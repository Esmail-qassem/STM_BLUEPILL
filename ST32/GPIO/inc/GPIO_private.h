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
	u32 PIN0 :4;
	u32 PIN1 :4;
	u32 PIN2 :4;
	u32 PIN3 :4;
	u32 PIN4 :4;
	u32 PIN5 :4;
	u32 PIN6 :4;
	u32 PIN7 :4;
};

u32 GPIO_CRL_VARIABLE;
}GPIO_CRL;

typedef union
{
struct
{
	u32 PIN8 :4;
	u32 PIN9 :4;
	u32 PIN10 :4;
	u32 PIN11 :4;
	u32 PIN12 :4;
	u32 PIN13 :4;
	u32 PIN14 :4;
	u32 PIN15 :4;
};
u32 GPIO_CRH_VARIABLE;
}GPIO_CRH;



#endif /* GPIO_PRIVATE_H_ */
