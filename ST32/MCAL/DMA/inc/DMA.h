#ifndef DMA_H_
#define DMA_H_
#include "STD_TYPES.h"

// DMA1 and DMA2 Registers
#define DMA_ISR(base)   (*(volatile u32 *)((base) + 0x00)) // Interrupt Status Register
#define DMA_IFCR(base)  (*(volatile u32 *)((base) + 0x04)) // Interrupt Flag Clear Register

// DMA Channel Registers
#define DMA_CCR(base, ch)    (*(volatile u32 *)((base) + 0x08 + (ch - 1) * 0x14))
#define DMA_CNDTR(base, ch)  (*(volatile u32 *)((base) + 0x0C + (ch - 1) * 0x14))
#define DMA_CPAR(base, ch)   (*(volatile u32 *)((base) + 0x10 + (ch - 1) * 0x14))
#define DMA_CMAR(base, ch)   (*(volatile u32 *)((base) + 0x14 + (ch - 1) * 0x14))

// Interrupt Status Register (ISR) Bits
#define DMA_ISR_GIF1    (1 << 0)  // Global Interrupt Flag for Channel 1
#define DMA_ISR_TCIF1   (1 << 1)  // Transfer Complete Interrupt Flag for Channel 1
#define DMA_ISR_HTIF1   (1 << 2)  // Half Transfer Interrupt Flag for Channel 1
#define DMA_ISR_TEIF1   (1 << 3)  // Transfer Error Interrupt Flag for Channel 1
#define DMA_ISR_TCIF5 (1 << 17)
// Interrupt Flag Clear Register (IFCR) Bits
#define DMA_IFCR_CGIF1  (1 << 0)  // Clear Global Interrupt Flag for Channel 1
#define DMA_IFCR_CTCIF1 (1 << 1)  // Clear Transfer Complete Interrupt Flag for Channel 1
#define DMA_IFCR_CHTIF1 (1 << 2)  // Clear Half Transfer Interrupt Flag for Channel 1
#define DMA_IFCR_CTEIF1 (1 << 3)  // Clear Transfer Error Interrupt Flag for Channel 1

// DMA Channel Configuration Register (CCR) Bits
#define DMA_CCR_EN      (1 << 0)  // Channel Enable
#define DMA_CCR_TCIE    (1 << 1)  // Transfer Complete Interrupt Enable
#define DMA_CCR_HTIE    (1 << 2)  // Half Transfer Interrupt Enable
#define DMA_CCR_TEIE    (1 << 3)  // Transfer Error Interrupt Enable
#define DMA_CCR_DIR     (1 << 4)  // Data Transfer Direction (1: Memory to Peripheral, 0: Peripheral to Memory)
#define DMA_CCR_CIRC    (1 << 5)  // Circular Mode Enable
#define DMA_CCR_PINC    (1 << 6)  // Peripheral Increment Mode
#define DMA_CCR_MINC    (1 << 7)  // Memory Increment Mode
#define DMA_CCR_PSIZE_8BIT  (0 << 8)  // Peripheral Size: 8-bit
#define DMA_CCR_PSIZE_16BIT (1 << 8)  // Peripheral Size: 16-bit
#define DMA_CCR_PSIZE_32BIT (2 << 8)  // Peripheral Size: 32-bit
#define DMA_CCR_MSIZE_8BIT  (0 << 10) // Memory Size: 8-bit
#define DMA_CCR_MSIZE_16BIT (1 << 10) // Memory Size: 16-bit
#define DMA_CCR_MSIZE_32BIT (2 << 10) // Memory Size: 32-bit
#define DMA_CCR_PL_LOW      (0 << 12) // Priority Level: Low
#define DMA_CCR_PL_MEDIUM   (1 << 12) // Priority Level: Medium
#define DMA_CCR_PL_HIGH     (2 << 12) // Priority Level: High
#define DMA_CCR_PL_VHIGH    (3 << 12) // Priority Level: Very High
#define DMA_CCR_MEM2MEM     (1 << 14) // Memory-to-Memory Mode Enable


typedef enum {
    // USART Peripherals
    PERIPH_USART1_TX  = 0x40013804,
    PERIPH_USART1_RX  = 0x40013800,
    PERIPH_USART2_TX  = 0x40004404,
    PERIPH_USART2_RX  = 0x40004400,
    PERIPH_USART3_TX  = 0x40004804,
    PERIPH_USART3_RX  = 0x40004800,

    // SPI Peripherals
    PERIPH_SPI1_TX    = 0x4001300C,
    PERIPH_SPI1_RX    = 0x40013008,
    PERIPH_SPI2_TX    = 0x4000380C,
    PERIPH_SPI2_RX    = 0x40003808,

    // I2C Peripherals
    PERIPH_I2C1_TX    = 0x40005410,
    PERIPH_I2C1_RX    = 0x40005410,
    PERIPH_I2C2_TX    = 0x40005810,
    PERIPH_I2C2_RX    = 0x40005810,

    // ADC Peripherals
    PERIPH_ADC1       = 0x4001244C,
    PERIPH_ADC2       = 0x4001284C,

    // TIM Peripherals
    PERIPH_TIM1_CH1   = 0x40012C34,
    PERIPH_TIM1_CH2   = 0x40012C38,
    PERIPH_TIM1_CH3   = 0x40012C3C,
    PERIPH_TIM1_CH4   = 0x40012C40,
    PERIPH_TIM2_CH1   = 0x40000034,
    PERIPH_TIM2_CH2   = 0x40000038,
    PERIPH_TIM2_CH3   = 0x4000003C,
    PERIPH_TIM2_CH4   = 0x40000040,
    PERIPH_TIM3_CH1   = 0x40000434,
    PERIPH_TIM3_CH2   = 0x40000438,
    PERIPH_TIM3_CH3   = 0x4000043C,
    PERIPH_TIM3_CH4   = 0x40000440,
    PERIPH_TIM4_CH1   = 0x40000834,
    PERIPH_TIM4_CH2   = 0x40000838,
    PERIPH_TIM4_CH3   = 0x4000083C,
    PERIPH_TIM4_CH4   = 0x40000840,

    // DAC Peripherals
    PERIPH_DAC_CH1    = 0x40007408,
    PERIPH_DAC_CH2    = 0x40007414
} DMA_Peripheral_t;



typedef enum
{
 DMA1_BASE  =     (0x40020000UL),
 DMA2_BASE   =    (0x40020400UL)

}DMA_REG;
typedef enum
{
DMA_Channel1=1 ,
DMA_Channel2 ,
DMA_Channel3 ,
DMA_Channel4 ,
DMA_Channel5 ,
DMA_Channel6 , 
DMA_Channel7 ,
}DMA_Channel;

void DMA_Init(DMA_REG dmaBase, DMA_Channel channel, DMA_Peripheral_t peripheral, u32 *memoryAddr, u32 dataSize) ;




#endif // DMA_REGISTERS_H




