#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "UART_interface.h" 
#include "SysTick_interface.h"
#include "FPEC.h"
#include "Parse.h"


void init (void)
{
	RCC_VidInit();
	SysTick_voidInit();
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOBEN);
	RCC_voidEnablePeripheral(APB1_BUS,APB1_USART3EN);
	// RCC_voidEnablePeripheral(AHB_BUS,AHB_FLITFEN);
	GPIO_SetPinConfig(GPIO_PORTB,PIN10,OUTPUT_50MHZ_AF_PUSH);
	GPIO_SetPinConfig(GPIO_PORTB,PIN11,INPUT_FLOATING);
	UART_voidInit();
} 
void main(void)
{
	init();
	UART_uint8SendStringSynch(UART_Unit3,"\nbtld\n");
	FPEC_voidEraseAppArea();
	UART_uint8SendStringSynch(UART_Unit3,"\nApplication Erased\n");

	while(1)
	{
		uint8 Copy_p8ReceiveData=0;
		while(E_Ok==UART_uint8ReceiveCharSynch(UART_Unit3, &Copy_p8ReceiveData)) 
		{
			UART_RX_Handler(Copy_p8ReceiveData);
		}
		while(E_TIME_OUT==UART_uint8ReceiveCharSynch(UART_Unit3, &Copy_p8ReceiveData))
		{
			UART_uint8SendStringSynch(UART_Unit3,"IDLE\n");
		}
	}



}


