#ifndef IWDG_H_
#define IWDG_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define IWDG_KR  *((volatile uint32*)0x40003000)
#define IWDG_PR  *((volatile uint32*)0x40003004)
#define IWDG_RLR *((volatile uint32*)0x40003008)
#define IWDG_SR  *((volatile uint32*)0x4000300C)



void IWDG_VoidInit(void);
void IWDG_VoidReload(void);







#endif