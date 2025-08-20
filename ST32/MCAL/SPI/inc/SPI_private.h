#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


static void (*SPI1_CallBack)(uint16) = NULL;
static void (*SPI2_CallBack)(uint16)=NULL;

typedef struct
{
	uint32 CPHA    :1;  /*Clock phase*/
	uint32 CPOL    :1;  /*Clock polarity*/
	uint32 MSTR    :1;  /*Master selection*/
    uint32 BR      :3;  /*Bude rate selection*/
    uint32 SPE     :1;  /* SPI enable */
    uint32 LSBFIRST:1;  /*Frame format*/
    uint32 SSI     :1;  /*Internal slave select*/
    uint32 SSM     :1;  /* Software slave management*/
    uint32 RXONLY  :1;  /*Recieve only*/
    uint32 DFF     :1;  /*Data Format*/
    uint32 CRCNEXT :1;  /*CRC transfer next*/
    uint32 CRCEN   :1;  /*Hardware CRC calculation enable*/
    uint32 BIDIOE  :1;  /* Output enable in bidirectional mode*/
    uint32 BIDIMODE:1;  /* Bidirectional data mode enable*/
    uint32         :16; /*Reserved*/
}SPI_CR1;
typedef struct
{
	uint32 RXDMAEN    :1;  /*Rx buffer DMA enable*/
	uint32 TXDMAEN    :1;  /*Tx buffer DMA enable*/
	uint32 SSOE       :1;  /*SS output enable*/
	uint32            :2;  /*Reserved*/
    uint32 ERRIE      :1;  /*Error interrupt enable*/
    uint32 RXNEIE     :1;  /*RX buffer not empty interrupt enable*/
    uint32 TXEIE      :1;  /*Tx buffer empty interrupt enable*/
    uint32            :24; /*Reserved*/
}SPI_CR2;

typedef struct
{
	uint32 RXNE   :1; /*Receive buffer not empty*/
	uint32 TXE    :1; /* Transmit buffer empty*/
	uint32 CHSIDE :1; /*Channel side*/
	uint32 UDR    :1; /*Underrun flag*/
    uint32 CRCERR :1; /*CRC error flag*/
    uint32 MODF   :1; /* Mode fault*/
    uint32 OVR    :1; /* Overrun flag*/
    uint32 BSY    :1; /* Busy flag*/
    uint32        :24 ; /*reserved*/
}SPI_SR;

enum Data_Frame
{
	_8_BIT_LENGTH,
	_16_BIT_LENGTH,
};

enum Frame_Frame
{
	MSB_FIRST,
	LSB_FIRST,
};

enum Baude_Rate
{
	F_BY_2,
	F_BY_4,
	F_BY_8,
	F_BY_16,
	F_BY_32,
	F_BY_64,
	F_BY_128,
	F_BY_256,
};

enum Master_selection
{
	Slave_config,
	Master_config,
};

enum Clock_Polarity_t
{
	CK_TO_0_WHEN_IDLE,  /*RISING EDGE TO START*/
	CK_TO_1_WHEN_IDLE,  /*FALLING EDGE TO START*/
};

enum Clock_Phase_t
{
	Read_then_Write,
	Write_Then_Read
};




#endif /* SPI_INC_SPI_PRIVATE_H_ */
