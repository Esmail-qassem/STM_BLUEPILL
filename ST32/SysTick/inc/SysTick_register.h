/*
 * SysTick_register.h
 *
 *  Created on: Feb 19, 2024
 *      Author: s_a_a
 */

#ifndef SYSTICK_REGISTER_H_
#define SYSTICK_REGISTER_H_


#define SysTick_Add 0xE000E010

#define STK_CTRL_Reg        ((volatile STK_CTRL*)SysTick_Add)

#define STK_LOAD_Reg       *((volatile u32*)(SysTick_Add+0x04))
#define STK_VAL_Reg        *((volatile u32*)(SysTick_Add+0x08))
#define STK_CALIB_Reg      *((volatile u32*)(SysTick_Add+0x0C))
#endif /* INC_SYSTICK_REGISTER_H_ */
