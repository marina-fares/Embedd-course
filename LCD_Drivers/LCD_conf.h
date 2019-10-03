/*
 * LCD_conf.h
 *
 *  Created on: Aug 30, 2019
 *      Author: Marina
 */

#ifndef LCD_CONF_H_
#define LCD_CONF_H_

#define RS_PIN PIN0
#define RS_PORT PORTB

#define RW_PIN PIN1
#define RW_PORT PORTB

#define EN_PIN PIN2
#define EN_PORT PORTB

#define DATA_PORT PORTC
#define CONTROL_PORT PORTB

#define Col_pos 0
#define Row_Pos 0

#define FUN_SET 0b00111000
#define DISPLAY 0b00001111
#define CLEAR 0b00000001


#endif
/* LCD_CONF_H_ */

