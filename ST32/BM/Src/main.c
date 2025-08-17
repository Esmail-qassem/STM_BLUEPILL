#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "UART_interface.h"

typedef void (*Function_t)(void);
Function_t addr_to_call = 0;
#define SCB_VTOR   *((volatile u32*)0xE000ED08)


int Pin_Reset,Power_Reset,Soft_Reset,flag;
u32 cause;
void main(void)
{   RCC_VidInit();
    RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOBEN);
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOAEN);
	RCC_voidEnablePeripheral(APB1_BUS,APB1_USART2EN);
    GPIO_SetPinConfig(GPIO_PORTA,PIN9,OUTPUT_50MHZ_AF_PUSH);
	GPIO_SetPinConfig(GPIO_PORTA,PIN10,INPUT_FLOATING);
	GPIO_SetPinConfig(GPIO_PORTA,PIN2,OUTPUT_50MHZ_AF_PUSH);
	GPIO_SetPinConfig(GPIO_PORTA,PIN3,INPUT_FLOATING);
	GPIO_SetPinConfig(GPIO_PORTB,PIN10,OUTPUT_50MHZ_AF_PUSH);
	GPIO_SetPinConfig(GPIO_PORTB,PIN11,INPUT_FLOATING);
    UART_voidInit();
    UART_u8SendStringSynch(UART_Unit2,"BM\n");

     cause = RCC_CSR_REG->Reset_Reasone; 

      Pin_Reset=GET_BIT(cause,26);
      Power_Reset=GET_BIT(cause,27);
      Soft_Reset=GET_BIT(cause,28);
        /*clear the flag*/
      SET_BIT(RCC_CSR_REG->Reset_Reasone,24);
     if(Power_Reset)
      {
        /*jump to bootloader*/
         SCB_VTOR = 0x08001400;
        addr_to_call = *(volatile Function_t*)(0x08001404);
        addr_to_call();
        
      }
      else if(Soft_Reset)
      {
        /*jump to application*/
        SCB_VTOR = 0x08002800;
        addr_to_call = *(volatile Function_t*)(0x08002804);
        addr_to_call();

      }
      
      
    while(1)
    { }




}


