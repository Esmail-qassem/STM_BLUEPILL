#include "flappy_bird.h"

#define GRAVITY         1
#define JUMP_STRENGTH   3
#define GROUND_LEVEL    60   // Y max (bottom of screen)
#define CEILING_LEVEL   1    // Y min (top of screen)

#define top_pipe_height 20
#define pipe_width 5
#define gap_height 20
sint16  pipe_x =118;

static sint16 birdY = 30;
static sint16 velocity = 0;
uint8  Game_Started=0;
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
void DrawPipe(void)
{
    for (uint8 y = 0; y < top_pipe_height; y++)
    for (uint8 x = pipe_x; x < pipe_x + pipe_width; x++)
        SH1106_DrawPixel(x, y, SH1106_COLOR_WHITE);

for (uint8 y = top_pipe_height + gap_height; y < SH1106_HEIGHT; y++)
    for (uint8 x = pipe_x; x < pipe_x + pipe_width; x++)
        SH1106_DrawPixel(x, y, SH1106_COLOR_WHITE);

          pipe_x-=2; 
     if(pipe_x < 0)
     {
        pipe_x=118;
     }  


}
void DrawScore(uint8 score)
{
    
}

void Flappy_MainFunction(void)
{    // 1. Clear buffer first
    SH1106_Clear();
    // 2. Draw bird
    if(Game_Started == 1 )
    {
        DrawPipe();
        velocity += GRAVITY;
        birdY += velocity;
        if(birdY > GROUND_LEVEL )
        {
            birdY = GROUND_LEVEL;
        }
        else if (birdY < CEILING_LEVEL)
        {
            birdY = CEILING_LEVEL;
        }
         DrawBird(5, birdY);
    }
    else
    {
        DrawBird(10, 30);
    }
    swapBuffer();

    // 3. Update display
    SH1106_UpdateScreen(I2C1_PORT);
    // 4. Move bird
}


void Bird_Jump(void)
{
    if (PUSH_BUTTON == PRESSED)
    {
        Game_Started=1;
        velocity = -JUMP_STRENGTH; // Bird jumps upward
    }

}



