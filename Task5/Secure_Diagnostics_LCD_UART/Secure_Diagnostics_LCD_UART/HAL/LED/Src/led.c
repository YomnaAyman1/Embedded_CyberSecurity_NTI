/*
 * led.c
 *
 * Created: 10/20/2023 3:34:55 PM
 *  Author: khaled waleed
 */ 
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  led.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "D:\NTI\Cyber_Security\Embedded_CyberSecurity_NTI\Task5\Secure_Diagnostics_LCD_UART\Secure_Diagnostics_LCD_UART\HAL\LED\Inc\led.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void led_init();        
* \Description     : set all led pins to output                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : void                                                                        
* \Return value:   : void  
*                                                                      
*******************************************************************************/
void led_init()
{
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN4,OUTPUT);  //green led
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN5,OUTPUT);  //blue led
	dio_vidConfigChannel(DIO_PORTA,DIO_PIN6,OUTPUT);  //yellow led
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN7,OUTPUT);  //red led
	
}

/******************************************************************************
* \Syntax          : void led_on(led_id_t ledId);
* \Description     : turn specified led on
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : ledId (desired pin)
* \Return value:   : void
*
*******************************************************************************/
void led_on(led_id_t ledId)
{
	switch (ledId)
	{
		case LED_RED:
		SET_BIT(DIO_PORTB_REG,DIO_PIN7);
		break;

		case LED_GREEN:
		SET_BIT(DIO_PORTA_REG,DIO_PIN4);
		break;

		case LED_BLUE:
		SET_BIT(DIO_PORTA_REG,DIO_PIN5);
		break;

		case LED_YELLOW:
		SET_BIT(DIO_PORTA_REG,DIO_PIN6);
		break;
	}
	
}

/******************************************************************************
* \Syntax          : void led_off(led_id_t ledId);
* \Description     : shut specified led down
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : ledId (desired pin)
* \Return value:   : void
*
*******************************************************************************/
void led_off(led_id_t ledId)
{
	switch (ledId)
	{
		case LED_RED:
		CLEAR_BIT(DIO_PORTB_REG,DIO_PIN7);
		break;

		case LED_GREEN:
		CLEAR_BIT(DIO_PORTA_REG,DIO_PIN4);
		break;

		case LED_BLUE:
		CLEAR_BIT(DIO_PORTA_REG,DIO_PIN5);
		break;

		case LED_YELLOW:
		CLEAR_BIT(DIO_PORTA_REG,DIO_PIN6);
		break;
	}
	
}

/******************************************************************************
* \Syntax          : void led_toggle(led_id_t ledId);
* \Description     : change led state
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : ledId (desired pin)
* \Return value:   : void
*
*******************************************************************************/
void led_toggle(led_id_t ledId)
{
	switch (ledId)
	{
		case LED_RED:
		FLIP_BIT(DIO_PORTB_REG,DIO_PIN7);
		break;

		case LED_GREEN:
		FLIP_BIT(DIO_PORTA_REG,DIO_PIN4);
		break;

		case LED_BLUE:
		FLIP_BIT(DIO_PORTA_REG,DIO_PIN5);
		break;

		case LED_YELLOW:
		FLIP_BIT(DIO_PORTA_REG,DIO_PIN6);
		break;
	}
	
}
/**********************************************************************************************************************
 *  END OF FILE: led.c
 *********************************************************************************************************************/
