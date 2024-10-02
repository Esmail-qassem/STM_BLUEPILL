#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_register.h"
#include "EXTI_config.h"


void EXTI_voidInterrupEnable(Line_t Copy_LineId)
{
	EXTI_Reg->IMR|=(1<<Copy_LineId);
}
void EXTI_voidInterrupDisable(Line_t Copy_LineId)
{
	EXTI_Reg->IMR&=~(1<<Copy_LineId);
}
EXTI_Err EXTI_SetSignalLatch(Line_t Copy_LineId,Exti_Mode_t Copy_Mode,u8 Copy_u8Ability)
{
	EXTI_Err Local_ErrorStatus=EXTI_OK;
if(EXT_Enable==Copy_u8Ability)
{
	switch(Copy_Mode)
		{
		case Falling_Edge:EXTI_Reg->RTSR|=1<<Copy_LineId;break;
		case Rising_Edge: EXTI_Reg->FTSR|= (1<<Copy_LineId) ;break;
		case On_Change: EXTI_Reg->RTSR|=1<<Copy_LineId; EXTI_Reg->FTSR|=1<<Copy_LineId  ;break;
	    default:Local_ErrorStatus=EXTI_NOK;
		}
}
else if(EXT_Disable==Copy_u8Ability)
{
	switch(Copy_Mode)
		{
		case Falling_Edge:CLEAR_BIT(EXTI_Reg->RTSR,Copy_LineId);break;
		case Rising_Edge:CLEAR_BIT(EXTI_Reg->FTSR,Copy_LineId) ;break;
		case On_Change:CLEAR_BIT(EXTI_Reg->RTSR,Copy_LineId);CLEAR_BIT(EXTI_Reg->FTSR,Copy_LineId);break;
	    default:Local_ErrorStatus=EXTI_NOK;
		}
}

	return Local_ErrorStatus;
}
void EXTI_voidSwTrigger(Line_t Copy_LineId)
{
EXTI_Reg->SWIER|=1<<Copy_LineId;

}
static void EXTI_voidClearBending(Line_t Copy_LineId)
{
EXTI_Reg->PR|=1<<Copy_LineId;

}


Status_t EXT0_CallBack(void (*Copy_pvfunction)(void))
{
	Status_t Local_ErrorStatus=E_Not_Ok;
	if(NULL==Copy_pvfunction)
	{
		Local_ErrorStatus=E_Null_Pointer;
	}
	else
	{
	Local_ErrorStatus=E_Ok;
	Local0_PvFunction=Copy_pvfunction;
	}
	return Local_ErrorStatus;
}
Status_t EXT1_CallBack(void (*Copy_pvfunction)(void))
{
	Status_t Local_ErrorStatus=E_Not_Ok;
	if(NULL==Copy_pvfunction)
	{
		Local_ErrorStatus=E_Null_Pointer;
	}
	else
	{
	Local_ErrorStatus=E_Ok;
	Local1_PvFunction=Copy_pvfunction;
	}
	return Local_ErrorStatus;

}
Status_t EXT2_CallBack(void (*Copy_pvfunction)(void))
{
	Status_t Local_ErrorStatus=E_Not_Ok;
	if(NULL==Copy_pvfunction)
	{
		Local_ErrorStatus=E_Null_Pointer;
	}
	else
	{
	Local_ErrorStatus=E_Ok;
	Local2_PvFunction=Copy_pvfunction;
	}
	return Local_ErrorStatus;

}
Status_t EXT3_CallBack(void (*Copy_pvfunction)(void))
{
	Status_t Local_ErrorStatus=E_Not_Ok;
	if(NULL==Copy_pvfunction)
	{
		Local_ErrorStatus=E_Null_Pointer;
	}
	else
	{
	Local_ErrorStatus=E_Ok;
	Local3_PvFunction=Copy_pvfunction;
	}
	return Local_ErrorStatus;

}
Status_t EXT4_CallBack(void (*Copy_pvfunction)(void))
{
	Status_t Local_ErrorStatus=E_Not_Ok;
	if(NULL==Copy_pvfunction)
	{
		Local_ErrorStatus=E_Null_Pointer;
	}
	else
	{
	Local_ErrorStatus=E_Ok;
	Local4_PvFunction=Copy_pvfunction;
	}
	return Local_ErrorStatus;


}
void EXTI0_IRQHandler (void)
{
	Local0_PvFunction();
	EXTI_voidClearBending(Line0);
}
void EXTI1_IRQHandler (void)
{
	Local1_PvFunction();
	EXTI_voidClearBending(Line1);
}
void EXTI2_IRQHandler (void)
{
	Local2_PvFunction();
EXTI_voidClearBending(Line2);

}
void EXTI3_IRQHandler (void)
{
	Local3_PvFunction();
	EXTI_voidClearBending(Line3);
}
void EXTI4_IRQHandler (void)
{
	Local4_PvFunction();
	EXTI_voidClearBending(Line4);
}
