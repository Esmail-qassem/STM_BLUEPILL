/*
 * AFIO_private.h
 *
 *  Created on: Feb 16, 2024
 *      Author: s_a_a
 */

#ifndef AFIO_PRIVATE_H_
#define AFIO_PRIVATE_H_








typedef struct
{
   u32 AFIO_EVCR;
   u32 AFIO_MAPR;
   u32 AFIO_EXTICR[4];
   u32 AFIO_MAPR2  ;
}AFIO_t;

#endif /* INC_AFIO_PRIVATE_H_ */
