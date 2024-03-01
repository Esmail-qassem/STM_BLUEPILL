/*
 * SysTick_private.h
 *
 *  Created on: Feb 19, 2024
 *      Author: s_a_a
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

static void(*Local_PvFunction)(void)=NULL;

enum Clock
{
	AHB_BY_8,
	AHB,
};


typedef struct
{
	u32 Sys_Enable    :1; /*Counter enable*/
	u32 TICKINT   :1; /*SysTick exception request enable*/
	u32 CLKSOURCE :1; /*Clock source selection*/
    u32           :13;
    u32 COUNTFLAG :1 ;
    u32           :15;
}STK_CTRL;


#endif /* INC_SYSTICK_PRIVATE_H_ */
