#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "../inc/EXTI_interface.h"
#include "../inc/EXTI_private.h"
#include "../inc/EXTI_register.h"
#include "../inc/EXTI_config.h"


void EXTI_voidInterrupEnable(Line_t Copy_LineId)
{
	EXTI_Reg->IMR=1<<Copy_LineId;
}
void EXTI_voidInterrupDisable(Line_t Copy_LineId)
{
	EXTI_Reg->IMR&=~(1<<Copy_LineId);
}
EXTI_Err EXTI_EnableChangeLineMode(Line_t Copy_LineId,Exti_Mode_t Copy_Mode)
{
	EXTI_Err Local_ErrorStatus=EXTI_OK;

	switch(Copy_Mode)
	{
	case Falling_Edge:EXTI_Reg->RTSR=1<<Copy_LineId;break;
	case Rising_Edge: EXTI_Reg->FTSR= (1<<Copy_LineId) ;break;
	case On_Change: EXTI_Reg->RTSR=1<<Copy_LineId; EXTI_Reg->FTSR=1<<Copy_LineId  ;break;
    default:Local_ErrorStatus-EXTI_NOK;
	}
	return Local_ErrorStatus;
}
EXTI_Err EXTI_EDisableChangeLineMode(Line_t Copy_LineId,Exti_Mode_t Copy_Mode)
{
	EXTI_Err Local_ErrorStatus=EXTI_OK;

	switch(Copy_Mode)
	{
	case Falling_Edge:CLEAR_BIT(EXTI_Reg->RTSR,Copy_LineId);break;
	case Rising_Edge:CLEAR_BIT(EXTI_Reg->FTSR,Copy_LineId) ;break;
	case On_Change:CLEAR_BIT(EXTI_Reg->RTSR,Copy_LineId);CLEAR_BIT(EXTI_Reg->FTSR,Copy_LineId);break;
    default:Local_ErrorStatus-EXTI_NOK;
	}
	return Local_ErrorStatus;
}
void EXTI_voidSwTrigger(Line_t Copy_LineId)
{
EXTI_Reg->SWIER=1<<Copy_LineId;

}
