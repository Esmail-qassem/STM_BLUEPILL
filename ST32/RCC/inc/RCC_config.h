/***********************************************************************/
/*Aauthor     : Esamil Qassem                                          */
/*Data        : 18 Nov 2023                                            */
/*SWC         : RCC                                                    */
/*Version     : V.1                                                    */
/***********************************************************************/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_
/* RCC CLOCK TYPE	*/
/* HSI
 * HSE
 * PLL
 *--if you will choose PLL so makr another define with the selected
 * clock source---.
 * */
#define  HSI
/*********************************/

#ifdef PLL
#define HSE /*write the clock source*/
#endif

/*************************** HSE ********************************/
/*************************** HSE ********************************/
#ifdef  HSE
/*BYPASS_RCC
 *BYPASS_CRYSTAL
 */
#define BYPASS_CRYSTAL
#endif
/***************************** PLL *************************/
/* to use the pLL you should select a clock source for the PLL*/
#ifdef PLL
/*PLL_x2
 *PLL_x3
 *PLL_x4
 *PLL_x5
 *PLL_x6
 *PLL_x7
 *PLL_x8
 *PLL_x9
 *PLL_x10
 *PLL_x11
 *PLL_x12
 *PLL_x13
 *PLL_x14
 *PLL_x15
 *PLL_x16
 *PLL_x16*/
#define PLL_MULT_FACTOR PLL_x2

#ifdef HSE
/*
 *HSE_NOT_DIVIDED
 *HSE_DIVIDED_BY_2
 * */
#define HSE_SOURCE  HSE_NOT_DIVIDED
#endif
#endif
/**************************************************************/

/*RCC_Disable
 * RCC_Enable
 * */

#define CLOCK_SECURITY   RCC_Disable


#endif /* RCC_CONFIG_H_ */
