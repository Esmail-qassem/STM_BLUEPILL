#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "UART_interface.h" 
#include "RTOS.h"
volatile uint32 idle_counter = 0;
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


void UART1 (void)
{	
UART_uint8SendStringSynch(UART_Unit1,"test1\n");
}
void UART2 (void)
{
	UART_uint8SendStringSynch(UART_Unit2,"test2\n");
}
void IdleTask(void)
{
	idle_counter++;
}
void TOGGLE_LED (void)
{
	static uint8 TogglePin=0;
	TogglePin^=1;
	GPIO_SetPinValue(GPIO_PORTC,PIN13,TogglePin);

}

void main(void)
{
	RCC_Init();
	Peripheral_APP_Init();
	RTOS_voidCreateTask(1,10,&UART1);
	RTOS_voidCreateTask(0,50,&UART2);
	RTOS_voidCreateTask(2,20,&TOGGLE_LED);
	RTOS_voidCreateTask(3,1,&IdleTask);
	RTOS_voidStart();
	while(1)
	{

	}
}

