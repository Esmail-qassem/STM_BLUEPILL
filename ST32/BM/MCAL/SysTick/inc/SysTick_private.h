/*
 * SysTick_private.h
 *
 *  Created on: Feb 19, 2024
 *      Author: s_a_a
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

static void(*Local_PvFunction)(void)=NULL;

#define AHB_BY_8 0
#define AHB 1

#define MSTK_SINGLE_INTERVAL 0
#define MSTK_PERIOD_INTERVAL 1
typedef struct
{
	uint32 Sys_Enable    :1; /*Counter enable*/
	uint32 TICKINT   :1; /*SysTick exception request enable*/
	uint32 CLKSOURCE :1; /*Clock source selection*/
    uint32           :13;
    uint32 COUNTFLAG :1 ;
    uint32           :15;
}STK_CTRL;


#endif /* INC_SYSTICK_PRIVATE_H_ */
