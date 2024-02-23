/***********************************************************************/
/*Aauthor     : Esamil Qassem                                          */
/*Data        : 3 FEB 2024                                             */
/*SWC         : NVIC                                                   */
/*Version     : V.1                                                    */
/***********************************************************************/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

typedef enum
{
	NVIC_OK,
	NVIC_NOK
}NVIC_Status_t;


NVIC_Status_t NVIC_EnableInterrupt(u8 Copy_u8Peripheral);
NVIC_Status_t NVIC_DisableInterrupt(u8 Copy_u8Peripheral);

NVIC_Status_t NVIC_SetPendingFlag(u8 Copy_u8Peripheral);
NVIC_Status_t NVIC_ClearPendingFlag(u8 Copy_u8Peripheral);

NVIC_Status_t NVIC_GetActiveInterrupt(u8 Copy_u8Peripheral,u8 * Copy_pvPeripheral);

void NVIC_SetPriority(s8 Copy_S8PriorityId,u8 Copy_u8GroupPriority,u8 Copy_u8SubGroupPriority);


#endif /* INC_NVIC_INTERFACE_H_ */
