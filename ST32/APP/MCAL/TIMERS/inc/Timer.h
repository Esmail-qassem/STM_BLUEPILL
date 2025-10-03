#ifndef TIMER14_H
#define TIMER14_H

#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"

/* === Common bit definitions === */
#define TIM_DIER_UIE   (1U << 0)   // Update interrupt enable
#define TIM_CR1_CEN    (1U << 0)   // Counter enable
#define TIM_SR_UIF     (1U << 0)   // Update interrupt flag

/* === Base addresses === */
#define TIMER1_BASE    0x40012C00
#define TIMER2_BASE    0x40000000
#define TIMER3_BASE    0x40000400
#define TIMER4_BASE    0x40000800

/* === Registers (offsets are same for all general/advanced timers) === */
#define TIM_CR1(base)   *((volatile uint16*)(base + 0x00))
#define TIM_DIER(base)  *((volatile uint16*)(base + 0x0C))
#define TIM_SR(base)    *((volatile uint16*)(base + 0x10))
#define TIM_PSC(base)   *((volatile uint16*)(base + 0x28))
#define TIM_ARR(base)   *((volatile uint16*)(base + 0x2C))

/* === IRQ numbers from stm32f103 vector table === */
#define TIM1_UP_IRQn   25
#define TIM2_IRQn      28
#define TIM3_IRQn      29
#define TIM4_IRQn      30

/* === Configurable values (1 ms @ 72 MHz APB1/APB2) === */
#define TIM1_PRESCALER   72-1
#define TIM1_RELOAD      1000-1
#define TIM2_PRESCALER   72-1
#define TIM2_RELOAD      1000-1
#define TIM3_PRESCALER   72-1
#define TIM3_RELOAD      1000-1
#define TIM4_PRESCALER   36-1
#define TIM4_RELOAD      1000-1

/* === Timer selection enum === */
typedef enum {
    TIMER1 = 1,
    TIMER2,
    TIMER3,
    TIMER4
} Timer_t;

/* === User callback type === */
typedef void (*TimerCallback_t)(void);

/* === Functions === */
void Timer_Init(Timer_t timer);
void Timer_Start(Timer_t timer);
void Timer_Stop(Timer_t timer);
void Timer_SetCallback(Timer_t timer, TimerCallback_t cb);

#endif
