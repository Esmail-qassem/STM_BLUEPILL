#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "UART_interface.h" 
#include "SPI_interface.h"
void RCC_APP_Init(void);
void Peripheral_APP_Init(void);
extern int count;
void main(void)
{
	RCC_APP_Init();
	Peripheral_APP_Init();
	//GPIO_SetPinConfig(GPIO_PORTB,PIN10,OUTPUT_50MHZ_AF_PUSH);
	//GPIO_SetPinConfig(GPIO_PORTB,PIN15,OUTPUT_50MHZ_AF_PUSH);
	//GPIO_SetPinConfig(GPIO_PORTB,PIN13,OUTPUT_50MHZ_AF_PUSH);
	//GPIO_SetPinConfig(GPIO_PORTA,PIN0,OUTPUT_50MHZ_PUSH_PULL);
	//GPIO_SetPinConfig(GPIO_PORTA,PIN1,OUTPUT_50MHZ_PUSH_PULL);
	//GPIO_SetPinConfig(GPIO_PORTA,PIN2,OUTPUT_50MHZ_PUSH_PULL);
	//UART_u8SendStringSynch(UART_Unit3,"... I'm in application \n\r ");
	//UART_u8SendStringSynch(UART_Unit3,"... ohhhh \n\r ");
	////TFT_VidFillColor(GREEN);
	////TFT_VidFillImage( IMT_IMAGE ) ;
	//UART_u8SendStringSynch(UART_Unit3,"\r... done \n\r ");
	// UART_voidSendNumber(UART_Unit3,count);
	// GPIO_SetPinValue(GPIO_PORTA,PIN0,1);
	//GPIO_SetPinValue(GPIO_PORTA,PIN1,1);
	//GPIO_SetPinValue(GPIO_PORTA,PIN2,1);

while(1)
	{
		for(int x=0;x<50000;x++);
		//UART_voidSendNumber(UART_Unit3,count);
		// Spi_SendRecieveSync(SPI2,11,&count);

		//count++;
		for(int x=0;x<50000;x++);
	}


}

/*test*/ 

void RCC_APP_Init(void)
{
	RCC_VidInit();
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOAEN);
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOBEN);
	RCC_voidEnablePeripheral(APB1_BUS,APB1_USART3EN);
	RCC_voidEnablePeripheral(APB1_BUS,APB1_SPI2EN);
}
void Peripheral_APP_Init(void)
{

	UART_voidInit();
	SPI_voidInit ();

}
