#include "Parse.h"
int sum=0; 
uint8 processRecord(uint8 *recordBuffer, uint16 length)
{  
    uint8 CRC=0;
    uint8 number_of_data=parseByte(*(recordBuffer+1),*(recordBuffer+2));
    sum+=number_of_data;
    uint8 address_high=parseByte(*(recordBuffer+3),*(recordBuffer+4));
    uint8 address_low=parseByte(*(recordBuffer+5),*(recordBuffer+6));

    uint16 address=(address_high<<8)|address_low;
            sum+=address;
    uint8 Datatype= parseByte(*(recordBuffer+7),*(recordBuffer+8));
                sum+=Datatype;
    for(uint8 i=0;i<number_of_data*2;i+=2)
    {
        
        int value =parseByte(recordBuffer[9+i],recordBuffer[9+i+1]);
                        sum+=value;
    }
    uint8 crc=parseByte(recordBuffer[number_of_data*2+9],recordBuffer[number_of_data*2+10]);
    sum+=crc;
    CRC=sum;
    sum=0;
    return CRC;
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

