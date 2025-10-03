/***********************************************************************/
/*Aauthor     : Esamil Qassem                                          */
/*Data        : 11 JAN 2024                                            */
/*SWC         : GPIO                                                    */
/*Version     : V.1                                                    */
/***********************************************************************/
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

typedef union
{
struct
{
	uint32 PIN0 :4;
	uint32 PIN1 :4;
	uint32 PIN2 :4;
	uint32 PIN3 :4;
	uint32 PIN4 :4;
	uint32 PIN5 :4;
	uint32 PIN6 :4;
	uint32 PIN7 :4;
};

uint32 GPIO_CRL_VARIABLE;
}GPIO_CRL;

typedef union
{
struct
{
	uint32 PIN8 :4;
	uint32 PIN9 :4;
	uint32 PIN10 :4;
	uint32 PIN11 :4;
	uint32 PIN12 :4;
	uint32 PIN13 :4;
	uint32 PIN14 :4;
	uint32 PIN15 :4;
};
uint32 GPIO_CRH_VARIABLE;
}GPIO_CRH;



#endif /* GPIO_PRIVATE_H_ */
