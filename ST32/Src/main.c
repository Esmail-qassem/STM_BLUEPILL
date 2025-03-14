#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <stdint.h>
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "AFIO_interface.h"
#include "EXTI_interface.h"
#include "SysTick_interface.h"
#include "UART_interface.h" 
#include "FPEC.h"
#include "DMA.h"
#include "TFT.h"
extern const u16 IMT_IMAGE[];
void RCC_APP_Init(void);
void Peripheral_APP_Init(void);

void main(void)
{
	RCC_APP_Init();
	GPIO_SetPinConfig(GPIO_PORTA,PIN1,OUTPUT_50MHZ_PUSH_PULL);
	GPIO_SetPinConfig(GPIO_PORTA,PIN2,OUTPUT_50MHZ_PUSH_PULL);
	Peripheral_APP_Init();
	UART_u8SendStringSynch(UART_Unit3,"... I'm in application \n\r ");
	UART_u8SendStringSynch(UART_Unit3,"... ohhhh \r ");
	//TFT_VidFillColor(GREEN);
	TFT_VidFillImage( IMT_IMAGE ) ;
	UART_u8SendStringSynch(UART_Unit3,"\r... done \r ");


while(1)
	{
	
	}


}

typedef void (*Function_t)(void);
Function_t BACK_TO_BL = 0;
#ifdef APPLICATION_ONLY
FPEC_voidFlashWrite(0x08000000,0xE0,1);
#define SCB_VTOR   *((volatile uint32_t*)0xE000ED08)
SCB_VTOR = 0x08001400;
#pragma message "APPLICATION_ONLY is running!"
#endif  

void RCC_APP_Init(void)
{
	RCC_VidInit();
	SysTick_voidInit();
	RCC_voidEnablePeripheral(AHB_BUS,AHB_DMA1EN);
	RCC_voidEnablePeripheral(AHB_BUS,AHB_DMA2EN);
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOAEN);
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOBEN);
	RCC_voidEnablePeripheral(APB1_BUS,APB1_USART3EN);
	RCC_voidEnablePeripheral(APB1_BUS,APB1_SPI2EN);
}
void Peripheral_APP_Init(void)
{

	UART_voidInit();
	SPI_voidInit ();
	TFT_VidInit();

}