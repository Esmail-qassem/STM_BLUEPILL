#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RTOS.h"
#include "Timer.h"

task_type SysTask[TASK_NUMBER]={{0}};


void RTOS_voidStart(void)
{
	Timer_SetCallback(TIMER4,&RTOS_voidSchedular);
	Timer_Init(TIMER4);
	Timer_Start(TIMER4);
}

Task_status RTOS_voidCreateTask(uint8 Copy_priority,uint16 Copy_periodicity,void(*Copy_pvTaskFunc)(void))
{
	if (Copy_priority >= TASK_NUMBER) 
	{
    	return TASK_ERROR_INVALID_ID;
    }
    if (Copy_pvTaskFunc == NULL) 
	{
        return TASK_ERROR_ALREADY_NULL;
    }
	SysTask[Copy_priority].periodicity=Copy_periodicity;
	SysTask[Copy_priority].remaining_ticks= 1;
	SysTask[Copy_priority].TaskFunc=Copy_pvTaskFunc;
	SysTask[Copy_priority].state=READY;
	return TASK_OK;
}

void RTOS_voidSchedular(void)
{
    uint8 Local_u8TaskCounter;
    uint8 task_executed = 0;

    for (Local_u8TaskCounter = 0; Local_u8TaskCounter < TASK_NUMBER; Local_u8TaskCounter++)
    {
        if (SysTask[Local_u8TaskCounter].state == READY)
        {
            SysTask[Local_u8TaskCounter].remaining_ticks--;

            if (SysTask[Local_u8TaskCounter].remaining_ticks == 0)
            {
                SysTask[Local_u8TaskCounter].remaining_ticks = SysTask[Local_u8TaskCounter].periodicity;

                if (SysTask[Local_u8TaskCounter].TaskFunc != NULL)
                {
                    SysTask[Local_u8TaskCounter].TaskFunc();
                    task_executed = 1;
                }
            }
        }
    }

    if (!task_executed)
    {
	IdleTask();  // run only if nothing else executed
    }
}


Task_status RTOS_voidDeleteTask(uint8 Copy_priority)
{
	if (Copy_priority >= TASK_NUMBER) 
	{
    	return TASK_ERROR_INVALID_ID;
    }
    if (SysTask[Copy_priority].TaskFunc == NULL) 
	{
        return TASK_ERROR_ALREADY_NULL;
    }

    SysTask[Copy_priority].TaskFunc = NULL;
    SysTask[Copy_priority].state = REMOVED; 
    SysTask[Copy_priority].periodicity = 0;    
    SysTask[Copy_priority].remaining_ticks = 0;    

    return TASK_OK;
}
void RTOS_voidSuspendTask(uint8 Copy_priority)
{
	SysTask[Copy_priority].state=SUSPENDED;
}
void RTOS_voidResumeTask(uint8 Copy_priority)
{
	SysTask[Copy_priority].state=READY;
}
void RTOS_voidWaitEvent(uint8 Copy_priority)
{
	SysTask[Copy_priority].state=WAITING;
}