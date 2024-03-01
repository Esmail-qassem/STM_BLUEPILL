/*
 * UART_private.h
 *
 *  Created on: Nov 18, 2023
 *      Author: s_a_a
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_
/*************************************************************/
static void (*UART1_CallBack)(void) = NULL;
static void (*UART2_CallBack)(void)=NULL;
static void (*UART3_CallBack)(void)=NULL;
/*************************************************************/
typedef struct
{
	u32 PE:1;   // Parity error
	u32 FE:1;   // Framing error
	u32 NE:1;   //  Noise error flag
	u32 ORE:1;  // Overrun error
	u32 IDLE:1; // IDLE line detected
	u32 RXNE:1; //  Read data register not empty
	u32 TC:1;   //Transmission complete
	u32 TXE:1;  // Transmit data empty
	u32 LBD:1;  //LIN break detection flag
	u32 CTS:1;  // CTS FLAG
	u32 :22;
}USART_SR;

typedef struct
{
	u32 DIV_FACTOR:4;
	u32 DIV_MANTISSA:12 ;
	u32:16;
}USART_BRR;

typedef struct
{
	u32 SBK    :1;   // Send Break
	u32 RWU    :1;   // Receiver wakeup
	u32 RE     :1;   // Receiver enable
	u32 TE     :1;   // Transmitter enable
	u32 IDLEIE :1;   // IDLE interrupt enable
	u32 RXNEIE :1;   // RXNE interrupt enable
	u32 TCIE   :1;   // RXNE interrupt enable
	u32 TXEIE  :1;   // TXE interrupt enable
	u32 PEIE   :1;   // PE interrupt enable
	u32 PS     :1;   // Parity selection
	u32 PCE    :1;   // Parity control enable
	u32 WAKE   :1;   // Wakeup method
	u32 M      :1;   // Word length
	u32 UE     :1;   // USART enable
    u32        :18;
}USART_CR1;

typedef struct
{
	u32 ADD    :3;   // Address of the USART node
	u32        :1;   // Reserved
	u32 LBDL   :1;   // lin break detection length
	u32 LBDIE  :1;   // LIN break detection interrupt enable
	u32        :1;   // Reserved
	u32 LBCL   :1;   // Last bit clock pulse
	u32 CPHA   :1;   // Clock phase
	u32 CPOL   :1;   // Clock phase
	u32 CLK_EN :1;   // Clock enable
	u32 STOP   :2;   // STOP bits
    u32        :17;
}USART_CR2;


typedef struct
{
	u32 EIE    :1;   // Error interrupt enable
	u32 IREN   :1;   // IrDA mode enable
	u32 IRLP   :1;   // IrDA Low Power
	u32 HDSEL  :1;   // Half-duplex selection
	u32 NACK   :1;   // Smartcard NACK enable
	u32 SCEN   :1;   // Smartcard mode enable
	u32 DMAR   :1;   // DMA enable receiver
	u32 DMAT   :1;   // DMA enable transmitter
	u32 RTSE   :1;   // RTS enable
	u32 CTSE   :1;   // CTS enable
	u32 CTSIE  :1;   // CTS interrupt enable
    u32        :21;
}USART_CR3;


enum Stop
{
	Stop_bit=0b00,
	Half_Stop_bit=0b01,
	Two_Stop_bit=0b10,
	One_half_Stop_bit=0b11,
};



/***********************************************************************/
#define _8BIT 0
#define _9BIT 1

#define UART1_PAR_DISABLE   0
#define UART1_PAR_EVEN      1
#define UART1_PAR_ODD       2

#define INT_DISABLE         0
#define TXE_INT_ENABLE      1
#define TCE_INT_ENABLE      2
#define RXNE_INT_ENABLE     3

#define UART2_PAR_DISABLE   0
#define UART2_PAR_EVEN      1
#define UART2_PAR_ODD       2

#define TIME_OUT 100000

#endif /* UART_PRIVATE_H_ */
