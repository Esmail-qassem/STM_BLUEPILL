

#ifndef INC_EXTI_PRIVATE_H_
#define INC_EXTI_PRIVATE_H_


static void(*Local0_PvFunction)(void)=NULL;
static void(*Local1_PvFunction)(void)=NULL;
static void(*Local2_PvFunction)(void)=NULL;
static void(*Local3_PvFunction)(void)=NULL;
static void(*Local4_PvFunction)(void)=NULL;

typedef struct
{
	volatile uint32 IMR;
	volatile uint32 EMR;
	volatile uint32 RTSR;
	volatile uint32 FTSR;
	volatile uint32 SWIER;
	volatile uint32 PR;
}EXTI;

#endif /* INC_EXTI_PRIVATE_H_ */
