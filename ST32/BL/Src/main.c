#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "UART_interface.h" 
#include "FPEC.h"
void Parser_voidParseRecord(u8* Copy_u8BufData);

volatile u8  u8RecBuffer[100]   ;
volatile u8  u8RecCounter    = 0;
volatile u8  u8TimeOutFlag   = 0;
volatile u16 u16TimerCounter = 0;
volatile u8  u8BLWriteReq    = 1;
typedef void (*Function_t)(void);
Function_t addr_to_call = 0;

void func(void)
{
#define SCB_VTOR   *((volatile u32*)0xE000ED08)

	SCB_VTOR = 0x08001400;

	addr_to_call = *(volatile Function_t*)(0x08001404);
	UART_u8SendStringSynch(UART_Unit3,"bye");
	addr_to_call();
}

void init (void)
{

	RCC_VidInit();
	SysTick_voidInit();
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOBEN);
	RCC_voidEnablePeripheral(APB1_BUS,APB1_USART3EN);
	RCC_voidEnablePeripheral(AHB_BUS,AHB_FLITFEN);
	GPIO_SetPinConfig(GPIO_PORTB,PIN10,OUTPUT_50MHZ_AF_PUSH);
	GPIO_SetPinConfig(GPIO_PORTB,PIN11,INPUT_FLOATING);
	
	UART_voidInit();
	


} 
void main(void)
{
	u8 Local_u8RecStatus;

	init();
	SysTick_voidSetIntervalSingle(15000000,func);
	while(u8TimeOutFlag == 0)
	{
		Local_u8RecStatus = UART_u8ReceiveCharSynch(UART_Unit3, &u8RecBuffer[u8RecCounter]);
		if (Local_u8RecStatus == 0)
		{
			SysTick_voidStopTimer();

			if(u8RecBuffer[u8RecCounter] == '\n')
			{
				if (u8BLWriteReq == 1)
				{
					FPEC_voidEraseAppArea();
					u8BLWriteReq = 0;
				}
				
				/* Parse */
				Parser_voidParseRecord(u8RecBuffer);
				UART_u8SendStringSynch(UART_Unit3,"ok");
				u8RecCounter = 0;
			}
			else
			{
				u8RecCounter ++ ;
			}

			SysTick_voidSetIntervalSingle(15000000,func);
		}

		else
		{
			

		}






	}


}


