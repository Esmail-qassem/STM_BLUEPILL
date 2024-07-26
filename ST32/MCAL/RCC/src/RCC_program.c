/***********************************************************************/
/*Aauthor     : Esamil Qassem                                          */
/*Data        : 18 Nov 2023                                            */
/*SWC         : RCC                                                    */
/*Version     : V.1                                                    */
/***********************************************************************/
#include "../../../inc/STD_TYPES.h"
#include "../../../inc/BIT_MATH.h"
#include "../inc/RCC_interface.h"
#include "../inc/RCC_private.h"
#include "../inc/RCC_register.h"
#include "../inc/RCC_config.h"



void RCC_VidInit(void){

	u16 Counter=0;
/*******************************************************************/
#ifdef  HSI

	RCC_CR_Reg->HSION=RCC_Enable;
	while(RCC_CR_Reg->HSIRDY != RCC_Enable && Counter<CRC_TIME_OUT )
		{
			Counter++;
		}

#ifndef PLL
RCC_CFGR_Reg->SW=HSI_SELECT_CLOCK;
#endif


#endif
/*********************************************************************/
#ifdef HSE


#ifdef BYPASS_RCC

RCC_CR_Reg->HSEBYP=RCC_Enable;
#endif

#ifndef BYPASS_RCC

RCC_CR_Reg->HSEBYP=RCC_Disable;

#endif

RCC_CR_Reg->HSEON=RCC_Enable;
while(RCC_CR_Reg->HSERDY != RCC_Enable && Counter<CRC_TIME_OUT )
	{
		Counter++;
	}



#ifndef PLL
RCC_CFGR_Reg->SW=HSE_SELECT_CLOCK;
#endif


#endif

/************************************************************************/
#ifdef PLL

/*CHOOSING THE INPUT SIGNAL For the PLL*/
#ifdef HSI
/*HSI CLOCK DIVIDED BY 2*/
RCC_CFGR_Reg->PLLSRC=HSI_SELECT_CLOCK;

#endif

#ifdef HSE

RCC_CFGR_Reg->PLLSRC=HSE_SELECT_CLOCK;

RCC_CFGR_Reg->PLLXTRPE=HSE_SOURCE;

#endif

RCC_CFGR_Reg->PLLMUL=PLL_MULT_FACTOR;

RCC_CR_Reg->PLLON=RCC_Enable;
while(RCC_CR_Reg->PLLRDY != RCC_Enable && Counter<CRC_TIME_OUT )
{
	Counter++;
}


RCC_CFGR_Reg->SW=PLL_SELECT_CLOCK;


#endif
}

RCC_status RCC_voidEnablePeripheral(RCC_BUS_t Copy_Bus, Bus_EnPeripheral_t Copy_u8Peripheral){

	RCC_status Local_ErrorStatus=RCC_OK;
if(Copy_Bus>APB2_BUS || Copy_Bus<AHB_BUS)
{
	Local_ErrorStatus = RCC_BUS_ERR;

}
else if (Copy_u8Peripheral>30 )
{
	Local_ErrorStatus=RCC_PERIPHERAL_ERR;
}
else
{
	switch( Copy_Bus ){
				case AHB_BUS  : SET_BIT(RCC_AHBENR_REG,Copy_u8Peripheral); break;
				case APB1_BUS : SET_BIT(RCC_APB1ENR_REG,Copy_u8Peripheral); break;
				case APB2_BUS : SET_BIT(RCC_APB2ENR_REG,Copy_u8Peripheral); break;
			}
}
return Local_ErrorStatus;
}

RCC_status RCC_voidDisablePeripheral(RCC_BUS_t Copy_Bus,Bus_EnPeripheral_t Copy_u8Peripheral){
	RCC_status Local_ErrorStatus=RCC_OK;
if(Copy_Bus>APB2_BUS || Copy_Bus<AHB_BUS)
{
	Local_ErrorStatus = RCC_BUS_ERR;

}
else if (Copy_u8Peripheral>30)
{
	Local_ErrorStatus=RCC_PERIPHERAL_ERR;
}
else
{
	switch( Copy_Bus ){
				case AHB_BUS  : CLEAR_BIT(RCC_AHBENR_REG,Copy_u8Peripheral); break;
				case APB1_BUS : CLEAR_BIT(RCC_APB1ENR_REG,Copy_u8Peripheral); break;
				case APB2_BUS : CLEAR_BIT(RCC_APB2ENR_REG,Copy_u8Peripheral); break;
			}
}
return Local_ErrorStatus;
}

RCC_status RCC_voidResetPeripheral(RCC_BUS_t Copy_Bus,Bus_RestPeripheral_t Copy_u8Peripheral)
{
	RCC_status Local_ErrorStatus=RCC_OK;
	if(Copy_Bus>APB2_BUS || Copy_Bus<AHB_BUS)
	{
		Local_ErrorStatus = RCC_BUS_ERR;

	}
	else if (Copy_u8Peripheral>30)
	{
		Local_ErrorStatus=RCC_PERIPHERAL_ERR;
	}
	else
	{
		switch( Copy_Bus ){
					case APB1_BUS : SET_BIT(RCC_APB1RSTR_REG,Copy_u8Peripheral); break;
					case APB2_BUS : SET_BIT(RCC_APB2RSTR_REG,Copy_u8Peripheral); break;
					default: Local_ErrorStatus=RCC_BUS_ERR;
				}


	}
	return Local_ErrorStatus;
}
