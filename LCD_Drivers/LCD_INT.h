///*
// * LCD_INT.H
// *
// *  Created on: Aug 24, 2019
// *      Author: Marina
// */
#ifndef LCD_INT_H_
#define LCD_INT_H_
#include "DIO_TYPES.h"
#include "LCD_conf.h"
#include "LCD_Priv.h"
void LCD_init(void);
void writeCom(u8 input1);
void writeData(u8 input1);
void writeString(u8 *str);
void writeStringAdd(u8 *str,u8 x,u8 y);
void clearScrean(void);
void setAdd(u8 x,u8 y);
#endif /* LCD_INT_H_ */
