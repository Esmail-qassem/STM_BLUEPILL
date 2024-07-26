
#define NULL 0

typedef unsigned int uint32_t;

extern uint32_t _estack, _etext, _sdata, _edata, _sbss, _ebss,_sidata;

extern void main(void);

void Reset_Handler                     (void);
void NMI_Handler                       (void) __attribute__ ((alias ("Default_Handler")));
void HardFault_Handler                 (void) __attribute__ ((alias ("Default_Handler")));
void MemManage_Handler                 (void) __attribute__ ((alias ("Default_Handler")));
void BusFault_Handler                  (void) __attribute__ ((alias ("Default_Handler")));
void UsageFault_Handler                (void) __attribute__ ((alias ("Default_Handler")));
void SVC_Handler                       (void) __attribute__ ((alias ("Default_Handler")));
void DebugMon_Handler                  (void) __attribute__ ((alias ("Default_Handler")));
void PendSV_Handler                    (void) __attribute__ ((alias ("Default_Handler")));
void SysTick_Handler                   (void) ;
void WWDG_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));                                        
void PVD_IRQHandler                    (void) __attribute__ ((alias ("Default_Handler")));
void TAMP_STAMP_IRQHandler             (void) __attribute__ ((alias ("Default_Handler")));
void RTC_WKUP_IRQHandler               (void) __attribute__ ((alias ("Default_Handler")));
void FLASH_IRQHandler                  (void) __attribute__ ((alias ("Default_Handler"))); 
void RCC_IRQHandler                    (void) __attribute__ ((alias ("Default_Handler")));   
void EXTI0_IRQHandler                  (void);
void EXTI1_IRQHandler                  (void);
void EXTI2_IRQHandler                  (void);
void EXTI3_IRQHandler                  (void);
void EXTI4_IRQHandler                  (void);
void DMA1_Channel1_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void DMA1_Channel2_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void DMA1_Channel3_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void DMA1_Channel4_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void DMA1_Channel5_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void DMA1_Channel6_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void DMA1_Channel7_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void ADC_1_2_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void USB_HP_CAN_TX_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void USB_LP_CAN_RX0_IRQHandler         (void) __attribute__ ((alias ("Default_Handler")));
void CAN_RX1_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void CAN_SCE_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void EXTI9_5_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void TIM1_BRK_IRQHandler               (void) __attribute__ ((alias ("Default_Handler")));
void TIM1_UP_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void TIM1_TRG_COM_IRQHandler           (void) __attribute__ ((alias ("Default_Handler")));
void TIM1_CC_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void TIM2_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void TIM3_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void TIM4_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void I2C1_EV_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void I2C1_ER_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void I2C2_EV_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void I2C2_ER_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void SPI1_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void SPI2_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void USART1_IRQHandler                 (void);
void USART2_IRQHandler                 (void);
void USART3_IRQHandler                 (void);
void EXTI15_10_IRQHandler              (void) __attribute__ ((alias ("Default_Handler")));
void RTCAlarm_IRQHandler               (void) __attribute__ ((alias ("Default_Handler")));
void TIM8_BRK_IRQHandler               (void) __attribute__ ((alias ("Default_Handler")));
void TIM8_UP_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void TIM8_TRG_COM_IRQHandler           (void) __attribute__ ((alias ("Default_Handler")));
void TIM8_CC_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void ADC3_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void FSMC_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void SDIO_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void TIM5_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void SPI3_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void UART4_IRQHandler                  (void) __attribute__ ((alias ("Default_Handler")));
void UART5_IRQHandler                  (void) __attribute__ ((alias ("Default_Handler")));
void TIM6_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void TIM7_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void DMA2_Channel1_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void DMA2_Channel2_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void DMA2_Channel3_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void DMA2_Channel4_5_IRQHandler        (void) __attribute__ ((alias ("Default_Handler")));


uint32_t * const MSP_Value = (uint32_t *)&_estack;

/* Vector table for a Cortex M3, using the attribute here to define a section in rom called isr_vector*/
uint32_t *Vector_Table[] __attribute__ ((section (".isr_vector"))) =
 {
    (uint32_t *)MSP_Value,                          /* Main Stack Pointer */
    (uint32_t *)Reset_Handler,                     /* Reset */
    (uint32_t *)NMI_Handler,                       /* Non maskable interrupt */
    (uint32_t *)HardFault_Handler,                 /* All class of fault */
    (uint32_t *)MemManage_Handler,                 /* Memory management */
    (uint32_t *)BusFault_Handler,                  /* Pre-fetch fault, memory access fault */ 
    (uint32_t *)UsageFault_Handler,                /* Undefined instruction or illegal state */
    0,
    0,
    0,
    0,
    (uint32_t *)SVC_Handler,                       /* System service call via SWI instruction */
    (uint32_t *)DebugMon_Handler,                  /* Debug Monitor */
    0,
    (uint32_t *)PendSV_Handler,                    /* Pendable request for system service */ 
    (uint32_t *)SysTick_Handler,
    (uint32_t *)WWDG_IRQHandler,                   /* Window WatchDog              */                                        
    (uint32_t *)PVD_IRQHandler,                    /* PVD through EXTI Line detection */                        
    (uint32_t *)TAMP_STAMP_IRQHandler,             /* Tamper and TimeStamps through the EXTI line */            
    (uint32_t *)RTC_WKUP_IRQHandler,               /* RTC Wakeup through the EXTI line */                      
    (uint32_t *)FLASH_IRQHandler,                  /* FLASH                        */                                          
    (uint32_t *)RCC_IRQHandler,                    /* RCC                          */                                            
    (uint32_t *)EXTI0_IRQHandler,                  /* EXTI Line0                   */                        
    (uint32_t *)EXTI1_IRQHandler,                  /* EXTI Line1                   */                          
    (uint32_t *)EXTI2_IRQHandler,                  /* EXTI Line2                   */                          
    (uint32_t *)EXTI3_IRQHandler,                  /* EXTI Line3                   */                          
    (uint32_t *)EXTI4_IRQHandler,                  /* EXTI Line4                   */                          
    (uint32_t *) DMA1_Channel1_IRQHandler,         
    (uint32_t *)DMA1_Channel2_IRQHandler,          
    (uint32_t *)DMA1_Channel3_IRQHandler,         
    (uint32_t *)DMA1_Channel4_IRQHandler,         
    (uint32_t *)DMA1_Channel5_IRQHandler,         
    (uint32_t *)DMA1_Channel6_IRQHandler,         
    (uint32_t *)DMA1_Channel7_IRQHandler,         
    (uint32_t *)ADC_1_2_IRQHandler      ,         
    (uint32_t *)USB_HP_CAN_TX_IRQHandler,         
    (uint32_t *)USB_LP_CAN_RX0_IRQHandler,        
    (uint32_t *)CAN_RX1_IRQHandler      ,         
    (uint32_t *)CAN_SCE_IRQHandler      ,         
    (uint32_t *)EXTI9_5_IRQHandler      ,         
    (uint32_t *)TIM1_BRK_IRQHandler     ,         
    (uint32_t *)TIM1_UP_IRQHandler      ,         
    (uint32_t *)TIM1_TRG_COM_IRQHandler ,         
    (uint32_t *)TIM1_CC_IRQHandler      ,         
    (uint32_t *)TIM2_IRQHandler         ,         
    (uint32_t *)TIM3_IRQHandler         ,         
    (uint32_t *)TIM4_IRQHandler         ,         
    (uint32_t *)I2C1_EV_IRQHandler      ,         
    (uint32_t *)I2C1_ER_IRQHandler      ,         
    (uint32_t *)I2C2_EV_IRQHandler      ,         
    (uint32_t *)I2C2_ER_IRQHandler      ,         
    (uint32_t *)SPI1_IRQHandler         ,         
    (uint32_t *)SPI2_IRQHandler         ,         
    (uint32_t *)USART1_IRQHandler       ,         
    (uint32_t *)USART2_IRQHandler       ,         
    (uint32_t *)USART3_IRQHandler       ,         
    (uint32_t *)EXTI15_10_IRQHandler    ,         
    (uint32_t *)RTCAlarm_IRQHandler     ,         
    (uint32_t *)0                       ,         
    (uint32_t *)TIM8_BRK_IRQHandler     ,         
    (uint32_t *)TIM8_UP_IRQHandler      ,         
    (uint32_t *)TIM8_TRG_COM_IRQHandler ,         
    (uint32_t *)TIM8_CC_IRQHandler      ,         
    (uint32_t *)ADC3_IRQHandler         ,         
    (uint32_t *)FSMC_IRQHandler         ,         
    (uint32_t *)SDIO_IRQHandler         ,         
    (uint32_t *)TIM5_IRQHandler         ,         
    (uint32_t *)SPI3_IRQHandler         ,         
    (uint32_t *)UART4_IRQHandler        ,         
    (uint32_t *)UART5_IRQHandler        ,         
    (uint32_t *)TIM6_IRQHandler         ,         
    (uint32_t *)TIM7_IRQHandler         ,         
    (uint32_t *)DMA2_Channel1_IRQHandler,         
    (uint32_t *)DMA2_Channel2_IRQHandler,         
    (uint32_t *)DMA2_Channel3_IRQHandler,         
    (uint32_t *)DMA2_Channel4_5_IRQHandler      
};

static void System_Intitialization(void)
{
    /* Clock intitialization */
}

void Reset_Handler(void)
{
    uint32_t Section_Size = NULL;
    uint32_t *MemSourceAddr = NULL;
    uint32_t *MemDestAddr = NULL;

    /* 1) Copy the data segment initializers from flash to SRAM */
    Section_Size = &_edata - &_sdata;  /* Length of .data segment */
    MemSourceAddr = (uint32_t *)&_sidata;  /* Start address of .data sengement (LMA) -> Load Memory Address */
    MemDestAddr = (uint32_t *)&_sdata;     /* Start address of .data sengement (VMA) -> Virtual Memory Address */
    
    for(uint32_t MemCounter = 0; MemCounter < Section_Size; MemCounter++){
        *MemDestAddr++ = *MemSourceAddr++;
    }

	/* 2) Initialize the .bss segment with zero */
     Section_Size = &_ebss- &_sbss;        /* Length of .bss segment */
     MemDestAddr = (uint32_t *)&_sbss;     /* Start address of .bss sengement */

    for(uint32_t MemCounter = 0; MemCounter < Section_Size; MemCounter++){
        *MemDestAddr++ = 0;
    }

	/* 3) Call the system intitialization function */
    System_Intitialization(); 

/* 4) Call the main function */
    main();
}

void Default_Handler(void)
{

}
