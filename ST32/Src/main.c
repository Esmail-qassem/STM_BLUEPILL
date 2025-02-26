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
void main(void)
{
	RCC_VidInit();
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOBEN);
	RCC_voidEnablePeripheral(APB1_BUS,APB1_USART3EN);
	NVIC_EnableInterrupt(35);
	SysTick_voidInit();
	UART_voidInit();
	GPIO_SetPinConfig(GPIO_PORTB,PIN10,OUTPUT_50MHZ_AF_PUSH);
	GPIO_SetPinConfig(GPIO_PORTB,PIN11,INPUT_FLOATING);


while(1)
	{
		
		UART_u8SendStringSynch(UART_Unit3,"i'm app ");

		 SysTick_voidSetBusyWait(30);

	
	}


}


