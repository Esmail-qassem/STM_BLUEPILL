/***********************************************************************/
/*Aauthor     : Esamil Qassem                                          */
/*Data        : 3 FEB 2024                                             */
/*SWC         : NVIC                                                   */
/*Version     : V.1                                                    */
/***********************************************************************/

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

typedef struct
{
	u32 VECTRESET:1;
	u32 VECTCLRACTIVE:1;
	u32 SYSRESETREQ:1;
	u32:5;
	u32 PRIGROUP :3; /*priority group*/
	u32:4;
	u32 ENDIANESS :1;
	u32 VECTKEY:16;
}NVIC_SCB_AIRCR;

/*number of group priorities and number of sub priorities*/
enum Priority_Grouping
{
	bxxxx=0b011,
	bxxx_y=0b100,
	bxx_yy=0b101,
	bx_yyy=0b110,
	b_yyyy=0b111
};
#endif /* INC_NVIC_PRIVATE_H_ */
