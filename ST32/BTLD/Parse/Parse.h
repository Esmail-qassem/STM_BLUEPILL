#ifndef PARSE_H_
#define PARSE_H_

#include "STD_TYPES.h"
uint8 asciiToHex(uint8 c);
uint8 parseByte(uint8 high, uint8 low);
uint8 processRecord(uint8 *recordBuffer, uint16 length);
void uartReceiveHandler(uint8 data);












#endif