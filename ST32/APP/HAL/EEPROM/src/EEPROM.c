#include "EEPROM.h"

#define EEPROM_BASE_ADDR 0x50 // A2 = 0

void EEPROM_WriteToBlock(I2C_Port_t port,uint8 block, uint8 byteAddr, uint8 data)
{
    uint8 slaveAddr = EEPROM_BASE_ADDR + (block & 0x03); // block 0..3
    uint8 buf[2] = { byteAddr, data };

    // Send device address + byte address + data
    I2C_MasterTransmit(port, slaveAddr, buf, 2, 0);

    // Wait for EEPROM internal write cycle (5ms typical)
    //delay_ms(5);
 for (volatile uint32 i = 0; i < 50000; i++);
}
void EEPROM_ReadFromBlock(I2C_Port_t port,uint8 block, uint8 byteAddr, uint8 *data)
{
    uint8 slaveAddr = EEPROM_BASE_ADDR + (block & 0x03);

    // Send address pointer
    I2C_MasterTransmit(port, slaveAddr, &byteAddr, 1, 1);

    // Repeated start for read
    I2C_MasterReceive(port, slaveAddr, data, 1, 0);
}
