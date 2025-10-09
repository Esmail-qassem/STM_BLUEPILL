#ifndef OLED_H_
#define OLED_H_

#include "STD_TYPES.h"
#include "I2C.h"



#define SH1106_I2C_ADDR    0x3C   // 7-bit address
#define SH1106_WIDTH       128
#define SH1106_HEIGHT      64
#define SH1106_PAGES       (SH1106_HEIGHT / 8)

typedef enum {
    SH1106_COLOR_BLACK = 0x00,
    SH1106_COLOR_WHITE = 0x01
} SH1106_Color_t;

void SH1106_Init(I2C_Port_t PORT);
void SH1106_SendCommand(I2C_Port_t PORT,uint8 cmd);
void SH1106_SendData(I2C_Port_t PORT,uint8 data);
void SH1106_Clear(void);
void SH1106_DrawPixel(uint8 x, uint8 y, SH1106_Color_t color);
void SH1106_UpdateScreen(I2C_Port_t PORT);

void SH1106_DrawRect(uint8 x, uint8 y, uint8 w, uint8 h, SH1106_Color_t color);
void SH1106_FillRect(uint8 x, uint8 y, uint8 w, uint8 h, SH1106_Color_t color);
void SH1106_DrawBird(uint8 x, uint8 y);
#endif