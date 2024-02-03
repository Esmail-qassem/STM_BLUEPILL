/***********************************************************************/
/*Aauthor     : Esamil Qassem                                          */
/*Data        : 3 FEB 2024                                             */
/*SWC         : NVIC                                                   */
/*Version     : V.1                                                    */
/***********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "../inc/NVIC_interface.h"
#include "../inc/NVIC_private.h"
#include "../inc/NVIC_register.h"
#include "../inc/NVIC_config.h"


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




