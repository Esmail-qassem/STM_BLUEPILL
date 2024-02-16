

#ifndef INC_EXTI_INTERFACE_H_
#define INC_EXTI_INTERFACE_H_

typedef enum
{
	Line0,Line1,Line2,Line3,Line4,Line5,Line6,Line7,Line8,Line9,Line10,Line11,Line12,Line13,Line14,Line15

}Line_t;

typedef enum
{
	Falling_Edge,
	Rising_Edge,
	On_Change
}Exti_Mode_t;

typedef enum
{
	EXTI_OK,
	EXTI_NOK

}EXTI_Err;
void EXTI_voidInterrupEnable(Line_t Copy_LineId);
void EXTI_voidInterrupDisable(Line_t Copy_LineId);

EXTI_Err EXTI_EnableChangeLineMode(Line_t Copy_LineId,Exti_Mode_t Copy_Mode);
EXTI_Err EXTI_EDisableChangeLineMode(Line_t Copy_LineId,Exti_Mode_t Copy_Mode);

void EXTI_voidSwTrigger(Line_t Copy_LineId);
#endif /* INC_EXTI_INTERFACE_H_ */
