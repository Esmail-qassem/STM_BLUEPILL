#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <stdint.h>
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "AFIO_interface.h"
#include "EXTI_interface.h"
#include "SysTick_interface.h"
#include "SPI_interface.h"
#include "UART_interface.h"

extern test;



void main(void)
{
	RCC_VidInit();
	SysTick_voidInit();
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOAEN);
	GPIO_SetPinConfig(GPIO_PORTA,PIN0,OUTPUT_50MHZ_PUSH_PULL);
	//SysTick_voidInit();


		
		
while(1)
	{
	SysTick_voidSetBusyWait(500);
	GPIO_SetPinValue(GPIO_PORTA,PIN0,1);
	SysTick_voidSetBusyWait(500);
	GPIO_SetPinValue(GPIO_PORTA,PIN0,0);

	


	}


}