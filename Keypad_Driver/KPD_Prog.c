#include "DIO_TYPES.h"
#include "KPD_conf.h"
#include "DIO_INT.h"
/*************************************************************************************************/
/* Description: Write a Number on the Seven Segments 						 */
/*											    	 */
/* Inputs : Copy_u8PortNB    -> Port No of the desired Seven Segments 			         */
/* 			Copy_u8DisplayNB -> The Number to be Displayed				 */
/* Outputs: u8Error -> Error State								 */
/*												 */

int KPD_Au8ColDefinitions[4]={PIN4,PIN5,PIN6,PIN7};
int KPD_Au8RowDefinitions[4]={PIN0,PIN1,PIN2,PIN3};
void KPD_init(void){
	DIO_SetPinDirection(KPD_PORT,PIN0,INPUT);
	DIO_SetPinDirection(KPD_PORT,PIN1,INPUT);
	DIO_SetPinDirection(KPD_PORT,PIN2,INPUT);
	DIO_SetPinDirection(KPD_PORT,PIN3,INPUT);
	DIO_SetPinValue(KPD_PORT,PIN0,1);
	DIO_SetPinValue(KPD_PORT,PIN1,1);
	DIO_SetPinValue(KPD_PORT,PIN2,1);
	DIO_SetPinValue(KPD_PORT,PIN3,1);
	DIO_SetPinDirection(KPD_PORT,PIN4,OUTPUT);
	DIO_SetPinDirection(KPD_PORT,PIN5,OUTPUT);
	DIO_SetPinDirection(KPD_PORT,PIN6,OUTPUT);
	DIO_SetPinDirection(KPD_PORT,PIN7,OUTPUT);

}

u8 KPD_u8GetKPDKeys(u8 Copy_u8State[KPD_NUMBER_OF_ROWS][KPD_NUMBER_OF_COL]) {
	u8 Local_u8ErrorState = ERROR_OK ;
	for(u8 Col = 0 ; Col < KPD_NUMBER_OF_COL ; Col ++){
		for(u8 setter = 0 ; setter < KPD_NUMBER_OF_COL ; setter ++)
		{
			if( setter == Col )
			{
				DIO_SetPinValue(KPD_PORT,KPD_Au8ColDefinitions[setter] , PRIV_PIN_LOW  ) ;
			}
			else
			{
				DIO_SetPinValue(KPD_PORT,KPD_Au8ColDefinitions[setter] , PRIV_PIN_HIGH ) ;
			}

		}


		for(u8 Row = 0 ; Row < KPD_NUMBER_OF_ROWS ; Row ++)
		{

			Copy_u8State[Col][Row]=DIO_GetPinValue(KPD_PORT,KPD_Au8RowDefinitions[Row]);

		}
	}
	return Local_u8ErrorState ;

}

/*											    	 */
/*											    	 */
/*											    	 */
/*************************************************************************************************/
