/*
 * LCD_INT.c
 *
 *  Created on: Aug 24, 2019
 *      Author: Marina
 */

#include "DIO_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "LCD_INT.h"
#include "DIO_INT.h"
#include "LCD_conf.h"
void LCD_init(void)
{
	DIO_SetPortDirection(DATA_PORT,OUTPUT);
	DIO_SetPortDirection(CONTROL_PORT,OUTPUT);
	writeCom(FUN_SET);//function set
	_delay_ms(2);
	writeCom(DISPLAY);//display
	_delay_ms(2);
	writeCom(CLEAR);//clear diplay
	_delay_ms(2);
}
void writeCom(u8 input1)
{
	DIO_SetPinValue(RS_PORT,RS_PIN,LOW);
	DIO_SetPinValue(RW_PORT,RW_PIN,LOW);
	DIO_SetPinValue(EN_PORT,EN_PIN,LOW);
	DIO_SetPortValue(PORTC,input1);
	DIO_SetPinValue(EN_PORT,EN_PIN,HIGH);
	_delay_ms(2);
	DIO_SetPinValue(EN_PORT,EN_PIN,LOW);
	_delay_ms(2);
}

void writeData(u8 input1)
{
	DIO_SetPinValue(RS_PORT,RS_PIN,HIGH);
	DIO_SetPinValue(RW_PORT,RW_PIN,LOW);
	DIO_SetPinValue(EN_PORT,EN_PIN,LOW);
	DIO_SetPortValue(DATA_PORT,input1);
	DIO_SetPinValue(EN_PORT,EN_PIN,HIGH);
	_delay_ms(2);
	DIO_SetPinValue(EN_PORT,EN_PIN,LOW);
	_delay_ms(2);
}
void setAdd(u8 x,u8 y)
{
	u8 add=x+(y<<6);
	add |=0x80;
	writeCom(add);//set address
}

void clearScrean(void){
	_delay_ms(2);
	writeCom(0x01);
	_delay_ms(2);
};
void writeString(u8 *str){
	u8 i=0;
	while(str[i]!='\0')
	{
		writeData(str[i]);
		i++;
	}
}
void writeStringAdd(u8 *str,u8 x,u8 y){
	setAdd(x,y);
	u8 i=0;
	while(str[i]!='\0')
	{
		writeData(str[i]);
		i++;
	}
}
