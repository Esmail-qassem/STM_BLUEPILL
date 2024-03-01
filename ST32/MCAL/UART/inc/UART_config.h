
#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_
/**************************************************************************************/
#define F_CPU              8000000UL
/* UART1
 * UART2
 * UART3
 * */
#define   UART1
#define   UART2
#define   UART3
/**************************************************************************************/
/****************   UART 1  ****************/
#define USART1_BAUD_RATE   115200

/*_8BIT
 *_9BIT
 * */
#define UART1_WORD_SIZE  _8BIT
/* UART1_PAR_DISABLE
 * UART1_PAR_EVEN
 * UART1_PAR_ODD
 * */
#define UART1_PARITY  UART1_PAR_DISABLE

/* INT_DISABLE
 * TXE_INT_ENABLE
 * TCE_INT_ENABLE
 * RXNE_INT_ENABLE
 * */
#define USART1_INTERRUPT INT_DISABLE
/* Stop_bit
 * Half_Stop_bit
 * Two_Stop_bit
 * One_half_Stop_bit
 * */
#define  UART1_Stop_Bit_Condition   Stop_bit

/**************************************************************************************/
/****************   UART 2  ****************/
#define USART2_BAUD_RATE   115200

/*_8BIT
 *_9BIT
 * */
#define UART2_WORD_SIZE  _8BIT

/* UART2_PAR_DISABLE
 * UART2_PAR_EVEN
 * UART2_PAR_ODD
 * */
#define UART2_PARITY  UART2_PAR_DISABLE

/* INT_DISABLE
 * TXE_INT_ENABLE
 * TCE_INT_ENABLE
 * RXNE_INT_ENABLE
 * */
#define USART2_INTERRUPT INT_DISABLE

/* Stop_bit
 * Half_Stop_bit
 * Two_Stop_bit
 * One_half_Stop_bit
 * */
#define  UART2_Stop_Bit_Condition   Stop_bit
/****************************************************************************/
/**************************************************************************************/
/****************   UART 3  ****************/
#define USART3_BAUD_RATE   115200

/*_8BIT
 *_9BIT
 * */
#define UART3_WORD_SIZE  _8BIT
/* UART1_PAR_DISABLE
 * UART1_PAR_EVEN
 * UART1_PAR_ODD
 * */
#define UART3_PARITY  UART1_PAR_DISABLE

/* INT_DISABLE
 * TXE_INT_ENABLE
 * TCE_INT_ENABLE
 * RXNE_INT_ENABLE
 * */
#define USART3_INTERRUPT INT_DISABLE
/* Stop_bit
 * Half_Stop_bit
 * Two_Stop_bit
 * One_half_Stop_bit
 * */
#define  UART3_Stop_Bit_Condition   Stop_bit
#endif /* UART_CONFIG_H_ */
