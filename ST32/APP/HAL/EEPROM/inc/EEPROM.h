#ifndef EEPROM_H_
#define EEPROM_H_

#include "STD_TYPES.h"
#include "I2C.h"


void EEPROM_WriteToBlock(I2C_Port_t port,uint8 block, uint8 byteAddr, uint8 data);
void EEPROM_ReadFromBlock(I2C_Port_t port,uint8 block, uint8 byteAddr, uint8 *data);




#endif