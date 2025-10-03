/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:HAL                     *****************/
/*****************       SWC:CLCD_INTERFACE            *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_
/* Configuration     */
/***************************************************************/
#define CLCD_DATA_PORT      DIO_PORTC

#define CLCD_CONTROL_PORT   DIO_PORTD

#define CLCD_RS_PIN           DIO_Pin0
#define CLCD_RW_PIN           DIO_Pin1
#define CLCD_E_PIN            DIO_Pin2




/*************************************************************/
void CLCD_voidInit(void);
void CLCD_voidSendCommand(uint8 copy_uint8Command);
void CLCD_voidSendData(uint8 copy_uint8Data);

void CLCD_voidSendString(const uint8* Copy_uint8String);

void CLCD_voidGoToXY(uint8 Copy_uint8Xposition,uint8 Copy_uint8Yposition);

void CLCD_voidWriteNumber(sint32 copy_uint32Number);

void CLCD_voidWriteSpecialChar(uint8* copy_puint8Pattern,uint8 copy_uint8PatternNumber,uint8 copy_uint8Xposition,uint8 copy_uint8Yposition);




#endif /* CLCD_INTERFACE_H_ */
