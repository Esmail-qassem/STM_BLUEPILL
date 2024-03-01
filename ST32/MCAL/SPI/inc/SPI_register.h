
#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

/***************************************************************************************************************************/
/********************************** SPI 1   APB2 ******************************************/

#define SPI1_BASE_Add   0x40013000

#define SPI1_CR1_Reg       ((volatile SPI_CR1*)SPI1_BASE_Add)
#define SPI1_CR2_Reg       ((volatile SPI_CR2*)(SPI1_BASE_Add+0x04))
#define SPI1_SR_Reg        ((volatile SPI_SR*)(SPI1_BASE_Add+0x08))

#define SPI1_DR_Reg       *((volatile u32*)(SPI1_BASE_Add+0x0c))

#define SPI1_CRCPR_Reg        *((volatile u32*)(SPI1_BASE_Add+0x10))
#define SPI1_RXCRCR_Reg       *((volatile u32*)(SPI1_BASE_Add+0x14))
#define SPI1_TXCRCR_Reg       *((volatile u32*)(SPI1_BASE_Add+0x18))



/***************************************************************************************************************************/
/********************************** SPI 2   APB1 ******************************************/
#define SPI2_BASE_Add  0x40003800

#define SPI2_CR1_Reg       ((volatile SPI_CR1*)SPI2_BASE_Add)
#define SPI2_CR2_Reg       ((volatile SPI_CR2*)(SPI2_BASE_Add+0x04))
#define SPI2_SR_Reg        ((volatile SPI_SR*)(SPI2_BASE_Add+0x08))

#define SPI2_DR_Reg       *((volatile u32*)(SPI2_BASE_Add+0x0c))

#define SPI2_CRCPR_Reg        *((volatile u32*)(SPI2_BASE_Add+0x10))
#define SPI2_RXCRCR_Reg       *((volatile u32*)(SPI2_BASE_Add+0x14))
#define SPI2_TXCRCR_Reg       *((volatile u32*)(SPI2_BASE_Add+0x18))


#endif /* SPI_INC_SPI_REGISTER_H_ */
