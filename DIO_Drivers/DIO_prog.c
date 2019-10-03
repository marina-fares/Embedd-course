/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#include "DIO_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "DIO_INT.h"
#include "DIO_reg.h"

#define u8 unsigned char

/* IO Pins */
void DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy)
{
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if(u8PinDirCopy==OUTPUT)
	{
		switch(u8PortIdCopy)
		{
		case PORTA:
			SET_BIT(DDRA_Register,u8PinIdCopy);
			break;
		case PORTB:
			SET_BIT(DDRB_Register,u8PinIdCopy);
			break;
		case PORTC:
			SET_BIT(DDRC_Register,u8PinIdCopy);
			break;
		case PORTD:
			SET_BIT(DDRD_Register,u8PinIdCopy);
			break;
		}
	}
	else
	{
	switch(u8PinDirCopy==INPUT)
		{
		case PORTA:
			CLR_BIT(DDRA_Register,u8PinIdCopy);
			break;
		case PORTB:
			CLR_BIT(DDRB_Register,u8PinIdCopy);
			break;
		case PORTC:
			CLR_BIT(DDRC_Register,u8PinIdCopy);
			break;
		case PORTD:
			CLR_BIT(DDRD_Register,u8PinIdCopy);
			break;
		}
	}

}

void DIO_SetPinValue(u8 u8PortIdCopy ,u8 u8PinIdCopy,u8 u8PinValCopy)

{
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if(u8PinValCopy==HIGH)
	{
		switch(u8PortIdCopy)
		{
		case PORTA:
			SET_BIT(PORTA_Register,u8PinIdCopy);
			break;
		case PORTB:
			SET_BIT(PORTB_Register,u8PinIdCopy);
			break;
		case PORTC:
			SET_BIT(PORTC_Register,u8PinIdCopy);
			break;
		case PORTD:
			SET_BIT(PORTD_Register,u8PinIdCopy);
			break;
		}
	}
	else
	{
	switch(u8PortIdCopy)
		{
		case PORTA:
			CLR_BIT(PORTA_Register,u8PinIdCopy);
			break;
		case PORTB:
			CLR_BIT(PORTB_Register,u8PinIdCopy);
			break;
		case PORTC:
			CLR_BIT(PORTC_Register,u8PinIdCopy);
			break;
		case PORTD:
			CLR_BIT(PORTD_Register,u8PinIdCopy);
			break;
		}
	}



}

u8 DIO_GetPinValue(u8 u8PortIdCopy ,u8 u8PinIdCopy)
{
	switch(u8PortIdCopy)
	{
	case PORTA:
		return GET_BIT(PINA_Register,u8PinIdCopy);
		break;
	case PORTB:
			return GET_BIT(PINB_Register,u8PinIdCopy);
			break;
	case PORTC:
			return GET_BIT(PINC_Register,u8PinIdCopy);
			break;
	case PORTD:
			return GET_BIT(PIND_Register,u8PinIdCopy);
			break;
	}
}
void DIO_SetPortDirection(u8 PortId,u8 PortDir)
{
	if(PortDir==OUTPUT)
	{
		switch(PortId)
		{
		case PORTA:
			DDRA_Register=0XFF;
			break;
		case PORTB:
			DDRB_Register=0XFF;
			break;
		case PORTC:
			DDRC_Register=0XFF;
			break;
		case PORTD:
			DDRD_Register=0XFF;
			break;
		}
	}
	else if(PortDir==INPUT)
		{
			switch(PortId)
			{
			case PORTA:
				DDRA_Register=0X00;
				break;
			case PORTB:
				DDRB_Register=0X00;
				break;
			case PORTC:
				DDRC_Register=0X00;
				break;
			case PORTD:
				DDRD_Register=0X00;
				break;
			}
		}
}
void DIO_SetPortValue(u8 PortId,u8 PortVal)
{

	switch(PortId)
	{
	case PORTA:
		PORTA_Register=PortVal;
		break;
	case PORTB:
		PORTB_Register=PortVal;
		break;
	case PORTC:
		PORTC_Register=PortVal;
		break;
	case PORTD:
		PORTD_Register=PortVal;
		break;
	}
}


