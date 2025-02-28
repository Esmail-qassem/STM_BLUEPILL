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
#include "FPEC.h"
#include "PwrMD.h"
typedef void (*Function_t)(void);
Function_t BACK_TO_BL = 0;

int volatile arr[3];
void main(void)
{
	#ifdef APPLICATION_ONLY
	 FPEC_voidFlashWrite(0x08000000,0xE0,1);
    #define SCB_VTOR   *((volatile uint32_t*)0xE000ED08)
    SCB_VTOR = 0x08001400;
    #pragma message "APPLICATION_ONLY is running!"
	#endif  
	
	RCC_VidInit();
	UART_voidInit();
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOBEN);
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOAEN);
	RCC_voidEnablePeripheral(APB1_BUS,APB1_USART3EN);
	GPIO_SetPinConfig(GPIO_PORTA,PIN0,OUTPUT_50MHZ_PUSH_PULL);
	GPIO_SetPinConfig(GPIO_PORTB,PIN10,OUTPUT_50MHZ_AF_PUSH);
	GPIO_SetPinConfig(GPIO_PORTB,PIN11,INPUT_FLOATING);
	GPIO_SetPinValue(GPIO_PORTA,PIN1,0);
	GPIO_SetPinValue(GPIO_PORTA,PIN0,1);
	
	UART_u8SendStringSynch(UART_Unit3,"... I'm in application \n\r ");
	UART_u8SendStringSynch(UART_Unit3,"... ohhhh \r ");
	
while(1)
	{
		UART_u8RecieveStringSynch(UART_Unit3,&arr,3);
		if (UART_IsStringEqual(&arr, "OK", 3)) 
		{
			#define SCB_VTOR   *((volatile u32*)0xE000ED08)
			SCB_VTOR = 0x08000000;
			BACK_TO_BL = *(volatile Function_t*)(0x08000004);
			UART_u8SendStringSynch(UART_Unit3," bye APP \n\r");
			BACK_TO_BL();

		}

		


	}


}


