#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/*Define if you want to use spi1 or spi2 or both*/
/**********************************************************************************************************/
/**********************************************************************************************************/

#define SPI_1
//#define SPI_2

/**********************************************************************************************************/
/**********************************************************************************************************/
#ifdef SPI_1

/* _8_BIT_LENGTH,
 * _16_BIT_LENGTH,
 * */
#define SPI1_Data_Length _8_BIT_LENGTH

/*  Enable
 *  Disable
 * */

#define SPI1_RECEIVE_ONLY  Disable

/* MSB_FIRST
 * LSB_FIRST
 * */
#define SPI1_FRAME_FORMAT MSB_FIRST

/*  F_BY_2
 *  F_BY_4
 *  F_BY_8
 *  F_BY_16
 *  F_BY_32
 *  F_BY_64
 *  F_BY_128
 *  F_BY_256
 * */
#define SPI1_BAUD_RATE F_BY_4

/*Slave_config
 *Master_config
 * */
#define  SPI1_MASTER_SELECTION  Master_config

/*CK_TO_0_WHEN_IDLE
 *CK_TO_1_WHEN_IDLE
 * */
#define SPI1_CLOCK_POLARITY CK_TO_0_WHEN_IDLE

/* Read_then_Write
 * Write_Then_Read
 * */
#define SPI1_CLOCK_PHASE   Write_Then_Read



#endif
/**********************************************************************************************************/
/**********************************************************************************************************/

#ifdef SPI_2

/*_8_BIT_LENGTH,
 *_16_BIT_LENGTH,
 * */
#define SPI2_Data_Length  _8_BIT_LENGTH

/*  Enable
 *  Disable
 * */

#define SPI2_RECEIVE_ONLY  Enable

/*MSB_FIRST
 *LSB_FIRST
 * */
#define SPI2_FRAME_FORMAT MSB_FIRST

/*  F_BY_2
 *  F_BY_4
 *  F_BY_8
 *  F_BY_16
 *  F_BY_32
 *  F_BY_64
 *  F_BY_128
 *  F_BY_256
 * */
#define SPI2_BAUD_RATE  F_BY_2

/*Slave_config
 *Master_config
 * */
#define  SPI2_MASTER_SELECTION Master_config

/*CK_TO_0_WHEN_IDLE
 *CK_TO_1_WHEN_IDLE
 * */
#define SPI2_CLOCK_POLARITY CK_TO_0_WHEN_IDLE

/* Read_then_Write
 * Write_Then_Read
 * */
#define SPI2_CLOCK_PHASE   Write_Then_Read


#endif

#endif /* SPI_INC_SPI_CONFIG_H_ */
