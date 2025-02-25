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
    SPI1_CR2_Reg->TXEIE = 1; 
    SPI1_CR2_Reg->RXNEIE = 1;

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
    SPI2_CR2_Reg->TXEIE = 1; 
    SPI2_CR2_Reg->RXNEIE = 1; 
#endif
}
Status_t Spi_SendRecieveSync(SPI_HW SPI_HW_Unit,u16 Copy_u16Transmit,u16* Copy_pvReceived)
{
	Status_t Local_ErrorStatus=E_Not_Ok;
    if(NULL==Copy_pvReceived)
    {
    	Local_ErrorStatus=E_Null_Pointer;
    }
    else
    {
      Local_ErrorStatus=E_Ok;
      switch(SPI_HW_Unit)
      { 
        case SPI1 :
        {
            SPI1_DR_Reg=Copy_u16Transmit;
            /*wait*/
            while(SPI1_SR_Reg->BSY == 1);

            *Copy_pvReceived=SPI1_DR_Reg;
          break;
        }
        case SPI2 :
        {
            SPI2_DR_Reg=Copy_u16Transmit;
            /*wait*/
            while(SPI2_SR_Reg->BSY == 1);

            *Copy_pvReceived=SPI2_DR_Reg;
          break;
        }
        default : break;
      }
    }
return Local_ErrorStatus;
}

Status_t Spi_SendRecieveASync(SPI_HW SPI_HW_Unit,u16 Copy_u16Transmit,void(*P2F_CallBack)(u16))
{     
  switch (SPI_HW_Unit)
  {
    case SPI1 :
    {
      SPI1_CallBack=P2F_CallBack;
      SPI1_DR_Reg=Copy_u16Transmit;
  break;
    }
    case SPI2:

    {
      SPI2_CallBack=P2F_CallBack;
      SPI2_DR_Reg=Copy_u16Transmit;
break;
    }
    default :break;
  }

}


void SPI1_IRQHandler(void)
{
  if(SPI1_CallBack!=NULL)
  { 
     SPI1_CallBack(SPI1_DR_Reg);

  }
  
}
void SPI2_IRQHandler(void)
{
  if(SPI2_CallBack!=NULL)
  {
    SPI2_CallBack(SPI2_DR_Reg);

  }

}
