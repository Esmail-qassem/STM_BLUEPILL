
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidInit (void);

Status_t Spi_SendRecieveSync(u16 Copy_u16Transmit,u16* Copy_pvReceived);


#endif /* SPI_INC_SPI_INTERFACE_H_ */
