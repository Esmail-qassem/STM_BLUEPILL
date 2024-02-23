

#ifndef INC_EXTI_PRIVATE_H_
#define INC_EXTI_PRIVATE_H_


static void(*Local0_PvFunction)(void)=NULL;
static void(*Local1_PvFunction)(void)=NULL;
static void(*Local2_PvFunction)(void)=NULL;
static void(*Local3_PvFunction)(void)=NULL;
static void(*Local4_PvFunction)(void)=NULL;

typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
}EXTI;

#endif /* INC_EXTI_PRIVATE_H_ */
