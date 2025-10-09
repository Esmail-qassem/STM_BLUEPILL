#include "flappy_bird.h"

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

void DrawBird(uint8 x,uint8 y)
{

    const uint8 birdBitmap[] = {
    0x00,
    0x38,
    0x7C,
    0xFC,
    0xFC,
    0x7C,
    0x38,
    0x00
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
void DrawPipe(uint8 x,uint8 y)
{

}
void DrawScore(uint8 score)
{
    
}
void Flappy_MainFunction(void)
{
    static uint8 x = 0;
    static uint8 dir = 1;   // 1 = right, 0 = left
    const uint8 y = 32;
    const uint8 speed = 5;  // pixels per frame (smooth motion)

    // 1. Clear buffer first
    SH1106_Clear();

    // 2. Draw bird
    DrawBird(x, y);

    // 3. Update display
    SH1106_UpdateScreen(I2C1_PORT);

    // 4. Move bird
    if(dir)
    {
        if(x+speed>=120)
        {
            dir=0;
            x=120;
            
        }
        else
        {
            x+=speed;
        }
    }
    else
    {
        if(x<=speed)
        {
            dir=1;
            x=0;

        }
        else
        {
            x-=speed;
        }

    }
 
}


