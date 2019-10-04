/*
 * EXTI_conf.h
 *
 *  Created on: Sep 20, 2019
 *      Author: Marina
 */

#ifndef EXTI_CONF_H_
#define EXTI_CONF_H_

void EXTI_EnableGIE(void);
void EXTI_DisableGIE(void);
void EXTI_EnablePIE(u8 Init);
void EXTI_DisablePIE(u8 Init);
void Event_Type(u8 INT_NO,u8 Type);
void EXTI_init(void);

#endif /* EXTI_CONF_H_ */
