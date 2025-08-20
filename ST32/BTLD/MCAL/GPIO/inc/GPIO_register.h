/***********************************************************************/
/*Aauthor     : Esamil Qassem                                          */
/*Data        : 11 JAN 2024                                            */
/*SWC         : GPIO                                                    */
/*Version     : V.1                                                    */
/***********************************************************************/
#ifndef GPIO_REGISTER_H_
#define GPIO_REGISTER_H_

#define GPIO_PORTA_BASE_ADD  0x40010800
#define GPIO_PORTB_BASE_ADD  0x40010C00
#define GPIO_PORTC_BASE_ADD  0x40011000


/***************************************************************************/

#define GPIOA_CRL_Reg     ((volatile GPIO_CRL*)GPIO_PORTA_BASE_ADD)

#define GPIOB_CRL_Reg     ((volatile GPIO_CRL*)GPIO_PORTB_BASE_ADD)

#define GPIOC_CRL_Reg     ((volatile GPIO_CRL*)GPIO_PORTC_BASE_ADD)



#define GPIOA_CRH_Reg     ((volatile GPIO_CRH*)(GPIO_PORTA_BASE_ADD+0x04))

#define GPIOB_CRH_Reg     ((volatile GPIO_CRH*)(GPIO_PORTB_BASE_ADD+0x04))

#define GPIOC_CRH_Reg     ((volatile GPIO_CRH*)(GPIO_PORTC_BASE_ADD+0x04))

/***************************************************************************/
/*Port input data register*/


#define GPIOA_IDR    *((volatile uint32*)(GPIO_PORTA_BASE_ADD+0x08))
#define GPIOB_IDR    *((volatile uint32*)(GPIO_PORTB_BASE_ADD+0x08))
#define GPIOC_IDR    *((volatile uint32*)(GPIO_PORTC_BASE_ADD+0x08))


/******************************************************************************/

#define GPIOA_ODR    *((volatile uint32*)(GPIO_PORTA_BASE_ADD+0x0C))
#define GPIOB_ODR    *((volatile uint32*)(GPIO_PORTB_BASE_ADD+0x0C))

/*********************************************************************/
#define GPIOA_BSRR   *((volatile uint32*)(GPIO_PORTA_BASE_ADD+0x10))
#define GPIOB_BSRR   *((volatile uint32*)(GPIO_PORTB_BASE_ADD+0x10))
#define GPIOC_BSRR   *((volatile uint32*)(GPIO_PORTC_BASE_ADD+0x10))

/******************************************************************************/
#define GPIOA_BRR   *((volatile uint32*)(GPIO_PORTA_BASE_ADD+0x14))
#define GPIOB_BRR   *((volatile uint32*)(GPIO_PORTB_BASE_ADD+0x14))
#define GPIOC_BRR   *((volatile uint32*)(GPIO_PORTC_BASE_ADD+0x14))

#endif /* GPIO_REGISTER_H_ */
