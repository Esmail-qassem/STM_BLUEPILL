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
	uint32 PE:1;   // Parity error
	uint32 FE:1;   // Framing error
	uint32 NE:1;   //  Noise error flag
	uint32 ORE:1;  // Overrun error
	uint32 IDLE:1; // IDLE line detected
	uint32 RXNE:1; //  Read data register not empty
	uint32 TC:1;   //Transmission complete
	uint32 TXE:1;  // Transmit data empty
	uint32 LBD:1;  //LIN break detection flag
	uint32 CTS:1;  // CTS FLAG
	uint32 :22;
}USART_SR;

typedef struct
{
	uint32 DIV_FACTOR:4;
	uint32 DIV_MANTISSA:12 ;
	uint32:16;
}USART_BRR;

typedef struct
{
	uint32 SBK    :1;   // Send Break
	uint32 RWU    :1;   // Receiver wakeup
	uint32 RE     :1;   // Receiver enable
	uint32 TE     :1;   // Transmitter enable
	uint32 IDLEIE :1;   // IDLE interrupt enable
	uint32 RXNEIE :1;   // RXNE interrupt enable
	uint32 TCIE   :1;   // RXNE interrupt enable
	uint32 TXEIE  :1;   // TXE interrupt enable
	uint32 PEIE   :1;   // PE interrupt enable
	uint32 PS     :1;   // Parity selection
	uint32 PCE    :1;   // Parity control enable
	uint32 WAKE   :1;   // Wakeup method
	uint32 M      :1;   // Word length
	uint32 UE     :1;   // USART enable
    uint32        :18;
}USART_CR1;

typedef struct
{
	uint32 ADD    :3;   // Address of the USART node
	uint32        :1;   // Reserved
	uint32 LBDL   :1;   // lin break detection length
	uint32 LBDIE  :1;   // LIN break detection interrupt enable
	uint32        :1;   // Reserved
	uint32 LBCL   :1;   // Last bit clock pulse
	uint32 CPHA   :1;   // Clock phase
	uint32 CPOL   :1;   // Clock phase
	uint32 CLK_EN :1;   // Clock enable
	uint32 STOP   :2;   // STOP bits
    uint32        :17;
}USART_CR2;


typedef struct
{
	uint32 EIE    :1;   // Error interrupt enable
	uint32 IREN   :1;   // IrDA mode enable
	uint32 IRLP   :1;   // IrDA Low Power
	uint32 HDSEL  :1;   // Half-duplex selection
	uint32 NACK   :1;   // Smartcard NACK enable
	uint32 SCEN   :1;   // Smartcard mode enable
	uint32 DMAR   :1;   // DMA enable receiver
	uint32 DMAT   :1;   // DMA enable transmitter
	uint32 RTSE   :1;   // RTS enable
	uint32 CTSE   :1;   // CTS enable
	uint32 CTSIE  :1;   // CTS interrupt enable
    uint32        :21;
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

#define TIME_OUT 200000

#endif /* UART_PRIVATE_H_ */
