#include"PwrMD.h"

/**
 * @brief Enter Sleep Mode (CPU Halt, Peripherals Active)
 */
void PWR_EnterSleepMode(void) {
    SCB_SCR &= ~SCB_SCR_SLEEPDEEP; // Clear SLEEPDEEP bit (select Sleep mode)
    __WFI(); // Wait for Interrupt (CPU stops until an interrupt occurs)
}

/**
 * @brief Enter Stop Mode (Low Power, RAM Retained, Wakes on Interrupt)
 */
void PWR_EnterStopMode(void) {
    RCC_APB1ENR_REG |= (1 << 28); // Enable Power Control (PWR) clock
    PWR_CR |= PWR_CR_LPDS; // Low-Power Deep Sleep (LPDS)
    SCB_SCR |= SCB_SCR_SLEEPDEEP; // Set SLEEPDEEP bit
    __WFI(); // Enter Stop Mode, wakes on interrupt
}

/**
 * @brief Enter Standby Mode (Lowest Power, Wakes on Reset or RTC)
 */
void PWR_EnterStandbyMode(void) {
    RCC_APB1ENR_REG |= (1 << 28); // Enable PWR clock
    PWR_CR |= PWR_CR_CWUF; // Clear Wakeup Flag
    PWR_CR |= PWR_CR_PDDS; // Enable Power Down Deep Sleep (PDDS)
    SCB_SCR |= SCB_SCR_SLEEPDEEP; // Set SLEEPDEEP bit
    __WFI(); // Enter Standby Mode
}

/**
 * @brief Check if the MCU woke up from Standby Mode
 * @return 1 if wakeup flag is set, 0 otherwise
 */
uint8 PWR_IsWakeupFromStandby(void) {
    return (PWR_CSR & PWR_CSR_WUF) ? 1 : 0;
}
