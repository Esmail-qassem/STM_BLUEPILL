#ifndef FLAPPY_BIRD_H_
#define FLAPPY_BIRD_H_
#include "STD_TYPES.h"
#include "OLED.h"

void DrawBird(uint8 x,uint8 y);
void DrawPipe(uint8 x,uint8 y);
void DrawScore(uint8 score);

void SH1106_DrawRect(uint8 x, uint8 y, uint8 w, uint8 h, SH1106_Color_t color);
void SH1106_FillRect(uint8 x, uint8 y, uint8 w, uint8 h, SH1106_Color_t color);

void Flappy_MainFunction(void);
#endif