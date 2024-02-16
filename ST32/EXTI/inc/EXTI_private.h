

#ifndef INC_EXTI_PRIVATE_H_
#define INC_EXTI_PRIVATE_H_

typedef struct
{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI;

#endif /* INC_EXTI_PRIVATE_H_ */
