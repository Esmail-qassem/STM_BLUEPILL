#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SysTick_interface.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "UART_interface.h" 
#include "RTOS.h"

void RCC_Init(void)
{
	RCC_VidInit();
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOAEN);
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOBEN);
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOCEN);
	RCC_voidEnablePeripheral(APB2_BUS,APB2_USART1EN);
	RCC_voidEnablePeripheral(APB1_BUS,APB1_USART2EN);
	RCC_voidEnablePeripheral(APB1_BUS,APB1_USART3EN);
}
void Peripheral_APP_Init(void)
{
	GPIO_SetPinConfig(GPIO_PORTA,PIN9,OUTPUT_50MHZ_AF_PUSH);
	GPIO_SetPinConfig(GPIO_PORTA,PIN10,INPUT_FLOATING);
	GPIO_SetPinConfig(GPIO_PORTB,PIN10,OUTPUT_50MHZ_AF_PUSH);
	GPIO_SetPinConfig(GPIO_PORTB,PIN11,INPUT_FLOATING);
	GPIO_SetPinConfig(GPIO_PORTA,PIN2,OUTPUT_50MHZ_AF_PUSH);
	GPIO_SetPinConfig(GPIO_PORTA,PIN3,INPUT_FLOATING);
	/*BOARD TEST LED*/
	GPIO_SetPinConfig(GPIO_PORTC,PIN13,OUTPUT_10MHZ_PUSH_PULL);
	UART_voidInit();
}
static uint8 LED_TOGGLE=0;
void UART1 (void)
{
	 UART_voidSendNumber(UART_Unit1,LED_TOGGLE);
}
void UART2 (void)
{
	UART_uint8SendStringSynch(UART_Unit2,"test2\n");
}
void UART3 (void)
{
	LED_TOGGLE^=1;
	GPIO_SetPinValue(GPIO_PORTC,PIN13,LED_TOGGLE);

}
void main(void)
{
	RCC_Init();
	Peripheral_APP_Init();
	RTOS_voidCreateTask(1,100,&UART1);
	RTOS_voidCreateTask(0,1000,&UART2);
	RTOS_voidCreateTask(2,1000,&UART3);
	RTOS_voidStart();
	while(1)
	{

	}
}

