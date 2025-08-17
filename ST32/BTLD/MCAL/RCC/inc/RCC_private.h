/***********************************************************************/
/*Aauthor     : Esamil Qassem                                          */
/*Data        : 18 Nov 2023                                            */
/*SWC         : RCC                                                    */
/*Version     : V.1                                                    */
/***********************************************************************/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_



typedef struct
{
	    u32 HSION:1;     /* Internal high-speed clock enable*/
		u32 HSIRDY:1;    /* Internal high-speed clock ready flag*/
		u32 :1;
		u32 HSITRIM:5;   /*Internal high-speed clock trimming*/
		u32 HSICAL:8;    /*Internal high-speed clock calibration*/
		u32 HSEON:1;     /*HSE clock enable*/
		u32 HSERDY:1;    /*External high-speed clock ready flag*/
		u32 HSEBYP:1;    /*External high-speed clock bypass*/
		u32 CSSON:1;     /*Clock security system enable*/
		u32 :4;
		u32 PLLON:1;     /*PLL enable*/
		u32 PLLRDY:1;    /*PLL clock ready flag*/
		u32 :6;


}RCC_CR;


typedef enum {
	PLL_x2=0b0000,
	PLL_x3=0b0001,
	PLL_x4=0b0010,
	PLL_x5=0b0011,
	PLL_x6=0b0100,
	PLL_x7=0b0101,
	PLL_x8=0b0110,
	PLL_x9=0b0111,
	PLL_x10=0b1000,
	PLL_x11=0b1001,
	PLL_x12=0b1010,
	PLL_x13=0b1011,
	PLL_x14=0b1100,
	PLL_x15=0b1101,
	PLL_x16=0b1110,
	PLL_x16_2=0b1111,
}MULTI_FACTOR;
/**********************************************/
typedef struct
{
	    u32 SW:2;
		u32 SWS:2;
		u32 HPRE:4;
		u32 PPRE1:3;
		u32 PPRE2:3;
		u32 ADCPRE:2;
		u32 PLLSRC:1;
		u32 PLLXTRPE:1;
		u32 PLLMUL:4;
		u32 USBPRE:1;
		u32 :1;
		u32 MCO:3;
		u32 :5;

}RCC_CFGR;





typedef struct {
	u32 LSIRDYF:1;
	u32 LSERDYF:1;
	u32 HSIRDYF:1;
	u32 HSERDYF:1;
	u32 PLLRDYF:1;
	u32 :2;
	u32 CSSF:1;
	u32 LSIRDYIE:1;
	u32 LSERDYIE:1;
	u32 HSIRDYIE:1;
	u32 HSERDYIE:1;
	u32 PLLRDYIE:1;
	u32 :3;
	u32 LSIRDYC:1;
	u32 LSERDYC:1;
	u32 HSIRDYC:1;
	u32 HSERDYC:1;
	u32 PLLRDYC:1;
	u32 :2;
	u32 CSSC:1;
	u32:8;
}RCC_CIR;



typedef struct {
	u32 LSEON:1;
	u32 LSERDY:1;
	u32 LSEBYP:1;
	u32 :5;
	u32 RTCSEL:2;
	u32 :5;
	u32 RTCEN:1;
	u32 BDRST:1;
	u32 :15;
}RCC_BDCR;

/***************************************************************/

typedef struct {
	u32 LSION:1;
	u32 LSIRDY:1;
	u32 :22;
	u32 RMVF:1;
	u32 :1;
	u32 PINRSTF:1;
	u32 PORRSTF:1;
	u32 SFTRSTF:1;
	u32 IWDGRSTF:1;
	u32 WWDGRSTF:1;
	u32 LPWRRSTF:1;
}RCC_CSR;

/***************************************************************/

enum RCC_Ability
{
	RCC_Disable,
	RCC_Enable

};
enum RCC_System_Clock
{
	HSI_SELECT_CLOCK=0b00,
	HSE_SELECT_CLOCK=0b01,
	PLL_SELECT_CLOCK=0b10
};

enum HSE_PLL
{
	HSE_NOT_DIVIDED,
	HSE_DIVIDED_BY_2,
};




#define CRC_TIME_OUT 5000

#endif /* RCC_PRIVATE_H_ */
