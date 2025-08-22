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
	    uint32 HSION:1;     /* Internal high-speed clock enable*/
		uint32 HSIRDY:1;    /* Internal high-speed clock ready flag*/
		uint32 :1;
		uint32 HSITRIM:5;   /*Internal high-speed clock trimming*/
		uint32 HSICAL:8;    /*Internal high-speed clock calibration*/
		uint32 HSEON:1;     /*HSE clock enable*/
		uint32 HSERDY:1;    /*External high-speed clock ready flag*/
		uint32 HSEBYP:1;    /*External high-speed clock bypass*/
		uint32 CSSON:1;     /*Clock security system enable*/
		uint32 :4;
		uint32 PLLON:1;     /*PLL enable*/
		uint32 PLLRDY:1;    /*PLL clock ready flag*/
		uint32 :6;


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
	    uint32 SW:2;
		uint32 SWS:2;
		uint32 HPRE:4;
		uint32 PPRE1:3;
		uint32 PPRE2:3;
		uint32 ADCPRE:2;
		uint32 PLLSRC:1;
		uint32 PLLXTRPE:1;
		uint32 PLLMUL:4;
		uint32 USBPRE:1;
		uint32 :1;
		uint32 MCO:3;
		uint32 :5;

}RCC_CFGR;





typedef struct {
	uint32 LSIRDYF:1;
	uint32 LSERDYF:1;
	uint32 HSIRDYF:1;
	uint32 HSERDYF:1;
	uint32 PLLRDYF:1;
	uint32 :2;
	uint32 CSSF:1;
	uint32 LSIRDYIE:1;
	uint32 LSERDYIE:1;
	uint32 HSIRDYIE:1;
	uint32 HSERDYIE:1;
	uint32 PLLRDYIE:1;
	uint32 :3;
	uint32 LSIRDYC:1;
	uint32 LSERDYC:1;
	uint32 HSIRDYC:1;
	uint32 HSERDYC:1;
	uint32 PLLRDYC:1;
	uint32 :2;
	uint32 CSSC:1;
	uint32:8;
}RCC_CIR;



typedef struct {
	uint32 LSEON:1;
	uint32 LSERDY:1;
	uint32 LSEBYP:1;
	uint32 :5;
	uint32 RTCSEL:2;
	uint32 :5;
	uint32 RTCEN:1;
	uint32 BDRST:1;
	uint32 :15;
}RCC_BDCR;

/***************************************************************/

typedef union
{
	struct{
	uint32 LSION:1;
	uint32 LSIRDY:1;
	uint32 :22;
	uint32 RMVF:1;
	uint32 :1;
	uint32 PINRSTF:1;
	uint32 PORRSTF:1;
	uint32 SFTRSTF:1;
	uint32 IWDGRSTF:1;
	uint32 WWDGRSTF:1;
	uint32 LPWRRSTF:1;
	}bits;
	uint32 Reset_Reasone;
}RCC_CSR;

/***************************************************************/


#define RCC_Disable  0
#define RCC_Enable   1


enum RCC_System_Clock
{
	HSI_SELECT_CLOCK=0b00,
	HSE_SELECT_CLOCK=0b01,
	PLL_SELECT_CLOCK=0b10
};


#define	HSE_NOT_DIVIDED   0
#define	HSE_DIVIDED_BY_2  1





#define CRC_TIME_OUT 5000

#endif /* RCC_PRIVATE_H_ */
