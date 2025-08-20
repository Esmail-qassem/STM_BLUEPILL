#ifndef FPEC_H_
#define FPEC_H_
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#define FPEC_ADD  0x00



typedef union
{
	struct{
		uint32  PG    :1 ;
		uint32  PER   :1 ;
		uint32  MER   :1 ;
		uint32  RES1  :1 ;
		uint32  OPTPG :1 ;
		uint32  OPTER :1 ;
		uint32  STRT  :1 ;
		uint32  LOCK  :1 ;
		uint32  RES2  :1 ;
		uint32  OPTWRE:1 ;
		uint32  ERRIE :1 ;
		uint32  RES3  :1 ;
		uint32  EOPIE :1 ;
		uint32  RES4  :19;
	}BitAccess;
	
	uint32 WordAccess;
}FPEC_CR_TYPE;

#define FLASH_CR   ((volatile FPEC_CR_TYPE*)(FPEC_ADD+0x10))

typedef struct
{
	volatile uint32 ACR;
	volatile uint32 KEYR;
	volatile uint32 OPTKEYR;
	volatile uint32 SR;
	volatile uint32 CR;
	volatile uint32 AR;
	volatile uint32 RESERVED;
	volatile uint32 OBR;
	volatile uint32 WRPR;
}FPEC_TYPE;

#define FPEC_Reg ((volatile FPEC_TYPE*)0x40022000)





void FPEC_voidEraseAppArea(void);
	
void FPEC_voidFlashPageErase(uint8 Copy_uint8PageNumber);

void FPEC_voidFlashWrite(uint32 Copy_uint32Address, uint16* Copy_uint16Data, uint8 Copy_uint8Length);












#endif