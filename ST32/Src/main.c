#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SysTick_interface.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "UART_interface.h" 
void RCC_APP_Init(void);
void Peripheral_APP_Init(void);
extern int count;
u8 Arr[10];
void main(void)
{
	RCC_APP_Init();
	Peripheral_APP_Init();
while(1)
	{
		SysTick_voidSetBusyWait(100);
		UART_u8SendStringSynch(UART_Unit1,"uart1\n");
	//	UART_u8SendStringSynch(UART_Unit2,"uart2\n");
	//	UART_u8SendStringSynch(UART_Unit3,"uart3\n");

	}


}

/*test*/ 

void RCC_APP_Init(void)
{
	RCC_VidInit();
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOAEN);
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOBEN);
	RCC_voidEnablePeripheral(APB2_BUS,APB2_USART1EN);
	RCC_voidEnablePeripheral(APB1_BUS,APB1_USART3EN);
	RCC_voidEnablePeripheral(APB1_BUS,APB1_USART2EN);

}
void Peripheral_APP_Init(void)
{
	GPIO_SetPinConfig(GPIO_PORTA,PIN9,OUTPUT_50MHZ_AF_PUSH);
	GPIO_SetPinConfig(GPIO_PORTA,PIN10,INPUT_FLOATING);
	GPIO_SetPinConfig(GPIO_PORTA,PIN2,OUTPUT_50MHZ_AF_PUSH);
	GPIO_SetPinConfig(GPIO_PORTA,PIN3,INPUT_FLOATING);
	GPIO_SetPinConfig(GPIO_PORTB,PIN10,OUTPUT_50MHZ_AF_PUSH);
	GPIO_SetPinConfig(GPIO_PORTB,PIN11,INPUT_FLOATING);
	UART_voidInit();
}
