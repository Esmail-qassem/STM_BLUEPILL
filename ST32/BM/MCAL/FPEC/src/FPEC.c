#include "FPEC.h"


void FPEC_voidEraseAppArea(void)
{
	uint8 i;
	
	for (i=10;i<64;i++)
	{
		FPEC_voidFlashPageErase(i);
	}
}

void FPEC_voidFlashPageErase(uint8 Copy_uint8PageNumber)
{
	/* Wait Busy Flag */
	while (GET_BIT(FPEC_Reg->SR,0) == 1);

	/* Check if FPEC is locked or not */
	if ( GET_BIT(FPEC_Reg->CR,7) == 1)
	{
		FPEC_Reg -> KEYR = 0x45670123;
		FPEC_Reg -> KEYR = 0xCDEF89AB;
	}
	
	/* Page Erase Operation */
	SET_BIT(FPEC_Reg->CR,1);

	/* Write Page address */
	FPEC_Reg->AR = (uint32)(Copy_uint8PageNumber * 1024) + 0x08000000 ;

	/* Start operation */
	SET_BIT(FPEC_Reg->CR,6);

	/* Wait Busy Flag */
	while (GET_BIT(FPEC_Reg->SR,0) == 1);

	/* EOP */
	SET_BIT(FPEC_Reg->SR,5);
	CLEAR_BIT(FPEC_Reg->CR,1);
}

void FPEC_voidFlashWrite(uint32 Copy_uint32Address, uint16* Copy_uint16Data, uint8 Copy_uint8Length)
{
	uint8 i;
	volatile uint16 Temp;

	while (GET_BIT(FPEC_Reg->SR,0) == 1);

	/* Check if FPEC is locked or not */
	if ( /* FPEC_CR->BitAccess.LOCK == 1 */ GET_BIT(FPEC_Reg->CR,7) == 1 )
	{
		FPEC_Reg -> KEYR = 0x45670123;
		FPEC_Reg -> KEYR = 0xCDEF89AB;
	}
	
	
	for (i = 0; i< Copy_uint8Length; i++)
	{
		/* Write Flash Programming */
		SET_BIT(FPEC_Reg->CR,0);

		/* Half word operation */

		Temp = Copy_uint16Data[i];
		*((volatile uint16*)Copy_uint32Address) = Copy_uint16Data[i];
		Copy_uint32Address += 2 ;

		/* Wait Busy Flag */
		while (GET_BIT(FPEC_Reg->SR,0) == 1);
	
		/* EOP */
		SET_BIT(FPEC_Reg->SR,5);
		CLEAR_BIT(FPEC_Reg->CR,0);
	}

}
