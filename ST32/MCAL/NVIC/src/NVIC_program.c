/***********************************************************************/
/*Aauthor     : Esamil Qassem                                          */
/*Data        : 3 FEB 2024                                             */
/*SWC         : NVIC                                                   */
/*Version     : V.1                                                    */
/***********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_register.h"
#include "NVIC_config.h"


NVIC_Status_t NVIC_EnableInterrupt(u8 Copy_u8Peripheral)
{
	NVIC_Status_t Local_ErrStatus=NVIC_OK;
if(Copy_u8Peripheral<32)
{
	NVIC_ISER0=(1<<Copy_u8Peripheral);
}
else if(Copy_u8Peripheral<60)
{

	Copy_u8Peripheral-=32;
	NVIC_ISER1=(1<<Copy_u8Peripheral);
}
else
{
	Local_ErrStatus=NVIC_NOK;
}

	return Local_ErrStatus;
}
NVIC_Status_t NVIC_DisableInterrupt(u8 Copy_u8Peripheral)
{
	NVIC_Status_t Local_ErrStatus=NVIC_OK;
if(Copy_u8Peripheral<32)
{
	NVIC_ICER0=(1<<Copy_u8Peripheral);
}
else if(Copy_u8Peripheral<60)
{

	Copy_u8Peripheral-=32;
	NVIC_ICER1=(1<<Copy_u8Peripheral);
}
else
{
	Local_ErrStatus=NVIC_NOK;
}

	return Local_ErrStatus;
}

NVIC_Status_t NVIC_SetPendingFlag(u8 Copy_u8Peripheral)
{
	NVIC_Status_t Local_ErrStatus=NVIC_OK;
if(Copy_u8Peripheral<32)
{
	NVIC_ISPR0=(1<<Copy_u8Peripheral);
}
else if(Copy_u8Peripheral<60)
{

	Copy_u8Peripheral-=32;
	NVIC_ISPR1=(1<<Copy_u8Peripheral);
}
else
{
	Local_ErrStatus=NVIC_NOK;
}

	return Local_ErrStatus;
}
NVIC_Status_t NVIC_ClearPendingFlag(u8 Copy_u8Peripheral)
{
	NVIC_Status_t Local_ErrStatus=NVIC_OK;
if(Copy_u8Peripheral<32)
{
	NVIC_ICPR0=(1<<Copy_u8Peripheral);
}
else if(Copy_u8Peripheral<60)
{

	Copy_u8Peripheral-=32;
	NVIC_ICPR1=(1<<Copy_u8Peripheral);
}
else
{
	Local_ErrStatus=NVIC_NOK;
}

	return Local_ErrStatus;
}

NVIC_Status_t NVIC_GetActiveInterrupt(u8 Copy_u8Peripheral,u8* Copy_pvPeripheral)
{
	NVIC_Status_t Local_ErrStatus=NVIC_OK;
if(Copy_u8Peripheral<32)
{
	*Copy_pvPeripheral=GET_BIT(NVIC_IABR0,Copy_u8Peripheral);

}
else if(Copy_u8Peripheral<60)
{

	Copy_u8Peripheral-=32;
	*Copy_pvPeripheral=GET_BIT(NVIC_IABR1,Copy_u8Peripheral);
}
else
{
	Local_ErrStatus=NVIC_NOK;
}
	return Local_ErrStatus;
}
void NVIC_SetPriority(s8 Copy_S8PriorityId,u8 Copy_u8GroupPriority,u8 Copy_u8SubPriority)
{
	/*u8 priority=Copy_u8SubPriority|(Copy_u8GroupPriority<<((GROUP-0x05FA0300)/256))  */
	NVIC_SCB_AIRCR_Reg->x=0x05FA0000|(priority_PreBuidConfig<<8);

	u8 Local_variable=priority_PreBuidConfig -3;

	if(Copy_S8PriorityId<0)
	{
		/*CORE PERIPHERAL*/

	}else if(Copy_S8PriorityId > -1)
	{
		*(NVIC_IPRn+Copy_S8PriorityId)=((Copy_u8SubPriority)|(Copy_u8GroupPriority<<(Local_variable)))<<4;
	}
}
