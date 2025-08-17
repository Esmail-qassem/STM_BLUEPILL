/***********************************************************************/
/*Aauthor     : Esamil Qassem                                          */
/*Data        : 11 JAN 2024                                            */
/*SWC         : GPIO                                                    */
/*Version     : V.1                                                    */
/***********************************************************************/
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


typedef enum
{
	INPUT_ANALOG =0b0000,
	INPUT_FLOATING=0b0100,
	INPUT_PULL_UP_DOWN=0b1000,

	OUTPUT_10MHZ_PUSH_PULL =0b0001,
	OUTPUT_10MHZ_OPEN_DRAIN =0b0101,
	OUTPUT_10MHZ_AF_PUSH =0b1001,
	OUTPUT_10MHZ_AF_OPEN_DRAIN =0b1101,

	OUTPUT_2MHZ_PUSH_PULL =0b0010,
	OUTPUT_2MHZ_OPEN_DRAIN =0b0110,
	OUTPUT_2MHZ_AF_PUSH =0b1010,
	OUTPUT_2MHZ_AF_OPEN_DRAIN =0b1110,

	OUTPUT_50MHZ_PUSH_PULL =0b0011,
	OUTPUT_50MHZ_OPEN_DRAIN =0b0111,
	OUTPUT_50MHZ_AF_PUSH =0b1011,
	OUTPUT_50MHZ_AF_OPEN_DRAIN =0b1111,
}Bit_Mode_t;

typedef enum
{
	GPIO_PORTA,
	GPIO_PORTB,
	GPIO_PORTC
}PORT_t;
typedef enum
{   PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}PIN_t;
typedef enum
{
	GPIO_ok,
	GPIO_Wrong_Port,
	GPIO_Wrong_bit
}GPIO_STATUS_t;

#define GPIO_HIGH 1
#define GPIO_LOW  0


GPIO_STATUS_t GPIO_SetPinConfig(PORT_t Copy_Port,PIN_t Copy_Pin,Bit_Mode_t Copy_Config);

GPIO_STATUS_t GPIO_GetPinReading(PORT_t Copy_Port,PIN_t Copy_Pin,u8* Copy_pu8Value);
GPIO_STATUS_t GPIO_GetPortReading(PORT_t Copy_Port,u16* Copy_pu8Value);


GPIO_STATUS_t GPIO_SetPinValue(PORT_t Copy_Port,PIN_t Copy_Pin,u8 Copy_pu8Value);
GPIO_STATUS_t GPIO_SetPortValue(PORT_t Copy_Port,u16 Copy_pu8Value);













#endif /* GPIO_INTERFACE_H_ */
