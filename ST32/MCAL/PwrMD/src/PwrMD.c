#include"PwrMD.h"
#include "RCC_interface.h"

// Define Power Control Registers (Base Address: 0x40007000)
#define PWR_CR   *((volatile u32*)0x40007000) // Power Control Register
#define PWR_CSR  *((volatile u32*)0x40007004) // Power Control/Status Register

// System Control Block (SCB) Registers for Sleep Control
#define SCB_SCR  *((volatile u32*)0xE000ED10) // System Control Register

// Bit definitions for PWR_CR
#define PWR_CR_LPDS   (1 << 0) // Low-Power Deep Sleep
#define PWR_CR_PDDS   (1 << 1) // Power Down Deep Sleep (Standby Mode)
#define PWR_CR_CWUF   (1 << 2) // Clear Wakeup Flag
#define PWR_CR_EWUP   (1 << 8) // Enable Wakeup Pin

// Bit definitions for PWR_CSR
#define PWR_CSR_WUF   (1 << 0) // Wakeup Flag

// Bit definitions for SCB_SCR
#define SCB_SCR_SLEEPDEEP (1 << 2) // Sleep Deep Bit

// __WFI() Assembly Instruction (Wait for Interrupt)
#define __WFI() __asm volatile ("wfi")

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
u8 PWR_IsWakeupFromStandby(void) {
    return (PWR_CSR & PWR_CSR_WUF) ? 1 : 0;
}
