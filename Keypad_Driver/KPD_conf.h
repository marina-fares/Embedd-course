/*
 * KPD_conf.h
 *
 *  Created on: Aug 30, 2019
 *      Author: Marina
 */
#include "DIO_INT.h"
#ifndef KPD_CONF_H_
#define KPD_CONF_H_
#define KPD_NUMBER_OF_ROWS 4
#define KPD_NUMBER_OF_COL 4
#define PRIV_PIN_LOW 0
#define PRIV_PIN_HIGH 1
#define ERROR_OK 1
#define KPD_REL 1
#define KPD_PRS 0
u8 KPD_u8GetKPDKeys(u8 Copy_u8State[KPD_NUMBER_OF_ROWS][KPD_NUMBER_OF_COL]);
void KPD_init(void);
#define KPD_PORT PORTA
#endif /* KPD_CONF_H_ */
