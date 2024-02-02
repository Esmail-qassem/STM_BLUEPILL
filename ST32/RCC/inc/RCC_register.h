/***********************************************************************/
/*Aauthor     : Esamil Qassem                                          */
/*Data        : 18 Nov 2023                                            */
/*SWC         : RCC                                                    */
/*Version     : V.1                                                    */
/***********************************************************************/
#ifndef RCC_REGISTER_H_
#define RCC_REGISTER_H_

#define RCC_BASE_ADD  0x40021000

/***************************************************************/

#define RCC_CR_Reg         ((volatile RCC_CR* )RCC_BASE_ADD)

/***************************************************************/

#define RCC_CFGR_Reg       ((volatile RCC_CFGR* )(RCC_BASE_ADD+0x04))

/***************************************************************/

#define RCC_CIR_REG        ((volatile RCC_CIR*)(RCC_BASE_ADD+0x08))


/***************************************************************/

#define RCC_CSR_REG        ((volatile RCC_CSR*)(RCC_BASE_ADD+0x24))

/***************************************************************/
#define RCC_BDCR_REG        ((volatile RCC_BDCR*)(RCC_BASE_ADD+0x20))

/***************************************************************/
#define RCC_APB2RSTR_REG    *((volatile u32*)(RCC_BASE_ADD+0x0C))

/***************************************************************/
#define RCC_APB1RSTR_REG    *((volatile u32*)(RCC_BASE_ADD+0x10))

/***************************************************************/
#define RCC_AHBENR_REG     *((volatile u32*)(RCC_BASE_ADD+0x14))

/***************************************************************/
#define RCC_APB2ENR_REG    *((volatile u32*)(RCC_BASE_ADD+0x18))

/***************************************************************/
#define RCC_APB1ENR_REG     *((volatile u32*)(RCC_BASE_ADD+0x1C))

/***************************************************************/

#endif /* RCC_REGISTER_H_ */
