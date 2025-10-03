

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_interface.h"
#include "UART_register.h"
#include "UART_private.h"
#include "UART_config.h"
void UART_voidSendNumber(UART_t HardWare_Unit,sint32 Copy_sint32Number)
{
	if(Copy_sint32Number<0)
	{
		UART_uint8SendCharSynch(HardWare_Unit,'-');
		Copy_sint32Number= -Copy_sint32Number;
	}
	if(Copy_sint32Number==0)
	{
 UART_uint8SendCharSynch(HardWare_Unit,'0');
		return;
	}
uint8 NUM[10];
uint8 Local_uint8Counter=0;
while(Copy_sint32Number>0)
{
	NUM[Local_uint8Counter++]=(Copy_sint32Number%10)+'0';
	Copy_sint32Number/=10;
}
/*reverse*/
for(uint8 i=Local_uint8Counter;i>0;i--)
{
    UART_uint8SendCharSynch(HardWare_Unit,(NUM[i-1]));
    ;
}
}


void UART_voidInit(void)
{

#ifdef UART1
	   /*Baud Rate Selection*/
	/*BAUD = F_CK/(16*UARTDIV)*/

uint32 USARTDIV1_x100 = (F_CPU * 100) / (16 * USART1_BAUD_RATE);

// Mantissa = integer part
uint32 Mantissa1 = USARTDIV1_x100 / 100;

// Decimal part = USARTDIV1_x100 - Mantissa1*100
uint32 Decimal1_x100 = USARTDIV1_x100 - (Mantissa1 * 100);

// Fraction = round(Decimal1_x100 * 16 / 100)
uint32 Fraction1 = (Decimal1_x100 * 16 + 50) / 100;

if (Fraction1 > 15) {
    Mantissa1 += 1;
    Fraction1 = 0;
}

USART1_BRR_Reg->DIV_MANTISSA = Mantissa1;
USART1_BRR_Reg->DIV_FACTOR   = Fraction1;


/*Word Length*/

USART1_CR1_Reg->M=UART1_WORD_SIZE;

/*Parity Control*/
#if   UART1_PARITY == UART1_PAR_DISABLE
     USART1_CR1_Reg->PCE=0;

#elif UART1_PARITY == UART1_PAR_EVEN
     USART1_CR1_Reg->PCE=1;
     USART1_CR1_Reg->PS=1;
#elif UART1_PARITY == UART1_PAR_ODD
     USART1_CR1_Reg->PCE=1;
     USART1_CR1_Reg->PS=0;
#else
#error "UART1 PARITY ERROR"
#endif


#if  USART1_INTERRUPT == INT_DISABLE

     USART1_CR1_Reg->TXEIE=0;
     USART1_CR1_Reg->TCIE=0;
     USART1_CR1_Reg->RXNEIE=0;

		#elif USART1_INTERRUPT == TXE_INT_ENABLE

     USART1_CR1_Reg->TXEIE=1;
     USART1_CR1_Reg->PEIE=1;

		#elif USART1_INTERRUPT == TCE_INT_ENABLE
     USART1_CR1_Reg->PEIE=1;
     USART1_CR1_Reg->TCIE=1;



		#endif

     /*Stop Bit */
USART1_CR2_Reg->STOP=UART1_Stop_Bit_Condition;
/*UART1 RECEIVE AND TRANSMITE ENABLE*/
USART1_CR1_Reg->TE=1;
USART1_CR1_Reg->RE=1;

/*UART1_ENABLE*/
USART1_CR1_Reg->UE=1;

#endif

#ifdef UART2
/*Baud Rate Selection*/
/*BAUD = F_CK/(16*UARTDIV)*/
uint32 USARTDIV2_x100 = (F_CPU * 100) / (16 * USART2_BAUD_RATE);

uint32 Mantissa2 = USARTDIV2_x100 / 100;
uint32 Decimal2_x100 = USARTDIV2_x100 - (Mantissa2 * 100);
uint32 Fraction2 = (Decimal2_x100 * 16 + 50) / 100;

if (Fraction2 > 15) {
    Mantissa2 += 1;
    Fraction2 = 0;
}

USART2_BRR_Reg->DIV_MANTISSA = Mantissa2;
USART2_BRR_Reg->DIV_FACTOR   = Fraction2;


/*Word Length*/

USART2_CR1_Reg->M=UART2_WORD_SIZE;

/*Parity Control*/
#if   UART2_PARITY == UART2_PAR_DISABLE
     USART2_CR1_Reg->PCE=0;

#elif UART2_PARITY == UART2_PAR_EVEN
     USART2_CR1_Reg->PCE=1;
     USART2_CR1_Reg->PS=1;
#elif UART2_PARITY == UART2_PAR_ODD
     USART2_CR1_Reg->PCE=1;
     USART2_CR1_Reg->PS=0;
#else
#error "UART2 PARITY ERROR"
#endif



#if  USART2_INTERRUPT == INT_DISABLE

     USART2_CR1_Reg->TXEIE=0;
     USART2_CR1_Reg->TCIE=0;
     USART2_CR1_Reg->RXNEIE=0;

		#elif USART2_INTERRUPT == TXE_INT_ENABLE
     USART2_CR1_Reg->PEIE=1;
     USART2_CR1_Reg->TXEIE=1;

		#elif USART2_INTERRUPT == TCE_INT_ENABLE
     USART2_CR1_Reg->PEIE=1;
     USART2_CR1_Reg->TCIE=1;




		#endif

     /*Stop Bit */
 USART2_CR2_Reg->STOP=UART2_Stop_Bit_Condition;
 /*UART2 RECEIVE AND TRANSMITE ENABLE*/
 USART2_CR1_Reg->TE=1;
 USART2_CR1_Reg->RE=1;

 /*UART2_ENABLE*/
 USART2_CR1_Reg->UE=1;



#endif



#ifdef UART3
/*Baud Rate Selection*/
/*BAUD = F_CK/(16*UARTDIV)*/
uint32 USARTDIV3_x100 = (F_CPU * 100) / (16 * USART3_BAUD_RATE);

uint32 Mantissa3 = USARTDIV3_x100 / 100;
uint32 Decimal3_x100 = USARTDIV3_x100 - (Mantissa3 * 100);
uint32 Fraction3 = (Decimal3_x100 * 16 + 50) / 100;

if (Fraction3 > 15) {
    Mantissa3 += 1;
    Fraction3 = 0;
}

USART3_BRR_Reg->DIV_MANTISSA = Mantissa3;
USART3_BRR_Reg->DIV_FACTOR   = Fraction3;

/*Word Length*/

USART3_CR1_Reg->M=UART3_WORD_SIZE;

/*Parity Control*/
#if   UART3_PARITY == UART3_PAR_DISABLE
     USART3_CR1_Reg->PCE=0;

#elif UART3_PARITY == UART3_PAR_EVEN
     USART3_CR1_Reg->PCE=1;
     USART3_CR1_Reg->PS=1;
#elif UART3_PARITY == UART3_PAR_ODD
     USART3_CR1_Reg->PCE=1;
     USART3_CR1_Reg->PS=0;
#else
#error "UART3 PARITY ERROR"
#endif



#if  USART3_INTERRUPT == INT_DISABLE

     USART3_CR1_Reg->TXEIE=0;
     USART3_CR1_Reg->TCIE=0;


		#elif USART3_INTERRUPT == TXE_INT_ENABLE
     USART3_CR1_Reg->PEIE=1;
     USART3_CR1_Reg->TXEIE=1;

		#elif USART3_INTERRUPT == TCE_INT_ENABLE
     USART3_CR1_Reg->PEIE=1;
     USART3_CR1_Reg->TCIE=1;




		#endif

     /*Stop Bit */
 USART3_CR2_Reg->STOP=UART3_Stop_Bit_Condition;
 /*UART2 RECEIVE AND TRANSMITE ENABLE*/
 USART3_CR1_Reg->TE=1;
 USART3_CR1_Reg->RE=1;

 /*UART2_ENABLE*/
 USART3_CR1_Reg->UE=1;



#endif

}



void UART_uint8SendCharSynch(UART_t HardWare_Unit,uint8 Copy_uint16Data)
{
switch(HardWare_Unit)
{
case UART_Unit1 :
          {
        		while(USART1_SR_Reg->TXE != 1);
        		USART1_DR_Reg=Copy_uint16Data;
        		while(USART1_SR_Reg->TC != 1);
	            break;
          }
case UART_Unit2 :
          {
        		while(USART2_SR_Reg->TXE != 1);
        		USART2_DR_Reg=Copy_uint16Data;
        		while(USART2_SR_Reg->TC != 1);
	            break;
          }
case UART_Unit3 :
          {
        		while(USART3_SR_Reg->TXE != 1);
        		USART3_DR_Reg=Copy_uint16Data;
        		while(USART3_SR_Reg->TC != 1);
	            break;
          }
}


}

Status_t UART_uint8ReceiveCharSynch(UART_t HardWare_Unit, uint8 *Copy_p8ReceiveData)
{
    uint32 Local_counter = 0;  // Initialize properly
    Status_t Local_Error = E_Ok;

    if (NULL == Copy_p8ReceiveData)
    {
        Local_Error= E_Null_Pointer;
    }

    if (UART_Unit1 == HardWare_Unit)
    {
        while ((USART1_SR_Reg->RXNE == 0) && (Local_counter < TIME_OUT))
        {
            Local_counter++;
        }

        if (Local_counter == TIME_OUT)
        {
            Local_Error = E_TIME_OUT;
        }
        else
        {
            *Copy_p8ReceiveData = USART1_DR_Reg;
        }
    }
    else if (UART_Unit2 == HardWare_Unit)
    {
        while ((USART2_SR_Reg->RXNE == 0) && (Local_counter < TIME_OUT))
        {
            Local_counter++;
        }

        if (Local_counter == TIME_OUT)
        {
            Local_Error = E_TIME_OUT;  // Fix missing timeout assignment
        }
        else
        {
            *Copy_p8ReceiveData = USART2_DR_Reg;
        }
    }
    else if (UART_Unit3 == HardWare_Unit)
    {
        while ((USART3_SR_Reg->RXNE == 0) && (Local_counter < TIME_OUT))
        {
            Local_counter++;
        }

        if (Local_counter == TIME_OUT)
        {
            Local_Error = E_TIME_OUT;
        }
        else
        {
            *Copy_p8ReceiveData = USART3_DR_Reg;
        }
    }

    return Local_Error;
}

Status_t UART_uint8SendStringSynch(UART_t HardWare_Unit,uint8* Copy_p8Data)
{
	Status_t Local_ErrorStatus =E_Ok;
	uint8 Local_Counter=NULL;
if(NULL ==Copy_p8Data )
{

	Local_ErrorStatus=E_Null_Pointer;


}else
{
		while(Copy_p8Data[Local_Counter]!='\0')
		{
			UART_uint8SendCharSynch(HardWare_Unit,Copy_p8Data[Local_Counter]);
			Local_Counter++;
		}
}

return Local_ErrorStatus;
}




void UART_uint8RecieveStringSynch(UART_t HardWare_Unit,uint8*Copy_p8Data,uint8 Copy_uint8DataSize)
{
	    uint8 receivedChar;
	    uint8 stringIndex = NULL;

	    // Assuming USART1 is used for UART communication
	    while (stringIndex < (Copy_uint8DataSize - 1))
	    {
	    	UART_uint8ReceiveCharSynch(HardWare_Unit,&receivedChar);

	        // Check for the end of the string
	        if (receivedChar == '\n' || receivedChar == '\r') {
	        	Copy_p8Data[stringIndex] = '\0'; // Null-terminate the string
	            break;
	        }

	        // Store the received character in the string
	        Copy_p8Data[stringIndex++] = receivedChar;
	    }
	}




uint8 UART_IsStringEqual(const uint8 *str1, const uint8 *str2, uint8 length) {
    for (uint8 i = 0; i < length; ++i) {
        if (str1[i] != str2[i]) {
            return 0;  // Not equal
        }

    }
    return 1;  // Equal

}
void USART1_IRQHandler (void)
{
	UART1_CallBack();
}
void USART2_IRQHandler (void)
{
	UART2_CallBack();
}
void USART3_IRQHandler (void)
{
	UART3_CallBack();
}

