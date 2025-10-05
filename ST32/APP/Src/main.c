#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "UART_interface.h" 
#include "IWDG.h"
#include "CLCD_interface.h"
#include "RTOS.h"
volatile uint32 idle_counter = 0;
void RCC_Init(void)
{
	RCC_VidInit();
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOAEN);
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOBEN);
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOCEN);
	 RCC_voidEnablePeripheral(APB2_BUS,APB2_USART1EN);
	 RCC_voidEnablePeripheral(APB1_BUS,APB1_USART3EN);
}
void Peripheral_APP_Init(void)
{
		/*uart 1*/
	 GPIO_SetPinConfig(GPIO_PORTA,PIN9,OUTPUT_50MHZ_AF_PUSH);
	 GPIO_SetPinConfig(GPIO_PORTA,PIN10,INPUT_FLOATING);
	 /*uart 3*/
	 GPIO_SetPinConfig(GPIO_PORTB,PIN10,OUTPUT_50MHZ_AF_PUSH);

	// /*BOARD TEST LED*/
	 GPIO_SetPinConfig(GPIO_PORTC,PIN13,OUTPUT_10MHZ_PUSH_PULL);
	/*LCD PIN CONFIGURATION*/
	GPIO_SetPinConfig(GPIO_PORTA,PIN0,OUTPUT_50MHZ_PUSH_PULL);
	GPIO_SetPinConfig(GPIO_PORTA,PIN1,OUTPUT_50MHZ_PUSH_PULL);
	GPIO_SetPinConfig(GPIO_PORTA,PIN2,OUTPUT_50MHZ_PUSH_PULL);
	GPIO_SetPinConfig(GPIO_PORTA,PIN3,OUTPUT_50MHZ_PUSH_PULL);
	GPIO_SetPinConfig(GPIO_PORTA,PIN4,OUTPUT_50MHZ_PUSH_PULL);
	GPIO_SetPinConfig(GPIO_PORTA,PIN5,OUTPUT_50MHZ_PUSH_PULL);
	GPIO_SetPinConfig(GPIO_PORTA,PIN6,OUTPUT_50MHZ_PUSH_PULL);
	GPIO_SetPinConfig(GPIO_PORTA,PIN7,OUTPUT_50MHZ_PUSH_PULL);
	GPIO_SetPinConfig(GPIO_PORTB,PIN0,OUTPUT_50MHZ_PUSH_PULL);
	GPIO_SetPinConfig(GPIO_PORTB,PIN1,OUTPUT_50MHZ_PUSH_PULL);
	GPIO_SetPinConfig(GPIO_PORTB,PIN11,OUTPUT_50MHZ_PUSH_PULL);
	UART_voidInit();
	CLCD_voidInit();
	
	
}


void LCD (void)
{	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("wdg con: ");
	CLCD_voidWriteNumber(idle_counter);
}
void UART1 (void)
{
UART_uint8SendStringSynch(UART_Unit1,"uart1\n");

}
void IdleTask(void)
{
	idle_counter++;
	if(idle_counter == 390)
	{
		/*reload the wdg every 396 ms */
		idle_counter=0;
		IWDG_VoidReload();
	}
}
void TOGGLE_LED (void)
{
	static uint8 TogglePin=0;
	TogglePin^=1;
	GPIO_SetPinValue(GPIO_PORTC,PIN13,TogglePin);

}

void main(void)
{
	IWDG_VoidInit();
	RCC_Init();
	Peripheral_APP_Init();
	RTOS_voidCreateTask(2,500,&LCD);
	RTOS_voidCreateTask(0,1000,&TOGGLE_LED);
	RTOS_voidCreateTask(1,20,&UART1);
	RTOS_voidCreateTask(3,1,&IdleTask);
	RTOS_voidStart();
	while(1)
	{

	}
}

