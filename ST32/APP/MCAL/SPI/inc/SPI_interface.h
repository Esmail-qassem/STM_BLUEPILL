
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "DMA.h"
typedef enum 
{
    SPI1,
    SPI2
}SPI_HW;


void SPI_voidInit (void);

Status_t Spi_SendRecieveSync(SPI_HW SPI_HW_Unit,uint16 Copy_uint16Transmit,uint16* Copy_pvReceived);
Status_t Spi_SendRecieveASync(SPI_HW SPI_HW_Unit,uint16 Copy_uint16Transmit,void(*P2F_CallBack)(uint16));
void SPI_SendDataDMA(uint8 *data, uint16 size);
#endif /* SPI_INC_SPI_INTERFACE_H_ */
