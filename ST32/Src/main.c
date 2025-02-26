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
int asd=2;
void main(void)
{
	asd=5;
	RCC_VidInit();
	UART_voidInit();
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOBEN);
	RCC_voidEnablePeripheral(APB1_BUS,APB1_USART3EN);
	
	GPIO_SetPinConfig(GPIO_PORTB,PIN5,OUTPUT_50MHZ_AF_PUSH);
	GPIO_SetPinConfig(GPIO_PORTB,PIN8,OUTPUT_50MHZ_AF_PUSH);


while(1)
	{
		
		GPIO_SetPinValue(GPIO_PORTB,PIN5,1);
		GPIO_SetPinValue(GPIO_PORTB,PIN8,1);
	}


}


