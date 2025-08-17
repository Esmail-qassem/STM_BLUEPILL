/***********************************************************************/
/*Aauthor     : Esamil Qassem                                          */
/*Data        : 17 Nov 2023                                            */
/*Version     : V.1                                                    */                 
/***********************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef enum
{
	E_Ok,
	E_Not_Ok,
	E_Null_Pointer,
	E_TIME_OUT
}Status_t;

enum Ability
{
	Disable,
	Enable
};
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef float f32;
typedef double f64;
typedef long double f128;
typedef unsigned long long int u128;
typedef signed long long int s128;
#define NULL 0
#endif
