/*
 * EXTI_priv.h
 *
 *  Created on: Sep 20, 2019
 *      Author: Marina
 */

#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_

#define SREG_Register  *((volatile u8*)0x5F)
#define GICR_Register  *((volatile u8*)0x5B)
#define MCUCR_Register  *((volatile u8*)0x55)
#define MCUCSR_Register  *((volatile u8*)0x54)


//steps of interrupt::
//1-Enable GIE -->SREG
//2-Enable PIE -->GICR
//3-define event type
#endif /* EXTI_PRIV_H_ */
