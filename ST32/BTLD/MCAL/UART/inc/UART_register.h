
#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_

#define UART1_BASE_Add      0x40013800   //APB2

#define UART2_BASE_Add      0x40004400   //APB1

#define UART3_BASE_Add      0x40004800   //APB1
/*****************************************************************************************************/
/*USART 1                                                                                            */
/*****************************************************************************************************/
/*UART STATUS REGISTER*/
#define USART1_SR_Reg      ((volatile USART_SR*)UART1_BASE_Add)
/*Data Register*/
#define USART1_DR_Reg      *((volatile u32*)(UART1_BASE_Add+0x04))
/*Baud Rate Register*/
#define USART1_BRR_Reg    ((volatile USART_BRR*)(UART1_BASE_Add+0x08))
/*Control Register 1*/
#define USART1_CR1_Reg     ((volatile USART_CR1*)(UART1_BASE_Add+0x0C))
/*Control Register 2*/
#define USART1_CR2_Reg     ((volatile USART_CR2*)(UART1_BASE_Add+0x10))
/*Control Register 3*/
#define USART1_CR3_Reg     ((volatile USART_CR3*)(UART1_BASE_Add+0x14))
/* Guard time and prescaler register*/
#define USART1_GTPR_Reg    *((volatile u32*)(UART1_BASE_Add+0x18))

/*****************************************************************************************************/
/*USART 2                                                                                            */
/*****************************************************************************************************/
/*UART STATUS REGISTER*/
#define USART2_SR_Reg      ((volatile USART_SR*)UART2_BASE_Add)
/*Data Register*/
#define USART2_DR_Reg      *((volatile u32*)(UART2_BASE_Add+0x04))
/*Baud Rate Register*/
#define USART2_BRR_Reg     ((volatile USART_BRR*)(UART2_BASE_Add+0x08))
/*Control Register 1*/
#define USART2_CR1_Reg     ((volatile USART_CR1*)(UART2_BASE_Add+0x0C))
/*Control Register 2*/
#define USART2_CR2_Reg     ((volatile USART_CR2*)(UART2_BASE_Add+0x10))
/*Control Register 3*/
#define USART2_CR3_Reg     ((volatile USART_CR3*)(UART2_BASE_Add+0x14))
/* Guard time and prescaler register*/
#define USART2_GTPR_Reg    *((volatile u32*)(UART2_BASE_Add+0x18))
/*****************************************************************************************************/
/*USART 3                                                                                            */
/*****************************************************************************************************/

#define USART3_SR_Reg      ((volatile USART_SR*)UART3_BASE_Add)
/*Data Register*/
#define USART3_DR_Reg      *((volatile u32*)(UART3_BASE_Add+0x04))
/*Baud Rate Register*/
#define USART3_BRR_Reg     ((volatile USART_BRR*)(UART3_BASE_Add+0x08))
/*Control Register 1*/
#define USART3_CR1_Reg     ((volatile USART_CR1*)(UART3_BASE_Add+0x0C))
/*Control Register 2*/
#define USART3_CR2_Reg     ((volatile USART_CR2*)(UART3_BASE_Add+0x10))
/*Control Register 3*/
#define USART3_CR3_Reg     ((volatile USART_CR3*)(UART3_BASE_Add+0x14))
/* Guard time and prescaler register*/
#define USART3_GTPR_Reg    *((volatile u32*)(UART3_BASE_Add+0x18))

#endif /* UART_REGISTER_H_ */
