#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "UART_interface.h"
#include "FPEC.h"

typedef void (*Function_t)(void);
Function_t addr_to_call = 0;
#define SCB_VTOR   *((volatile uint32*)0xE000ED08)


int Pin_Reset,Power_Reset,Soft_Reset,flag;
uint32 cause;
uint32 Copy_uint32Address=0x80013f0;

uint16 Copy_uint16Data[4]={0x3333,0x2222,0x1111,0x4444};
void main(void)
{  
  RCC_VidInit();
	RCC_voidEnablePeripheral(APB2_BUS,APB2_GPIOAEN);
	RCC_voidEnablePeripheral(APB1_BUS,APB1_USART2EN);
	GPIO_SetPinConfig(GPIO_PORTA,PIN2,OUTPUT_50MHZ_AF_PUSH);
	GPIO_SetPinConfig(GPIO_PORTA,PIN3,INPUT_FLOATING);
  UART_voidInit();

  FPEC_voidFlashWrite(Copy_uint32Address,Copy_uint16Data,4);

     cause = RCC_CSR_REG->Reset_Reasone; 

      Pin_Reset=GET_BIT(cause,26);
      Power_Reset=GET_BIT(cause,27);
      Soft_Reset=GET_BIT(cause,28);
        /*clear the flag*/
      SET_BIT(RCC_CSR_REG->Reset_Reasone,24);
       UART_uint8SendStringSynch(UART_Unit1,"\nBM\n");

     if(Soft_Reset || Power_Reset)
      {
        /*jump to application*/
        SCB_VTOR = 0x08002800;
        addr_to_call = *(volatile Function_t*)(0x08002804);
        addr_to_call(); 
      }
      else if(Pin_Reset)
      {
        /*jump to bootloader*/
         SCB_VTOR = 0x08001400;
        addr_to_call = *(volatile Function_t*)(0x08001404);
        addr_to_call();
      }
    while(1){}

}


