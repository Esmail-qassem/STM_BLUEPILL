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
#define  PLL
/*********************************/

#ifdef PLL
#define HSI /*write the clock source*/
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
#define PLL_MULT_FACTOR PLL_x9

#ifdef HSE
/*
 *HSE_NOT_DIVIDED
 *HSE_DIVIDED_BY_2
 * */
#define HSE_SOURCE  HSE_NOT_DIVIDED
#endif
#endif



/*
	APB2_HCLK_NO_DIVIDER 
	APB2_HCLK_DIVIDE_BY_2
	APB2_HCLK_DIVIDE_BY_4
	APB2_HCLK_DIVIDE_BY_8
	APB2_HCLK_DIVIDE_BY_16

bits to not exceed 36 MHz on this domain
    APB1_HCLK_NO_DIVIDER 
	APB1_HCLK_DIVIDE_BY_2
	APB1_HCLK_DIVIDE_BY_4
	APB1_HCLK_DIVIDE_BY_8
	APB1_HCLK_DIVIDE_BY_16

	AHB_SYSCLK_NO_DIVIDER 
	AHB_SYSCLK_DIVIDE_BY_2
	AHB_SYSCLK_DIVIDE_BY_4
	AHB_SYSCLK_DIVIDE_BY_8
	AHB_SYSCLK_DIVIDE_BY_16
	AHB_SYSCLK_DIVIDE_BY_64
	AHB_SYSCLK_DIVIDE_BY_128
	AHB_SYSCLK_DIVIDE_BY_256
	AHB_SYSCLK_DIVIDE_BY_512
*/



#define APB2_DIVIDER APB2_HCLK_NO_DIVIDER 
#define APB1_DIVIDER APB1_HCLK_NO_DIVIDER
#define AHB_DIVIDER  AHB_SYSCLK_NO_DIVIDER

/**************************************************************/

/*RCC_Disable
 * RCC_Enable
 * */

#define CLOCK_SECURITY   RCC_Disable


#endif /* RCC_CONFIG_H_ */
