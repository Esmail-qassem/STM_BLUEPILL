#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_



typedef enum
{
	UART_Unit1,
	UART_Unit2,
	UART_Unit3,


}UART_t;



void UART_voidInit(void);

void UART_u8SendCharSynch(UART_t HardWare_Unit,u8 Copy_u16Data);

Status_t UART_u8ReceiveCharSynch(UART_t HardWare_Unit,u8 *Copy_p8ReceiveData);

Status_t UART_u8SendStringSynch(UART_t HardWare_Unit,u8* Copy_p8Data);

void UART_u8RecieveStringSynch(UART_t HardWare_Unit,u8*Copy_p8Data,u8 Copy_u8DataSize);



void UART1_VidSendCallBack( void(*ptr) (void) );
void UART2_VidSendCallBack( void(*ptr) (void) );
void UART2_VidSendCallBack( void(*ptr) (void) );


u8 UART_IsStringEqual(const u8 *str1, const u8 *str2, u8 length) ;


#endif /* UART_INTERFACE_H_ */
