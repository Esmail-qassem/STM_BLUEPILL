#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

typedef struct
{
	u32 CPHA    :1;  /*Clock phase*/
	u32 CPOL    :1;  /*Clock polarity*/
	u32 MSTR    :1;  /*Master selection*/
    u32 BR      :3;  /*Bude rate selection*/
    u32 SPE     :1;  /* SPI enable */
    u32 LSBFIRST:1;  /*Frame format*/
    u32 SSI     :1;  /*Internal slave select*/
    u32 SSM     :1;  /* Software slave management*/
    u32 RXONLY  :1;  /*Recieve only*/
    u32 DFF     :1;  /*Data Format*/
    u32 CRCNEXT :1;  /*CRC transfer next*/
    u32 CRCEN   :1;  /*Hardware CRC calculation enable*/
    u32 BIDIOE  :1;  /* Output enable in bidirectional mode*/
    u32 BIDIMODE:1;  /* Bidirectional data mode enable*/
    u32         :16; /*Reserved*/
}SPI_CR1;
typedef struct
{
	u32 RXDMAEN    :1;  /*Rx buffer DMA enable*/
	u32 TXDMAEN    :1;  /*Tx buffer DMA enable*/
	u32 SSOE       :1;  /*SS output enable*/
	u32            :2;  /*Reserved*/
    u32 ERRIE      :1;  /*Error interrupt enable*/
    u32 RXNEIE     :1;  /*RX buffer not empty interrupt enable*/
    u32 TXEIE      :1;  /*Tx buffer empty interrupt enable*/
    u32            :24; /*Reserved*/
}SPI_CR2;

typedef struct
{
	u32 RXNE   :1; /*Receive buffer not empty*/
	u32 TXE    :1; /* Transmit buffer empty*/
	u32 CHSIDE :1; /*Channel side*/
	u32 UDR    :1; /*Underrun flag*/
    u32 CRCERR :1; /*CRC error flag*/
    u32 MODF   :1; /* Mode fault*/
    u32 OVR    :1; /* Overrun flag*/
    u32 BSY    :1; /* Busy flag*/
    u32        :24 ; /*reserved*/
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
