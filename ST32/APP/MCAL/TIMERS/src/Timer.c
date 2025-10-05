#include "Timer.h"

/* === Static callbacks and tick counters === */
static TimerCallback_t tim1_callback = 0;
static TimerCallback_t tim2_callback = 0;
static TimerCallback_t tim3_callback = 0;
static TimerCallback_t tim4_callback = 0;

volatile uint32 total_ticks = 0;

volatile NVIC_Status_t nvic_stat= NVIC_NOK;
void Timer_Init(Timer_t timer)
{
    switch(timer)
    {
        case TIMER1:
            RCC_voidEnablePeripheral(APB2_BUS, APB2_TIM1EN); // TIM1 on APB2
            TIM_PSC(TIMER1_BASE)  = TIM1_PRESCALER;
            TIM_ARR(TIMER1_BASE)  = TIM1_RELOAD;
            TIM_DIER(TIMER1_BASE) |= TIM_DIER_UIE;
            nvic_stat=NVIC_EnableInterrupt(TIM1_UP_IRQn);
            break;

        case TIMER2:
            RCC_voidEnablePeripheral(APB1_BUS, APB1_TIM2EN); // TIM2 on APB1
            TIM_PSC(TIMER2_BASE)  = TIM2_PRESCALER;
            TIM_ARR(TIMER2_BASE)  = TIM2_RELOAD;
            TIM_DIER(TIMER2_BASE) |= TIM_DIER_UIE;
           nvic_stat= NVIC_EnableInterrupt(TIM2_IRQn);

            break;

        case TIMER3:
            RCC_voidEnablePeripheral(APB1_BUS, APB1_TIM3EN);
            TIM_PSC(TIMER3_BASE)  = TIM3_PRESCALER;
            TIM_ARR(TIMER3_BASE)  = TIM3_RELOAD;
            TIM_DIER(TIMER3_BASE) |= TIM_DIER_UIE;
           nvic_stat= NVIC_EnableInterrupt(TIM3_IRQn);

            break;

        case TIMER4:
            RCC_voidEnablePeripheral(APB1_BUS, APB1_TIM4EN);
            TIM_PSC(TIMER4_BASE)  = TIM4_PRESCALER;
            TIM_ARR(TIMER4_BASE)  = TIM4_RELOAD;
            TIM_DIER(TIMER4_BASE) |= TIM_DIER_UIE;
            nvic_stat=NVIC_EnableInterrupt(TIM4_IRQn);
           
            break;
    }
}

void Timer_Start(Timer_t timer)
{
    switch(timer) {
        case TIMER1: TIM_CR1(TIMER1_BASE) |= TIM_CR1_CEN; break;
        case TIMER2: TIM_CR1(TIMER2_BASE) |= TIM_CR1_CEN; break;
        case TIMER3: TIM_CR1(TIMER3_BASE) |= TIM_CR1_CEN; break;
        case TIMER4: TIM_CR1(TIMER4_BASE) |= TIM_CR1_CEN; break;
    }
}

void Timer_Stop(Timer_t timer)
{
    switch(timer) {
        case TIMER1: TIM_CR1(TIMER1_BASE) &= ~TIM_CR1_CEN; break;
        case TIMER2: TIM_CR1(TIMER2_BASE) &= ~TIM_CR1_CEN; break;
        case TIMER3: TIM_CR1(TIMER3_BASE) &= ~TIM_CR1_CEN; break;
        case TIMER4: TIM_CR1(TIMER4_BASE) &= ~TIM_CR1_CEN; break;
    }
}

void Timer_SetCallback(Timer_t timer, TimerCallback_t cb)
{
    switch(timer) {
        case TIMER1: tim1_callback = cb; break;
        case TIMER2: tim2_callback = cb; break;
        case TIMER3: tim3_callback = cb; break;
        case TIMER4: tim4_callback = cb; break;
    }
}

/* === IRQ Handlers === */
void TIM1_UP_IRQHandler(void)
{
    if (TIM_SR(TIMER1_BASE) & TIM_SR_UIF) {
        TIM_SR(TIMER1_BASE) &= ~TIM_SR_UIF;
        if (tim1_callback) tim1_callback();
    }
}

void TIM2_IRQHandler(void)
{
    if (TIM_SR(TIMER2_BASE) & TIM_SR_UIF) {
        TIM_SR(TIMER2_BASE) &= ~TIM_SR_UIF;
        
        if (tim2_callback) tim2_callback();
    }
}

void TIM3_IRQHandler(void)
{
    if (TIM_SR(TIMER3_BASE) & TIM_SR_UIF) {
        TIM_SR(TIMER3_BASE) &= ~TIM_SR_UIF;
        
        if (tim3_callback) tim3_callback();
    }
}

void TIM4_IRQHandler(void)
{
    if (TIM_SR(TIMER4_BASE) & TIM_SR_UIF) {
        TIM_SR(TIMER4_BASE) &= ~TIM_SR_UIF;
        total_ticks++;
        if (tim4_callback) tim4_callback();
    }
}
