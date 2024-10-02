/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
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
//#include "../HAL/ESP/inc/ESP_interface.h"

//#define NVIC_TEST
//#define AFIO_TEST
//#define EXT_TEST




#ifdef EXT_TEST
void E0(void)
{

	static volatile value0=0;
	TOGGLE_BIT(value0,0);
	GPIO_SetPinValue(GPIO_PORTA,PIN5,value0);

}
void E1(void)
{

	static volatile value1=0;
	TOGGLE_BIT(value1,0);
	GPIO_SetPinValue(GPIO_PORTA,PIN6,value1);

}
void E2(void)
{

	static volatile value2=0;
	TOGGLE_BIT(value2,0);
	GPIO_SetPinValue(GPIO_PORTA,PIN7,value2);

}
void E3(void)
{

	static volatile value3=0;
	TOGGLE_BIT(value3,0);
	GPIO_SetPinValue(GPIO_PORTA,PIN8,value3);

}
void E4(void)
{

	static volatile value4=0;
	TOGGLE_BIT(value4,0);
	GPIO_SetPinValue(GPIO_PORTA,PIN9,value4);

}
#endif

void main(void)
{
	RCC_VidInit();
	SysTick_voidInit();
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOAEN);
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOBEN);
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOCEN);
	RCC_voidEnablePeripheral(APB1_BUS,APB1_USART3EN);
	RCC_voidEnablePeripheral(APB2_BUS,APB2_USART1EN);
    RCC_voidEnablePeripheral(APB1_BUS,APB1_USART2EN);


	GPIO_SetPinConfig(GPIO_PORTC,PIN13,OUTPUT_2MHZ_PUSH_PULL);

	GPIO_SetPinConfig(GPIO_PORTA,PIN0,OUTPUT_10MHZ_PUSH_PULL);
	GPIO_SetPinConfig(GPIO_PORTA,PIN1,OUTPUT_10MHZ_PUSH_PULL);
	GPIO_SetPinConfig(GPIO_PORTA,PIN2,OUTPUT_10MHZ_PUSH_PULL);
	GPIO_SetPinConfig(GPIO_PORTA,PIN3,OUTPUT_10MHZ_PUSH_PULL);
	GPIO_SetPinConfig(GPIO_PORTA,PIN4,OUTPUT_10MHZ_PUSH_PULL);

	GPIO_SetPinConfig(GPIO_PORTA,PIN9,OUTPUT_10MHZ_AF_PUSH);
	 GPIO_SetPinConfig(GPIO_PORTA,PIN10,INPUT_FLOATING);
	 GPIO_SetPinConfig(GPIO_PORTB,PIN10,OUTPUT_10MHZ_AF_PUSH);
	 GPIO_SetPinConfig(GPIO_PORTB,PIN11,INPUT_FLOATING);

	//GPIO_SetPinConfig(GPIO_PORTA,PIN0,OUTPUT_50MHZ_PUSH_PULL);


	//GPIO_SetPinConfig(GPIO_PORTB,PIN10,OUTPUT_10MHZ_AF_PUSH);
	//GPIO_SetPinConfig(GPIO_PORTB,PIN11,INPUT_FLOATING);

	//GPIO_SetPinConfig(GPIO_PORTA,PIN2,OUTPUT_10MHZ_AF_PUSH);
	//GPIO_SetPinConfig(GPIO_PORTA,PIN3,INPUT_FLOATING);


#ifdef EXT_TEST
	GPIO_SetPinConfig(GPIO_PORTA,PIN0,INPUT_PULL_UP_DOWN);
	GPIO_SetPinConfig(GPIO_PORTA,PIN1,INPUT_PULL_UP_DOWN);
	GPIO_SetPinConfig(GPIO_PORTA,PIN2,INPUT_PULL_UP_DOWN);
	GPIO_SetPinConfig(GPIO_PORTA,PIN3,INPUT_PULL_UP_DOWN);
	GPIO_SetPinConfig(GPIO_PORTA,PIN4,INPUT_PULL_UP_DOWN);

	GPIO_SetPinValue(GPIO_PORTA,PIN0,1);
	GPIO_SetPinValue(GPIO_PORTA,PIN1,1);
	GPIO_SetPinValue(GPIO_PORTA,PIN2,1);
	GPIO_SetPinValue(GPIO_PORTA,PIN3,1);
	GPIO_SetPinValue(GPIO_PORTA,PIN4,1);
#endif
#ifdef AFIO_TEST
	AFIO_voidSetEXTIConfiguration(AFIO_LINE1,AFIO_PORTB);
	AFIO_voidSetEXTIConfiguration(AFIO_LINE0,AFIO_PORTC);
	AFIO_voidSetEXTIConfiguration(AFIO_LINE15,AFIO_PORTB);

#endif

#ifdef NVIC_TEST
NVIC_EnableInterrupt(6);
NVIC_EnableInterrupt(7);

//NVIC_SetPriority(6,1,2);
//NVIC_SetPriority(7,0,3);


NVIC_SetPendingFlag(7);
NVIC_SetPendingFlag(6);


#endif


#ifdef EXT_TEST

RCC_voidEnablePeripheral(APB2_BUS, APB2_AFIOEN);
 AFIO_voidSetEXTIConfiguration(4,0);
 AFIO_voidSetEXTIConfiguration(1,0);
 AFIO_voidSetEXTIConfiguration(2,0);
 AFIO_voidSetEXTIConfiguration(0,0);
 AFIO_voidSetEXTIConfiguration(3,0);

 NVIC_EnableInterrupt(6);
 NVIC_EnableInterrupt(8);
 NVIC_EnableInterrupt(7);
 NVIC_EnableInterrupt(9);
 NVIC_EnableInterrupt(10);


 EXTI_SetSignalLatch(0,On_Change,EXT_Enable);
 EXTI_SetSignalLatch(1,On_Change,EXT_Enable);
 EXTI_SetSignalLatch(2,On_Change,EXT_Enable);
 EXTI_SetSignalLatch(3,On_Change,EXT_Enable);
 EXTI_SetSignalLatch(4,On_Change,EXT_Enable);

 EXTI_voidInterrupEnable(3);
 EXTI_voidInterrupEnable(0);
EXTI_voidInterrupEnable(4);
EXTI_voidInterrupEnable(1);
EXTI_voidInterrupEnable(2);

EXT0_CallBack(&E0);
EXT1_CallBack(&E1);
EXT2_CallBack(&E2);
EXT4_CallBack(&E4);
EXT3_CallBack(&E3);

#endif


//NVIC_EnableInterrupt(37);



//ESP_voidWifiLogin("esmail","Esmail1222001");


//ESP_voidConnectToTCP("185.176.43.106","80");

//x= ESP_u8ReceiveHttpReq("t3bt.atwebpages.com" ,"43" );

UART_voidInit();

while(1)
	{
GPIO_SetPinValue(GPIO_PORTC,PIN13,GPIO_HIGH);
 UART_u8SendStringSynch(UART_Unit1,"A");
SysTick_voidSetBusyWait(100);

		
	}


}

#ifdef NVIC_TEST

	void EXTI0_IRQHandler(void)
	{

 GPIO_SetPinValue(GPIO_PORTA,PIN0,GPIO_HIGH);

	}
	void EXTI1_IRQHandler(void)
	{


    GPIO_SetPinValue(GPIO_PORTA,PIN2,GPIO_HIGH);

	}


#endif
