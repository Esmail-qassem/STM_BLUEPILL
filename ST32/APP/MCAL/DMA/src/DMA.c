#include "DMA.h"


// Function to initialize DMA for a specific channel and controller
void DMA_Init(DMA_REG dmaBase, DMA_Channel channel, DMA_Peripheral_t peripheral, uint32 *memoryAddr, uint32 dataSize) 
{
    DMA_CCR(dmaBase, channel) &= ~DMA_CCR_EN; // Disable DMA channel before configuration
    DMA_CPAR(dmaBase, channel) = (uint32)peripheral; // Set peripheral address
    DMA_CMAR(dmaBase, channel) = (uint32)memoryAddr; // Set memory address
    DMA_CNDTR(dmaBase, channel) = dataSize; // Set number of data items to transfer
    DMA_CCR(dmaBase, channel) = DMA_CCR_MINC | DMA_CCR_PINC | DMA_CCR_PL_HIGH | DMA_CCR_TCIE; // Configure DMA settings
    DMA_CCR(dmaBase, channel) |= DMA_CCR_EN; // Enable DMA channel
}
