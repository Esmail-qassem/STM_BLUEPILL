#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_register.h"
#include "AFIO_config.h"

void AFIO_voidSetEXTIConfiguration(AFIO_Line_t Copy_uint8Line,AFIO_EXTI_PORT Copy_uint8Port_Mapp)
{

	if(Copy_uint8Line<4)
	{
	AFIO_Reg->AFIO_EXTICR[0] &=~(0b1111<<(4*Copy_uint8Line));
	AFIO_Reg->AFIO_EXTICR[0] |=(Copy_uint8Port_Mapp<<(4*Copy_uint8Line));

	}
	else if(Copy_uint8Line<8)
	{
		Copy_uint8Line-=4;
		AFIO_Reg->AFIO_EXTICR[1] &=~(0b1111<<(4*Copy_uint8Line));
		AFIO_Reg->AFIO_EXTICR[1] |=(Copy_uint8Port_Mapp<<(4*Copy_uint8Line));

	}
	else if(Copy_uint8Line<12)
	{
		Copy_uint8Line-=8;
		AFIO_Reg->AFIO_EXTICR[2] &=~(0b1111<<(4*Copy_uint8Line));
		AFIO_Reg->AFIO_EXTICR[2] |=(Copy_uint8Port_Mapp<<(4*Copy_uint8Line));
	}
	else if(Copy_uint8Line<16)
	{
		Copy_uint8Line-=12;
		AFIO_Reg->AFIO_EXTICR[3] &=~(0b1111<<(4*Copy_uint8Line));
		AFIO_Reg->AFIO_EXTICR[3] |=(Copy_uint8Port_Mapp<<(4*Copy_uint8Line));

	}





}
