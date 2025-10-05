#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
/* Configuration     */
/***************************************************************/
#ifndef F_CPU
#define F_CPU   36000000UL
#endif
#define CLCD_DATA_PORT      GPIO_PORTA

#define CLCD_CONTROL_PORT   GPIO_PORTB

#define CLCD_RS_PIN           PIN0
#define CLCD_RW_PIN           PIN1
#define CLCD_E_PIN            PIN11

#define DIO_LOW   0
#define DIO_HIGH  1



/*************************************************************/
void CLCD_voidInit(void);
void CLCD_voidSendCommand(uint8 copy_uint8Command);
void CLCD_voidSendData(uint8 copy_uint8Data);

void CLCD_voidSendString(const uint8* Copy_uint8String);

void CLCD_voidGoToXY(uint8 Copy_uint8Xposition,uint8 Copy_uint8Yposition);

void CLCD_voidWriteNumber(sint32 copy_uint32Number);

void CLCD_voidWriteSpecialChar(uint8* copy_puint8Pattern,uint8 copy_uint8PatternNumber,uint8 copy_uint8Xposition,uint8 copy_uint8Yposition);
void Delay_ms(uint32 ms);



#endif /* CLCD_INTERFACE_H_ */
