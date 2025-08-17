/***********************************************************************/
/*Aauthor     : Esamil Qassem                                          */
/*Data        : 18 Nov 2023                                            */
/*SWC         : RCC                                                    */
/*Version     : V.1                                                    */
/***********************************************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
#include "RCC_config.h"
#include "RCC_private.h"
#include "RCC_register.h"

typedef enum {
	RCC_OK, RCC_BUS_ERR, RCC_PERIPHERAL_ERR,

} RCC_status;
/************************** APB1 ENABLE******************************/

typedef enum {
	APB1_TIM2EN,
	APB1_TIM3EN,
	APB1_TIM4EN,
	APB1_TIM5EN,
	APB1_TIM6EN,
	APB1_TIM7EN,
	APB1_TIM12EN,
	APB1_TIM13EN,
	APB1_TIM14EN,
	APB1_WWDGEN = 11,
	APB1_SPI2EN = 14,
	APB1_SPI3EN,
	APB1_USART2EN = 17,
	APB1_USART3EN,
	APB1_UART4EN,
	APB1_UART5EN,
	APB1_I2C1EN,
	APB1_I2C2EN,
	APB1_USBEN,
	APB1_CANEN = 25,
	APB1_BKPEN = 27,
	APB1_PWREN,
	APB1_DACEN,

	APB2_AFIOEN = 0,
	APB2_GPIOAEN = 2,
	APB2_GPIOBEN,
	APB2_GPIOCEN,
	APB2_GPIODEN,
	APB2_GPIOEEN,
	APB2_GPIOFEN,
	APB2_GPIOGEN,
	APB2_ADC1EN,
	APB2_ADC2EN,
	APB2_TIM1EN,
	APB2_SPI1EN,
	APB2_TIM8EN,
	APB2_USART1EN,
	APB2_ADC3EN,
	APB2_TIM9EN = 19,
	APB2_TIM10EN,
	APB2_TIM11EN,

	AHB_DMA1EN = 0,
	AHB_DMA2EN,
	AHB_SRAMEN,
	AHB_FLITFEN = 4,
	AHB_CRCEN = 6,
	AHB_FSMCEN = 8,
	AHB_SDIOEN = 10

} Bus_EnPeripheral_t;
/***************************************************************************/

/********************************** APB1 RESTART *******************************/

typedef enum {
	APB1_TIM2RST,
	APB1_TIM3RST,
	APB1_TIM4RST,
	APB1_TIM5RST,
	APB1_TIM6RST,
	APB1_TIM7RST,
	APB1_TIM12RST,
	APB1_TIM13RST,
	APB1_TIM14RST,
	APB1_WWDGRST = 11,
	APB1_SPI2RST = 14,
	APB1_SPI3RST,
	APB1_USART2RST = 17,
	APB1_USART3RST,
	APB1_UART4RST,
	APB1_UART5RST,
	APB1_I2C1RST,
	APB1_I2C2RST,
	APB1_USBRST,
	APB1_CANRST = 25,
	APB1_BKPRST = 27,
	APB1_PWRRST,
	APB1_DACRST,

	APB2_AFIORST=0,
	APB2_GPIOARST = 2,
	APB2_GPIOBRST,
	APB2_GPIOCRST,
	APB2_GPIODRST,
	APB2_GPIOERST,
	APB2_GPIOFRST,
	APB2_GPIOGRST,
	APB2_ADC1RST,
	APB2_ADC2RST,
	APB2_TIM1RST,
	APB2_SPI1RST,
	APB2_TIM8RST,
	APB2_USART1RST,
	APB2_ADC3RST,
	APB2_TIM9RST = 19,
	APB2_TIM10RST,
	APB2_TIM11RST
} Bus_RestPeripheral_t;
/***************************************************************************/
typedef enum {
	AHB_BUS, APB1_BUS, APB2_BUS

} RCC_BUS_t;

void RCC_VidInit(void);
RCC_status RCC_voidEnablePeripheral(RCC_BUS_t Copy_Bus, Bus_EnPeripheral_t Copy_u8Peripheral);
RCC_status RCC_voidDisablePeripheral(RCC_BUS_t Copy_Bus, Bus_EnPeripheral_t Copy_u8Peripheral);
RCC_status RCC_voidResetPeripheral(RCC_BUS_t Copy_Bus,Bus_RestPeripheral_t Copy_u8Peripheral);

#endif /* RCC_INTERFACE_H_ */
