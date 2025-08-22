#include "Parse.h"


char lineBuffer[MAX_LINE_LENGTH];
uint16 index = 0;


uint8 processRecord(uint8 *recordBuffer)
{
    int CRC;
    uint16 sum = 0;   // local sum
    uint8 number_of_data = parseByte(recordBuffer[1], recordBuffer[2]);
    uint8 address_high  = parseByte(recordBuffer[3], recordBuffer[4]);
    uint8 address_low   = parseByte(recordBuffer[5], recordBuffer[6]);
    uint16 address = (address_high << 8) | address_low;
    uint8 record_type   = parseByte(recordBuffer[7], recordBuffer[8]);

    sum += number_of_data + address_high + address_low + record_type;
    if(record_type == 0x00) // Data record
    {
        for(uint8 i = 0; i < number_of_data; i += 2)
            {
                uint8 data_low  = parseByte(recordBuffer[9 + i*2],   recordBuffer[10 + i*2]);
                uint8 data_high  = parseByte(recordBuffer[11 + i*2],  recordBuffer[12 + i*2]);
                uint16 halfword = (data_high << 8) | data_low;
                sum += data_high + data_low;
            
                FPEC_voidFlashWrite(0x08000000 + address, &halfword, 1);
                address += 2;

            }
    }
    else if(record_type == 0x01)
    {
      	UART_uint8SendStringSynch(UART_Unit3,"\nsoftware updated \n");
        return 0xFF;
    }  
    // Checksum
    uint8 crc = parseByte(recordBuffer[9 + number_of_data*2], recordBuffer[10 + number_of_data*2]);
    sum += crc;
    CRC = sum & 0xFF;   // only keep lowest 8 bits
    return CRC; // must be 0 if valid
}




uint8 asciiToHex(uint8 c)
{
    uint8 value=0;
  if (c >= '0' && c <= '9')
    {
        value = c - '0';     // '0' → 0, '9' → 9
    }
    else if (c >= 'A' && c <= 'F')
    {
        value = c - 'A' + 10;  // 'A' → 10, 'F' → 15
    }
    else if (c >= 'a' && c <= 'f')
    {
        value = c - 'a' + 10;  // 'a' → 10, 'f' → 15
    }
    else
    {
        // Invalid char 
    }
    return value;
}

uint8 parseByte(uint8 high, uint8 low)
{
   uint8 low_case= asciiToHex(low);
    uint8 high_case=asciiToHex(high);
    return((high_case<<4)|low_case);
}


void UART_RX_Handler(uint8 byte)
{
    static uint16 index = 0;

    if (byte == '\n' || byte == '\r') // End of line (accept CR or LF)
    {
        if (index > 0) // only if we actually received data
        {
            lineBuffer[index] = '\0';   // null terminate

            uint8 status = processRecord(lineBuffer);

            if (status == 0xFF) // EOF detected
            {
                UART_uint8SendStringSynch(UART_Unit3, "EOF received\n");
                SCB_AIRCR = 0x5FA0004; /* generate soft reset */
            }
            else if (status == 0) // valid line parsed
            {
                UART_uint8SendStringSynch(UART_Unit3, ".");  // ✅ print one dot per record
            }
        }
        index = 0; // reset for next line
    }
    else
    {
        if (index < MAX_LINE_LENGTH - 1)
        {
            lineBuffer[index++] = byte;
        }
        else
        {
            // Overflow protection
            UART_uint8SendStringSynch(UART_Unit3, "Line too long!\n");
            index = 0;
        }
    }
}
