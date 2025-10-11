#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "UART_interface.h" 
#include "IWDG.h"
#include "CLCD_interface.h"
#include "RTOS.h"
#include "flappy_bird.h"
/************************************/
/* Global Variable */
I2C_Config_t config={400000,0,1,0};
/************************************/
/*proto typed*/
void RCC_Init(void);
void Peripheral_APP_Init(void);
/************************************/
uint8 PUSH_BUTTON = 1;
/*Tasks*/
void IdleTask(void)
{
	// static uint32 idle_counteridle_counter=0;
	// idle_counteridle_counter++;
	// if(idle_counteridle_counter == 396)
	// {
	// 	/*reload the wdg every 396 ms */
	// 	idle_counteridle_counter=0;
	// 	IWDG_VoidReload();
	// }
	GPIO_GetPinReading(GPIO_PORTB,PIN5,&PUSH_BUTTON);
}
void TOGGLE_LED (void)
{
	static uint8 TogglePin=0;
	TogglePin^=1;
	GPIO_SetPinValue(GPIO_PORTC,PIN13,TogglePin);
	GPIO_SetPinValue(GPIO_PORTB,PIN15,TogglePin);
}


void I2C_TASK (void)
{
	Flappy_MainFunction();
	Bird_Jump();
}
/************************************/
void main(void)
{
	//IWDG_VoidInit();
	RCC_Init();
	Peripheral_APP_Init();
	RTOS_voidCreateTask(2,500,&TOGGLE_LED);
	RTOS_voidCreateTask(1,10,&IdleTask);
	RTOS_voidCreateTask(0,50,&I2C_TASK);
	RTOS_voidStart();
	while(1)
	{
	}
}











void RCC_Init(void)
{
	RCC_VidInit();
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOAEN);
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOBEN);
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOCEN);
	RCC_voidEnablePeripheral(APB2_BUS,APB2_USART1EN);
	RCC_voidEnablePeripheral(APB1_BUS,APB1_USART3EN);
	RCC_voidEnablePeripheral(APB1_BUS,APB1_I2C1EN);
}
void Peripheral_APP_Init(void)
{
		/*uart 1*/
	 GPIO_SetPinConfig(GPIO_PORTA,PIN9,OUTPUT_50MHZ_AF_PUSH);
	 GPIO_SetPinConfig(GPIO_PORTA,PIN10,INPUT_FLOATING);
	 /*uart 3*/
	 GPIO_SetPinConfig(GPIO_PORTB,PIN10,OUTPUT_50MHZ_AF_PUSH);
	 GPIO_SetPinConfig(GPIO_PORTB,PIN11,INPUT_FLOATING);

	// /*BOARD TEST LED*/
	 GPIO_SetPinConfig(GPIO_PORTC,PIN13,OUTPUT_50MHZ_PUSH_PULL);
	 GPIO_SetPinConfig(GPIO_PORTB,PIN15,OUTPUT_50MHZ_PUSH_PULL);
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
	GPIO_SetPinConfig(GPIO_PORTB,PIN12,OUTPUT_50MHZ_PUSH_PULL);

	/*I2C 1*/
	 GPIO_SetPinConfig(GPIO_PORTB,PIN6,OUTPUT_50MHZ_AF_OPEN_DRAIN);
	 GPIO_SetPinConfig(GPIO_PORTB,PIN7,OUTPUT_50MHZ_AF_OPEN_DRAIN);
	/*I2C 2*/


	/* push botton */
	GPIO_SetPinConfig(GPIO_PORTB,PIN5,INPUT_PULL_UP_DOWN);
	GPIO_SetPinValue(GPIO_PORTB,PIN5,GPIO_HIGH);


	//UART_voidInit();
	//CLCD_voidInit();
	I2C_Init(I2C1_PORT,&config);
	SH1106_Init(I2C1_PORT);
	//SH1106_Clear();
}