/*
 * SysTick_interface.h
 *
 *  Created on: Feb 19, 2024
 *      Author: s_a_a
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_


void SysTick_voidInit(void);

/*Synchronous function*/
void SysTick_voidSetBusyWait(u32 Copy_u32TicksCount);

/*ASynchronous function*/
/**************************************/
Status_t SysTick_voidSetIntervalSingle(u32 Copy_u32TicksCount,void (*Copy_pvfunction)(void));
Status_t SysTick_voidSetIntervalPeriodoc(u32 Copy_u32TicksCount,void (*Copy_pvfunction)(void));
/**************************************/
void SysTick_voidStopTimer(void);
u32 SysTick_GetElapsedTime(void);
u32 SysTick_GetRemaningTime(void);


#endif /* INC_SYSTICK_INTERFACE_H_ */
