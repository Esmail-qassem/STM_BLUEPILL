#include "flappy_bird.h"

extern volatile uint8 PUSH_BUTTON;
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
#define GRAVITY         1
#define JUMP_STRENGTH   5
#define GROUND_LEVEL    60   // Y max (bottom of screen)
#define CEILING_LEVEL   1    // Y min (top of screen)
static sint16 birdY = 30;
static sint16 velocity = 0;

void Flappy_MainFunction(void)
{    // 1. Clear buffer first
    velocity += GRAVITY;
    birdY += velocity;
    SH1106_Clear();
    if(birdY > GROUND_LEVEL )
    {
        birdY = GROUND_LEVEL;
    }
    else if (birdY < CEILING_LEVEL)
    {
        birdY = CEILING_LEVEL;
    }
    // 2. Draw bird
    DrawBird(5, birdY);
    // 3. Update display
    SH1106_UpdateScreen(I2C1_PORT);
    // 4. Move bird
}


void Bird_Jump(void)
{
    if (PUSH_BUTTON == PRESSED)
    {
        velocity = -JUMP_STRENGTH; // Bird jumps upward
    }

}


