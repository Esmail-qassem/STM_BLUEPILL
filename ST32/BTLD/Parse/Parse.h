#ifndef PARSE_H_
#define PARSE_H_

#include "STD_TYPES.h"
#include "UART_interface.h"
#include "FPEC.h"
#define SCB_AIRCR *((volatile uint32*)0xE000ED0C)

#define MAX_LINE_LENGTH 64

uint8 parseByte(uint8 high, uint8 low);
uint8 processRecord(uint8 *recordBuffer);
void UART_RX_Handler(uint8 data);












#endif