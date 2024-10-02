/***********************************************************************/
/*Aauthor     : Esamil Qassem                                          */
/*Data        : 11 JAN 2024                                            */
/*SWC         : GPIO                                                    */
/*Version     : V.1                                                    */
/***********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_register.h"
#include "GPIO_config.h"

GPIO_STATUS_t GPIO_SetPinConfig(PORT_t Copy_Port,PIN_t Copy_Pin,Bit_Mode_t Copy_Config)
{
	GPIO_STATUS_t Local_Error_Status=GPIO_ok;
	if(Copy_Port>GPIO_PORTC || Copy_Port<GPIO_PORTA)
	{
		Local_Error_Status=GPIO_Wrong_Port;
	}
	else if(Copy_Pin>PIN15 || Copy_Pin<PIN0)
	{
		Local_Error_Status=GPIO_Wrong_bit;
	}else
	{

		if(Copy_Pin<8)
		{
			switch(Copy_Port)
			{ case GPIO_PORTA : {GPIOA_CRL_Reg->GPIO_CRL_VARIABLE &=~((0b1111)<<(Copy_Pin*4));
		                       	GPIOA_CRL_Reg->GPIO_CRL_VARIABLE |=((Copy_Config)<<(Copy_Pin*4));
		                    		break;
			                     }
			case GPIO_PORTB : {GPIOB_CRL_Reg->GPIO_CRL_VARIABLE &=~((0b1111)<<(Copy_Pin*4));
					                       	GPIOB_CRL_Reg->GPIO_CRL_VARIABLE |=((Copy_Config)<<(Copy_Pin*4));
					                    		break;
						                     }
			case GPIO_PORTC : {GPIOC_CRL_Reg->GPIO_CRL_VARIABLE &=~((0b1111)<<(Copy_Pin*4));
					                       	GPIOC_CRL_Reg->GPIO_CRL_VARIABLE |=((Copy_Config)<<(Copy_Pin*4));
					                    		break;
						                     }
			}
		}
		else if(Copy_Pin>7)
		{
			Copy_Pin=Copy_Pin-8;
			switch(Copy_Port)
			{ case GPIO_PORTA : {GPIOA_CRH_Reg->GPIO_CRH_VARIABLE &=~((0b1111)<<(Copy_Pin*4));
		                       	GPIOA_CRH_Reg->GPIO_CRH_VARIABLE |=((Copy_Config)<<(Copy_Pin*4));
		                    		break;
			                     }
			case GPIO_PORTB : {GPIOB_CRH_Reg->GPIO_CRH_VARIABLE &=~((0b1111)<<(Copy_Pin*4));
					                       	GPIOB_CRH_Reg->GPIO_CRH_VARIABLE |=((Copy_Config)<<(Copy_Pin*4));
					                    		break;
						                     }
			case GPIO_PORTC : {GPIOC_CRH_Reg->GPIO_CRH_VARIABLE &=~((0b1111)<<(Copy_Pin*4));
					                       	GPIOC_CRH_Reg->GPIO_CRH_VARIABLE |=((Copy_Config)<<(Copy_Pin*4));
					                    		break;
						                     }
			}
		}
	}
return Local_Error_Status;
}
GPIO_STATUS_t GPIO_GetPinReading(PORT_t Copy_Port,PIN_t Copy_Pin,u8* Copy_pu8Value)
{
	GPIO_STATUS_t Local_Error_Status=GPIO_ok;
		if(Copy_Port>GPIO_PORTC || Copy_Port<GPIO_PORTA)
		{
			Local_Error_Status=GPIO_Wrong_Port;
		}
		else if(Copy_Pin>PIN15 || Copy_Pin<PIN0)
		{
			Local_Error_Status=GPIO_Wrong_bit;
		}else
		{
			switch(Copy_Port)
			{case GPIO_PORTA :*Copy_pu8Value=GET_BIT(GPIOA_IDR,Copy_Pin);break;
			case GPIO_PORTB :*Copy_pu8Value=GET_BIT(GPIOB_IDR,Copy_Pin);break;
			case GPIO_PORTC :*Copy_pu8Value=GET_BIT(GPIOC_IDR,Copy_Pin);break;
			}
		}
return Local_Error_Status;
}
GPIO_STATUS_t GPIO_GetPortReading(PORT_t Copy_Port,u16* Copy_pu8Value)
{
	GPIO_STATUS_t Local_Error_Status=GPIO_ok;
		if(Copy_Port>GPIO_PORTC || Copy_Port<GPIO_PORTA)
		{
			Local_Error_Status=GPIO_Wrong_Port;
		}
		else
		{
			switch(Copy_Port)
			{case GPIO_PORTA :*Copy_pu8Value=GPIOA_IDR;break;
			case GPIO_PORTB :*Copy_pu8Value=GPIOB_IDR;break;
			case GPIO_PORTC :*Copy_pu8Value=GPIOC_IDR;break;
			}
		}
return Local_Error_Status;
}
GPIO_STATUS_t GPIO_SetPinValue(PORT_t Copy_Port,PIN_t Copy_Pin,u8 Copy_pu8Value)
{
	GPIO_STATUS_t Local_Error_Status=GPIO_ok;
			if(Copy_Port>GPIO_PORTB || Copy_Port<GPIO_PORTA)
			{
				Local_Error_Status=GPIO_Wrong_Port;
			}
			else if(Copy_Pin>PIN15 || Copy_Pin<PIN0)
			{
				Local_Error_Status=GPIO_Wrong_bit;
			}else
			{
				if(GPIO_HIGH == Copy_pu8Value)
				{
					switch(Copy_Port)
							{case GPIO_PORTA: GPIOA_BSRR=(1<<Copy_Pin);break;
							 case GPIO_PORTB :GPIOB_BSRR=(1<<Copy_Pin);break;
							 case GPIO_PORTC :GPIOC_BSRR=(1<<Copy_Pin);break;
							}


				}else if(GPIO_LOW == Copy_pu8Value)
				{
					switch(Copy_Port)
		         {  case GPIO_PORTA:GPIOA_BRR =(1<<Copy_Pin);break;
	            	case GPIO_PORTB :GPIOB_BRR =(1<<Copy_Pin);break;
	                case GPIO_PORTC :GPIOC_BRR =(1<<Copy_Pin);break;
		          }


				}

			}
return Local_Error_Status;
}
GPIO_STATUS_t GPIO_SetPortValue(PORT_t Copy_Port,u16 Copy_pu8Value)
{
	GPIO_STATUS_t Local_Error_Status=GPIO_ok;
			if(Copy_Port>GPIO_PORTB || Copy_Port<GPIO_PORTA)
			{
				Local_Error_Status=GPIO_Wrong_Port;
			}
			else
			{
				switch(Copy_Port)
					{case GPIO_PORTA:GPIOA_ODR=Copy_pu8Value ;break;
					case GPIO_PORTB :GPIOB_ODR=Copy_pu8Value ;break;
					case GPIO_PORTC : break;
					}
			}
return Local_Error_Status;
}

