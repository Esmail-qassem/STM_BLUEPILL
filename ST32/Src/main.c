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
	RCC_voidEnablePeripheral(APB2_BUS,APB2_USART1EN);
	RCC_voidEnablePeripheral(APB1_BUS,APB1_USART2EN);
	RCC_voidEnablePeripheral(APB1_BUS,APB1_USART3EN);
	NVIC_EnableInterrupt(35);
	SysTick_voidInit();
	UART_voidInit();
	GPIO_SetPinConfig(GPIO_PORTB,PIN8,OUTPUT_50MHZ_PUSH_PULL);
	GPIO_SetPinConfig(GPIO_PORTB,PIN5,OUTPUT_50MHZ_PUSH_PULL);
	// GPIO_SetPinConfig(GPIO_PORTA,PIN2,OUTPUT_50MHZ_PUSH_PULL);
	// GPIO_SetPinConfig(GPIO_PORTA,PIN3,OUTPUT_50MHZ_PUSH_PULL);
	// GPIO_SetPinConfig(GPIO_PORTA,PIN4,OUTPUT_10MHZ_AF_PUSH);
	// GPIO_SetPinConfig(GPIO_PORTA,PIN5,OUTPUT_10MHZ_AF_PUSH);
	// GPIO_SetPinConfig(GPIO_PORTA,PIN6,OUTPUT_10MHZ_AF_PUSH);
	// GPIO_SetPinConfig(GPIO_PORTA,PIN7,OUTPUT_10MHZ_AF_PUSH);


static int x=0;
x^=1;
while(1)
	{
		
			GPIO_SetPinValue(GPIO_PORTB,PIN8,1);
			GPIO_SetPinValue(GPIO_PORTB,PIN5,1);
		 SysTick_voidSetBusyWait(300);

	
	}


}


