/*
 * SysTick_interface.h
 *
 *  Created on: Feb 19, 2024
 *      Author: s_a_a
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SysTick_private.h"
#include "SysTick_register.h"
#include "SysTick_config.h"

void SysTick_voidInit(void);

/*Synchronous function*/
void SysTick_voidSetBusyWait(uint32 milliseconds);

/*ASynchronous function*/
/**************************************/
Status_t SysTick_voidSetIntervalSingle(uint32 Copy_uint32TicksCount,void (*Copy_pvfunction)(void));
Status_t SysTick_voidSetIntervalPeriodoc(uint32 Copy_uint32TicksCount,void (*Copy_pvfunction)(void));
/**************************************/
void SysTick_voidStopTimer(void);
uint32 SysTick_GetElapsedTime(void);
uint32 SysTick_GetRemaningTime(void);


#endif /* INC_SYSTICK_INTERFACE_H_ */
