
#include "CLCD_interface.h"
void Delay_ms(uint32 ms)
{
    uint32 cycle_per_ms =F_CPU/9000U;
    for(uint32 i=0;i<ms;i++)
    {
        for(uint32 j=0;j<50;j++);
    }
}
void CLCD_voidSendCommand(uint8 copy_uint8Command)
{
	/*Setting RS pin to low*/
GPIO_SetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_LOW);
/*Setting RW pin low for write*/
GPIO_SetPinValue(CLCD_CONTROL_PORT,CLCD_RW_PIN,DIO_LOW);

/*Set command data pins*/
GPIO_SetPortValue(CLCD_DATA_PORT,(uint8)copy_uint8Command);

/*Send Enable pulse*/
GPIO_SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_HIGH);
Delay_ms(2);
GPIO_SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_LOW);
}

void CLCD_voidInit(void)
{
	/*Wait more that 30 ms*/
	Delay_ms(35);

	/*Function set ,2 lines AND 5*8 size*/
	CLCD_voidSendCommand(0b00111000);
	/*Display on/off control:diplay enable,disable cursor*/
	CLCD_voidSendCommand(0b00001100);
	/*display clear*/
	CLCD_voidSendCommand(1);



}


void CLCD_voidSendData(uint8 copy_uint8Data)
{

	/*Setting RS pin to HIGH*/
	GPIO_SetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_HIGH);
	/*Setting RW pin low for write*/
	GPIO_SetPinValue(CLCD_CONTROL_PORT,CLCD_RW_PIN,DIO_LOW);

	/*Set data pins*/
	GPIO_SetPortValue(CLCD_DATA_PORT,(uint8)copy_uint8Data);

	/*Send Enable pulse*/
	GPIO_SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_HIGH);
	Delay_ms(2);
	GPIO_SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_LOW);


}

void CLCD_voidSendString(const uint8* Copy_uint8String)
{
uint8 Local_uint8Counter=0;
while(Copy_uint8String[Local_uint8Counter]!='\0')
{
    CLCD_voidSendData(Copy_uint8String[Local_uint8Counter]);
    Local_uint8Counter++;
}

}


void CLCD_voidGoToXY(uint8 Copy_uint8Xposition,uint8 Copy_uint8Yposition)
{
  uint8 Local_uint8Address;

  if(Copy_uint8Xposition==0)
  {
	  Local_uint8Address=Copy_uint8Yposition;
  }
  else if(Copy_uint8Xposition==1)

  {
	  Local_uint8Address=Copy_uint8Yposition+0x40;
  }

  CLCD_voidSendCommand(Local_uint8Address|(1<<7));
}


void CLCD_voidWriteNumber(sint32 copy_uint32Number)
{
	if(copy_uint32Number<0)
	{
		CLCD_voidSendData('-');
		copy_uint32Number= -copy_uint32Number;
	}
	if(copy_uint32Number==0)
	{
		CLCD_voidSendData('0');
		return;
	}
uint8 NUM[10];
uint8 Local_uint8Counter=0;
while(copy_uint32Number>0)
{
	NUM[Local_uint8Counter++]=(copy_uint32Number%10)+'0';
	copy_uint32Number/=10;
}
/*reverse*/
for(uint8 i=Local_uint8Counter;i>0;i--)
{
	CLCD_voidSendData(NUM[i-1]);
}
}
void CLCD_voidWriteSpecialChar(uint8* copy_puint8Pattern,uint8 copy_uint8PatternNumber,uint8 copy_uint8Xposition,uint8 copy_uint8Yposition)
{
	uint8 Local_uint8CGRAM_Address=0;
	/*Set the CGRAM address*/
Local_uint8CGRAM_Address=copy_uint8PatternNumber*8;
CLCD_voidSendCommand(Local_uint8CGRAM_Address|(1<<6));

for(uint8 i=0;i<8;i++)
{
	CLCD_voidSendData(copy_puint8Pattern[i]);
}
/*go back to DDRAM to display the Arr*/
 CLCD_voidGoToXY(copy_uint8Xposition,copy_uint8Yposition);

CLCD_voidSendData(copy_uint8PatternNumber);

}


