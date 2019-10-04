/*
 * EXTI_prog.c
 *
 *  Created on: Sep 20, 2019
 *      Author: Marina
 */

#ifndef EXTI_PROG_C_
#define EXTI_PROG_C_
#include "BIT_MATH.h"
#include "DIO_TYPES.h"
#include "EXTI_priv.h"
#include "EXTI_INT.h"
#include "EXTI_conf.h"
void EXTI_EnableGIE(void){
	SET_BIT(SREG_Register,7);
}
void EXTI_DisableGIE(void)
{
	CLR_BIT(SREG_Register,7);
}
void EXTI_EnablePIE(u8 Init)
{
	SET_BIT(GICR_Register,Init);
}
void EXTI_DisablePIE(u8 Init)
{
	CLR_BIT(GICR_Register,Init);
}
void Event_Type(u8 INT_NO,u8 Type)
{
	if((INT_NO==INT0)||(INT_NO==INT0))
	{
		MCUCR_Register |=(Type<<INT_NO);
		MCUCR_Register &=~(Type<<INT_NO);
	}
	else{
		switch(Type){
			case FALLING:
				CLR_BIT(MCUCSR_Register,6);
				break;
			case RISING:
				SET_BIT(MCUCSR_Register,6);
				break;
			}
	}
}
void EXTI_init(void){

}

#endif /* EXTI_PROG_C_ */
