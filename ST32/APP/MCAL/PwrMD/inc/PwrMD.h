#ifndef PWRMD_H_
#define PwrMD_H_

#include "STD_TYPES.h"
#include "RCC_interface.h"

// Define Power Control Registers (Base Address: 0x40007000)
#define PWR_CR   *((volatile uint32*)0x40007000) // Power Control Register
#define PWR_CSR  *((volatile uint32*)0x40007004) // Power Control/Status Register

// System Control Block (SCB) Registers for Sleep Control
#define SCB_SCR  *((volatile uint32*)0xE000ED10) // System Control Register

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

// Function prototypes
void PWR_EnterSleepMode(void);
void PWR_EnterStopMode(void);
void PWR_EnterStandbyMode(void);
uint8 PWR_IsWakeupFromStandby(void);

#endif // PWRMD_H


