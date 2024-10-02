#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_register.h"
#include "SPI_config.h"

void SPI_voidInit (void)
{
#ifdef SPI_1
	/*Data length selection*/
	SPI1_CR1_Reg->DFF=SPI1_Data_Length;
	/*If you want to be slave and receive only*/
    SPI1_CR1_Reg->RXONLY=SPI1_RECEIVE_ONLY;
    /*Software slave managment*/
    SPI1_CR1_Reg->SSM=1;
    /*Frame format*/
    SPI1_CR1_Reg->LSBFIRST=SPI1_FRAME_FORMAT;
    /*baud rate control*/
    SPI1_CR1_Reg->BR=SPI1_BAUD_RATE;
    /* Master selection */
    SPI1_CR1_Reg->MSTR= SPI1_MASTER_SELECTION;
    /*choose the clock plarity*/
    SPI1_CR1_Reg->CPOL=SPI1_CLOCK_POLARITY;
    /*choose the clock phase*/
    SPI1_CR1_Reg->CPHA=SPI1_CLOCK_PHASE;

    SPI1_CR1_Reg->SPE=Enable;
#endif
#ifdef SPI_2
	SPI2_CR1_Reg->DFF=SPI2_Data_Length;
	/*If you want to be slave and receive only*/
	 SPI2_CR1_Reg->RXONLY=SPI2_RECEIVE_ONLY;
	 /*Software slave managment*/
	 SPI2_CR1_Reg->SSM=1;
	 /*Frame format*/
	 SPI2_CR1_Reg->LSBFIRST=SPI2_FRAME_FORMAT;
	 /*baud rate control*/
	 SPI2_CR1_Reg->BR=SPI2_BAUD_RATE;
	 /* Master selection */
	 SPI2_CR1_Reg->MSTR= SPI2_MASTER_SELECTION;
	 /*choose the clock plarity*/
	  SPI2_CR1_Reg->CPOL=SPI2_CLOCK_POLARITY;
	  /*choose the clock phase*/
	  SPI2_CR1_Reg->CPHA=SPI2_CLOCK_PHASE;

	  SPI2_CR1_Reg->SPE=Enable;
#endif
}
Status_t Spi_SendRecieveSync(u16 Copy_u16Transmit,u16* Copy_pvReceived)
{
	Status_t Local_ErrorStatus=E_Not_Ok;
    if(NULL==Copy_pvReceived)
    {
    	Local_ErrorStatus=E_Null_Pointer;
    }
    else
    {
    	Local_ErrorStatus=E_Ok;
      SPI1_DR_Reg=Copy_u16Transmit;

      /*wait*/
      while(SPI1_SR_Reg->BSY == 1);

      *Copy_pvReceived=SPI1_DR_Reg;
    }
return Local_ErrorStatus;
}
