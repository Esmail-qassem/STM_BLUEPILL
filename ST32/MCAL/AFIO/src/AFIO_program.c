#include "../../../Inc/STD_TYPES.h"
#include "../../../Inc/BIT_MATH.h"
#include "../inc/AFIO_interface.h"
#include "../inc/AFIO_private.h"
#include "../inc/AFIO_register.h"
#include "../inc/AFIO_config.h"

void AFIO_voidSetEXTIConfiguration(AFIO_Line_t Copy_u8Line,AFIO_EXTI_PORT Copy_u8Port_Mapp)
{

	if(Copy_u8Line<4)
	{
	AFIO_Reg->AFIO_EXTICR[0] &=~(0b1111<<(4*Copy_u8Line));
	AFIO_Reg->AFIO_EXTICR[0] |=(Copy_u8Port_Mapp<<(4*Copy_u8Line));

	}
	else if(Copy_u8Line<8)
	{
		Copy_u8Line-=4;
		AFIO_Reg->AFIO_EXTICR[1] &=~(0b1111<<(4*Copy_u8Line));
		AFIO_Reg->AFIO_EXTICR[1] |=(Copy_u8Port_Mapp<<(4*Copy_u8Line));

	}
	else if(Copy_u8Line<12)
	{
		Copy_u8Line-=8;
		AFIO_Reg->AFIO_EXTICR[2] &=~(0b1111<<(4*Copy_u8Line));
		AFIO_Reg->AFIO_EXTICR[2] |=(Copy_u8Port_Mapp<<(4*Copy_u8Line));
	}
	else if(Copy_u8Line<16)
	{
		Copy_u8Line-=12;
		AFIO_Reg->AFIO_EXTICR[3] &=~(0b1111<<(4*Copy_u8Line));
		AFIO_Reg->AFIO_EXTICR[3] |=(Copy_u8Port_Mapp<<(4*Copy_u8Line));

	}





}
