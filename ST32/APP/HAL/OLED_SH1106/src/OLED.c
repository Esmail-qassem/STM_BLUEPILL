#include "OLED.h"

static uint8 SH1106_Buffer[SH1106_WIDTH * SH1106_PAGES];
#define SH1106_COLUMN_OFFSET 2   // SH1106 has 132 columns, 128 visible

//-----------------------------------------------------//
//                Low-level Senders                    //
//-----------------------------------------------------//
void SH1106_SendCommand(I2C_Port_t PORT, uint8 cmd)
{
    uint8 data[2];
    data[0] = 0x00;   // Control byte: Co=0, D/C#=0 (Command)
    data[1] = cmd;
    I2C_MasterTransmit(PORT, SH1106_I2C_ADDR, data, 2, 0);
}

void SH1106_SendData(I2C_Port_t PORT, uint8 dataByte)
{
    uint8 data[2];
    data[0] = 0x40;   // Control byte: Co=0, D/C#=1 (Data)
    data[1] = dataByte;
    I2C_MasterTransmit(PORT, SH1106_I2C_ADDR, data, 2, 0);
}

//-----------------------------------------------------//
//                Initialization Sequence              //
//-----------------------------------------------------//
void SH1106_Init(I2C_Port_t PORT)
{
    // Power-up delay (~100 ms)
    for (volatile uint32 i = 0; i < 100000; i++);

    // Recommended SH1106 initialization sequence
    SH1106_SendCommand(PORT, 0xAE); // Display OFF
    SH1106_SendCommand(PORT, 0xD5); // Set display clock divide ratio
    SH1106_SendCommand(PORT, 0x80);
    SH1106_SendCommand(PORT, 0xA8); // Multiplex ratio
    SH1106_SendCommand(PORT, 0x3F);
    SH1106_SendCommand(PORT, 0xD3); // Display offset
    SH1106_SendCommand(PORT, 0x00);
    SH1106_SendCommand(PORT, 0x40); // Start line = 0
    SH1106_SendCommand(PORT, 0xAD); // DC-DC control mode set
    SH1106_SendCommand(PORT, 0x8B);
    SH1106_SendCommand(PORT, 0xA1); // Segment remap
    SH1106_SendCommand(PORT, 0xC8); // COM scan direction
    SH1106_SendCommand(PORT, 0xDA); // COM pins config
    SH1106_SendCommand(PORT, 0x12);
    SH1106_SendCommand(PORT, 0x81); // Contrast
    SH1106_SendCommand(PORT, 0x80);
    SH1106_SendCommand(PORT, 0xD9); // Pre-charge period
    SH1106_SendCommand(PORT, 0x1F);
    SH1106_SendCommand(PORT, 0xDB); // VCOMH deselect level
    SH1106_SendCommand(PORT, 0x40);
    SH1106_SendCommand(PORT, 0xA4); // Resume to RAM content
    SH1106_SendCommand(PORT, 0xA6); // Normal display

    SH1106_Clear();
    SH1106_UpdateScreen(PORT);

    SH1106_SendCommand(PORT, 0xAF); // Display ON
}

//-----------------------------------------------------//
//                Framebuffer Operations               //
//-----------------------------------------------------//
void SH1106_Clear(void)
{
    for (uint16 i = 0; i < sizeof(SH1106_Buffer); i++)
        SH1106_Buffer[i] = 0x00;
}

void SH1106_DrawPixel(uint8 x, uint8 y, SH1106_Color_t color)
{
    if (x >= SH1106_WIDTH || y >= SH1106_HEIGHT)
        return;

    uint16 index = x + (y / 8) * SH1106_WIDTH;

    if (color == SH1106_COLOR_WHITE)
        SH1106_Buffer[index] |= (1 << (y % 8));
    else
        SH1106_Buffer[index] &= ~(1 << (y % 8));
}

void SH1106_UpdateScreen(I2C_Port_t PORT)
{
    for (uint8 page = 0; page < SH1106_PAGES; page++)
    {
        // Set page address and column start
        SH1106_SendCommand(PORT, 0xB0 + page);                  // Page address
        SH1106_SendCommand(PORT, 0x00 + (SH1106_COLUMN_OFFSET & 0x0F)); // Lower column
        SH1106_SendCommand(PORT, 0x10 + ((SH1106_COLUMN_OFFSET >> 4) & 0x0F)); // Higher column

        // Prepare data buffer (1 control byte + page data)
        uint8 data[1 + SH1106_WIDTH];
        data[0] = 0x40;  // Control byte for data

        for (uint8 col = 0; col < SH1106_WIDTH; col++)
        {
            data[1 + col] = SH1106_Buffer[page * SH1106_WIDTH + col];
        }

        // Send entire page at once
        I2C_MasterTransmit(PORT, SH1106_I2C_ADDR, data, sizeof(data), 0);
    }
}


void SH1106_DrawRect(uint8 x, uint8 y, uint8 w, uint8 h, SH1106_Color_t color)
{
    for (uint8 i = 0; i < w; i++) {
        SH1106_DrawPixel(x + i, y, color);
        SH1106_DrawPixel(x + i, y + h - 1, color);
    }
    for (uint8 j = 0; j < h; j++) {
        SH1106_DrawPixel(x, y + j, color);
        SH1106_DrawPixel(x + w - 1, y + j, color);
    }
}

void SH1106_FillRect(uint8 x, uint8 y, uint8 w, uint8 h, SH1106_Color_t color)
{
    for (uint8 i = 0; i < w; i++) {
        for (uint8 j = 0; j < h; j++) {
            SH1106_DrawPixel(x + i, y + j, color);
        }
    }
}

void SH1106_DrawBird(uint8 x, uint8 y)
{
    // Small 8x8 pixel bird
    const uint8 birdBitmap[8] = {
        0b00011000,
        0b00111100,
        0b01111110,
        0b11111111,
        0b11111111,
        0b01111110,
        0b00111100,
        0b00011000
    };

    for (uint8 row = 0; row < 8; row++) {
        for (uint8 col = 0; col < 8; col++) {
            if (birdBitmap[row] & (1 << (7 - col)))
                SH1106_DrawPixel(x + col, y + row, SH1106_COLOR_WHITE);
            else
                SH1106_DrawPixel(x + col, y + row, SH1106_COLOR_BLACK);
        }
    }
}