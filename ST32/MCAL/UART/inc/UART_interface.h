#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_



typedef enum
{
	UART_Unit1,
	UART_Unit2,
	UART_Unit3,


}UART_t;



void UART_voidInit(void);

void UART_uint8SendCharSynch(UART_t HardWare_Unit,uint8 Copy_uint16Data);

Status_t UART_uint8ReceiveCharSynch(UART_t HardWare_Unit,uint8 *Copy_p8ReceiveData);

Status_t UART_uint8SendStringSynch(UART_t HardWare_Unit,uint8* Copy_p8Data);

void UART_uint8RecieveStringSynch(UART_t HardWare_Unit,uint8*Copy_p8Data,uint8 Copy_uint8DataSize);

void UART_voidSendNumber(UART_t HardWare_Unit,s32 Copy_s32Number);

uint8 UART_IsStringEqual(const uint8 *str1, const uint8 *str2, uint8 length) ;


#endif /* UART_INTERFACE_H_ */
