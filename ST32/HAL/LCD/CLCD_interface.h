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
void CLCD_voidSendCommand(u8 copy_u8Command);
void CLCD_voidSendData(u8 copy_u8Data);

void CLCD_voidSendString(const u8* Copy_u8String);

void CLCD_voidGoToXY(u8 Copy_u8Xposition,u8 Copy_u8Yposition);

void CLCD_voidWriteNumber(s32 copy_u32Number);

void CLCD_voidWriteSpecialChar(u8* copy_pu8Pattern,u8 copy_u8PatternNumber,u8 copy_u8Xposition,u8 copy_u8Yposition);




#endif /* CLCD_INTERFACE_H_ */
