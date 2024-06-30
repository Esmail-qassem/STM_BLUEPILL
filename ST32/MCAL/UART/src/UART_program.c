

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "../inc/UART_interface.h"
#include "../inc/UART_register.h"
#include "../inc/UART_private.h"
#include "../inc/UART_config.h"

u8* Global_Recieve=NULL;
void UART_voidInit(void)
{

#ifdef UART1
	   /*Baud Rate Selection*/
	/*BAUD = F_CK/(16*UARTDIV)*/

u32 LOC_u64Mantissa_1 = ( F_CPU ) / ( 16 * USART1_BAUD_RATE ) ;
u32 LOC_u64Fraction_1 = ((LOC_u64Mantissa_1 % 100) * 16 + 7) / 16;

if (LOC_u64Fraction_1 > 15) {
    LOC_u64Mantissa_1 += 1;
    LOC_u64Fraction_1 = 0;
}

USART1_BRR_Reg->DIV_MANTISSA=LOC_u64Mantissa_1;
USART1_BRR_Reg->DIV_FACTOR=LOC_u64Fraction_1;

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
u32 LOC_u64Mantissa_2 = ( F_CPU ) / ( 16 * USART2_BAUD_RATE ) ;
u32 LOC_u64Fraction_2 = ((LOC_u64Mantissa_2 % 100) * 16 + 7) / 16;

if (LOC_u64Fraction_2 > 15) {
    LOC_u64Mantissa_2 += 1;
    LOC_u64Fraction_2 = 0;
}

USART2_BRR_Reg->DIV_MANTISSA=LOC_u64Mantissa_2;
USART2_BRR_Reg->DIV_FACTOR=LOC_u64Fraction_2;

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
u32 LOC_u64Mantissa_3 = ( F_CPU ) / ( 16 * USART3_BAUD_RATE ) ;
u32 LOC_u64Fraction_3 = ((LOC_u64Mantissa_3 % 100) * 16 + 7) / 16;

if (LOC_u64Fraction_3 > 15) {
    LOC_u64Mantissa_3 += 1;
    LOC_u64Fraction_3 = 0;
}

USART3_BRR_Reg->DIV_MANTISSA=LOC_u64Mantissa_3;
USART3_BRR_Reg->DIV_FACTOR=LOC_u64Fraction_3;

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
Status_t UART_u8SendCharASynch(UART_t HardWare_Unit,u8 Copy_u16Data,void(*Copy_pfISR)(void))
{
	Status_t ret =E_Not_Ok;
	if(NULL == Copy_pfISR)
	{
		ret =E_Null_Pointer;
	}
	else
	{
		ret =E_Ok;
		switch(HardWare_Unit)
		{
		case UART_Unit1 :
		          {

		          }
		case UART_Unit2 :
		          {

		          }
		case UART_Unit3 :
		          {

		          }
		}



	}
return ret;
}


void UART_u8SendCharSynch(UART_t HardWare_Unit,u8 Copy_u16Data)
{
switch(HardWare_Unit)
{
case UART_Unit1 :
          {
        		while(USART1_SR_Reg->TXE != 1);
        		USART1_DR_Reg=Copy_u16Data;
        		while(USART1_SR_Reg->TC != 1);
	            break;
          }
case UART_Unit2 :
          {
        		while(USART2_SR_Reg->TXE != 1);
        		USART2_DR_Reg=Copy_u16Data;
        		while(USART2_SR_Reg->TC != 1);
	            break;
          }
case UART_Unit3 :
          {
        		while(USART3_SR_Reg->TXE != 1);
        		USART3_DR_Reg=Copy_u16Data;
        		while(USART3_SR_Reg->TC != 1);
	            break;
          }
}


}



Status_t UART_u8ReceiveCharAsynch(UART_t HardWare_Unit,u8 *Copy_p8ReceiveData,void(*Copy_pfISR)(void))
{
	Status_t Local_Error=E_Ok;

	if(NULL == Copy_p8ReceiveData)
	{
		Local_Error=E_Null_Pointer;
	}
	else
	{
		if(UART_Unit1==HardWare_Unit)
		{
			 UART1_CallBack=Copy_pfISR;
			 Global_Recieve=Copy_p8ReceiveData;
			 USART1_CR1_Reg->PEIE=1;
			 USART1_CR1_Reg->RXNEIE=1;
		}
		else if(UART_Unit2==HardWare_Unit)
		{
			UART2_CallBack=Copy_pfISR;
			 Global_Recieve=Copy_p8ReceiveData;
			 USART2_CR1_Reg->PEIE=1;
			 USART2_CR1_Reg->RXNEIE=1;
		}
		else if (UART_Unit3==HardWare_Unit)
		{
			UART3_CallBack=Copy_pfISR;
			 Global_Recieve=Copy_p8ReceiveData;
			 USART3_CR1_Reg->PEIE=1;
			 USART3_CR1_Reg->RXNEIE=1;
		}
	}
	return Local_Error;
}





Status_t UART_u8ReceiveCharSynch(UART_t HardWare_Unit,u8 *Copy_p8ReceiveData)
{
	u32 Local_counter=NULL;
	Status_t Local_Error=E_Ok;

	USART1_SR_Reg->RXNE=Disable;
	if(NULL == Copy_p8ReceiveData)
	{
		Local_Error=E_Null_Pointer;

	}
	else
	{
		if(UART_Unit1==HardWare_Unit)
		{
			while(USART1_SR_Reg->RXNE ==0 && (Local_counter<TIME_OUT))
				{
					Local_counter++;
				}
				if(Local_counter==TIME_OUT)
				{
					Local_Error=E_TIME_OUT;
				}
				else
				{
					* Copy_p8ReceiveData=USART1_DR_Reg;
				}
		}
		else if(UART_Unit2==HardWare_Unit)
		{
			while(USART2_SR_Reg->RXNE ==0 && (Local_counter<TIME_OUT))
				{
					Local_counter++;
				}
				if(Local_counter==TIME_OUT)
				{
					Local_Error=E_TIME_OUT;
				}
				else
				{
					* Copy_p8ReceiveData=USART2_DR_Reg;
				}



		}else if (UART_Unit3==HardWare_Unit)
		{
			while(USART3_SR_Reg->RXNE ==0 && (Local_counter<TIME_OUT))
				{
					Local_counter++;
				}
				if(Local_counter==TIME_OUT)
				{
					Local_Error=E_TIME_OUT;
				}
				else
				{
					* Copy_p8ReceiveData=USART3_DR_Reg;
				}
		}
	}
	return Local_Error;
}

Status_t UART_u8SendStringSynch(UART_t HardWare_Unit,u8* Copy_p8Data)
{
	Status_t Local_ErrorStatus =E_Ok;
	u8 Local_Counter=NULL;
if(NULL ==Copy_p8Data )
{

	Local_ErrorStatus=E_Null_Pointer;


}else
{
		while(Copy_p8Data[Local_Counter]!='\0')
		{
			UART_u8SendCharSynch(HardWare_Unit,Copy_p8Data[Local_Counter]);
			Local_Counter++;
		}
}

return Local_ErrorStatus;
}




void UART_u8RecieveStringSynch(UART_t HardWare_Unit,u8*Copy_p8Data,u8 Copy_u8DataSize)
{
	    u8 receivedChar;
	    u8 stringIndex = NULL;

	    // Assuming USART1 is used for UART communication
	    while (stringIndex < (Copy_u8DataSize - 1))
	    {
	    	UART_u8ReceiveCharSynch(HardWare_Unit,&receivedChar);

	        // Check for the end of the string
	        if (receivedChar == '\n' || receivedChar == '\r') {
	        	Copy_p8Data[stringIndex] = '\0'; // Null-terminate the string
	            break;
	        }

	        // Store the received character in the string
	        Copy_p8Data[stringIndex++] = receivedChar;
	    }
	}




u8 UART_IsStringEqual(const u8 *str1, const u8 *str2, u8 length) {
    for (u8 i = 0; i < length; ++i) {
        if (str1[i] != str2[i]) {
            return 0;  // Not equal
        }

    }
    return 1;  // Equal

}
void USART1_IRQHandler (void)
{
	*Global_Recieve=USART1_DR_Reg;
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

