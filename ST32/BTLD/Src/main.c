#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "UART_interface.h" 
#include "FPEC.h"
#include "Parse.h"

#define SCB_AIRCR *((volatile uint32*)0xE000ED0C)

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
char hexLine[] = ":10010000214601360121470136007EFE09D2190140";

int counter=0;
void main(void)
{
	uint8 Local_uint8RecStatus;

	init();
	while(1)
	{
		SysTick_voidSetBusyWait(500);
		UART_uint8SendStringSynch(UART_Unit3,"btld\n");
		counter++;
		if(counter==15)
		{
         SCB_AIRCR= 0x5FA0004; /*generate soft reset*/
		}


	}



}


