#ifndef PWRMD_H_
#define PwrMD_H_

#include "STD_TYPES.h"

// Function prototypes
void PWR_EnterSleepMode(void);
void PWR_EnterStopMode(void);
void PWR_EnterStandbyMode(void);
u8 PWR_IsWakeupFromStandby(void);

#endif // PWRMD_H


