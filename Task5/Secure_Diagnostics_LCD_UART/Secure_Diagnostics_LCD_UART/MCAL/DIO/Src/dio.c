/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  dio.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "D:\NTI\Cyber_Security\Embedded_CyberSecurity_NTI\Task5\Secure_Diagnostics_LCD_UART\Secure_Diagnostics_LCD_UART\MCAL\DIO\Inc\dio.h"


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
* \Syntax          : void dio_vidConfigChannel
						(dio_port_t port, dio_pin_t pin, dio_direction_t direction)        
* \Description     : this service for configuring IO channel                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port 	   -> MC port ID
					 channel   -> MC channel ID
					 direction -> MC channel direction
* \Return value:   : None                            
*******************************************************************************/
void dio_vidConfigChannel(dio_portId_t port, dio_channelId_t channel, dio_direction_t direction)
{
	switch (port)
	{
	case DIO_PORTA:
		if (direction == OUTPUT)
		{
			SET_BIT (DIO_DDRA_REG,channel);
		}
		else
		{
			CLEAR_BIT (DIO_DDRA_REG,channel);
		}
		break;

	case DIO_PORTB:
		if (direction == OUTPUT)
		{
			SET_BIT (DIO_DDRB_REG,channel);
		}
		else
		{
			CLEAR_BIT (DIO_DDRB_REG,channel);
		}
		break;

	case DIO_PORTC:
		if (direction == OUTPUT)
		{
			SET_BIT (DIO_DDRC_REG,channel);
		}
		else
		{
			CLEAR_BIT (DIO_DDRC_REG,channel);
		}
		break;

	case DIO_PORTD:
		if (direction == OUTPUT)
		{
			SET_BIT (DIO_DDRD_REG,channel);
		}
		else
		{
			CLEAR_BIT (DIO_DDRD_REG,channel);
		}
		break;
	}
}

/******************************************************************************
* \Syntax          : void dio_vidWriteChannel
						(dio_portId_t port, dio_channelId_t channel, dio_level_t level)      
* \Description     : this service for writting on IO channel                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port 	  -> MC port ID
					 channel  -> MC channel ID
					 level    -> MC channel level
* \Return value:   : None                            
*******************************************************************************/
void dio_vidWriteChannel(dio_portId_t port, dio_channelId_t channel, dio_level_t level)
{
	switch (port)
	{
	case DIO_PORTA:
		if (level == STD_LOW)
		{
			CLEAR_BIT(DIO_PORTA_REG,channel);
		}
		else
		{
			SET_BIT(DIO_PORTA_REG,channel);
		}
		break;

	case DIO_PORTB:
		if (level == STD_LOW)
		{
			CLEAR_BIT(DIO_PORTB_REG,channel);
		}
		else
		{
			SET_BIT(DIO_PORTB_REG,channel);
		}
		break;

	case DIO_PORTC:
		if (level == STD_LOW)
		{
			CLEAR_BIT(DIO_PORTC_REG,channel);
		}
		else
		{
			SET_BIT(DIO_PORTC_REG,channel);
		}
		break;

	case DIO_PORTD:
		if (level == STD_LOW)
		{
			CLEAR_BIT(DIO_PORTD_REG,channel);
		}
		else
		{
			SET_BIT(DIO_PORTD_REG,channel);
		}
		break;
	}
}

/******************************************************************************
* \Syntax          :void dio_vidWriteChannelGroup
						(dio_portId_t port,u8 value,u8 mask)
* \Description     : this service for writting on group of IO channels                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port  -> MC port ID
					 value -> data value
					 mask  -> data mask
* \Return value:   : None                            
*******************************************************************************/
void dio_vidWriteChannelGroup(dio_portId_t port,u8 value,u8 mask)
{
	/*	show me your code */
	
}

/******************************************************************************
* \Syntax          :void dio_vidFlipChannel
						(dio_portId_t port, dio_channelId_t channel)
* \Description     : this service for fliping IO channel                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port  -> MC port ID
					 channel  -> MC channel ID
* \Return value:   : None                            
*******************************************************************************/
void dio_vidFlipChannel(dio_portId_t port, dio_channelId_t channel)
{
	switch (port)
	{
	case DIO_PORTA:
		FLIP_BIT(DIO_PORTA_REG,channel);
		break;

	case DIO_PORTB:
		FLIP_BIT(DIO_PORTB_REG,channel);
		break;

	case DIO_PORTC:
		FLIP_BIT(DIO_PORTC_REG,channel);
		break;

	case DIO_PORTD:
		FLIP_BIT(DIO_PORTD_REG,channel);
		break;
	}
}

/******************************************************************************
* \Syntax          :dio_level_t Dio_dioLevelReadChannel
						(dio_portId_t port, dio_channelId_t channel)
* \Description     : this service for reading IO channel                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port     -> MC port ID
					 channel  -> MC channel ID
* \Return value:   : loc_pinRead   -> IO channel level                           
*******************************************************************************/
dio_level_t dio_dioLevelReadChannel(dio_portId_t port, dio_channelId_t channel)
{
	/*	show me your code */
	dio_level_t value = STD_LOW;
	switch(port)
	{
		case DIO_PORTA: value = CHECK_BIT(DIO_PINA_REG,channel);
		case DIO_PORTB: value = CHECK_BIT(DIO_PINB_REG,channel);
		case DIO_PORTC: value = CHECK_BIT(DIO_PINC_REG,channel);
		case DIO_PORTD: value = CHECK_BIT(DIO_PIND_REG,channel);
	}
	return value;
}

/******************************************************************************
* \Syntax          :void dio_vidEnablePullUp
						(dio_portId_t port, dio_channelId_t channel)
* \Description     : this service for enabling pull up resistor for IO channel                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port  -> MC port ID
					 channel  -> MC channel ID
* \Return value:   : None                            
*******************************************************************************/
void dio_vidEnablePullUp(dio_portId_t port, dio_channelId_t channel)
{
	/*	show me your code */	
}

/******************************************************************************
* \Syntax          :void dio_vidWritePort	
						(dio_portId_t port,  dio_level_t level)
* \Description     : this service for reading IO port                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port     -> MC port ID
* \Return value:   : None        
/**********************************************************************************/                   

void dio_vidWritePort(dio_portId_t port,  dio_level_t level)
{
	switch (port)
	{
		case DIO_PORTA:
		if (level == STD_LOW)
		{
			DIO_PORTA_REG =0x00;
		}
		else
		{
			DIO_PORTA_REG =0xFF;
		}
		break;

		case DIO_PORTB:
		if (level == STD_LOW)
		{
			DIO_PORTB_REG =0x00;
		}
		else
		{
			DIO_PORTB_REG =0xFF;
		}
		break;

		case DIO_PORTC:
		if (level == STD_LOW)
		{
			DIO_PORTC_REG =0x00;
		}
		else
		{
			DIO_PORTC_REG =0xFF;
		}
		break;

		case DIO_PORTD:
		if (level == STD_LOW)
		{
			DIO_PORTD_REG =0x00;
		}
		else
		{
			DIO_PORTD_REG =0xFF;
		}
		break;
	}
}

/******************************************************************************
* \Syntax          :dio_vidConfigPort
				(dio_portId_t port,  dio_direction_t direction)
* \Description     : this service for configuring port as input or output                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port     -> MC port ID
* \Return value:   : None        
/**********************************************************************************/                   


void dio_vidConfigPort(dio_portId_t port,  dio_direction_t direction)
{
	switch (port)
	{
		case DIO_PORTA:
		if (direction == INPUT)
		{
			DIO_DDRA_REG =0x00;
		}
		else
		{
			DIO_DDRA_REG =0xFF;
		}
		break;

		case DIO_PORTB:
		if (direction == INPUT)
		{
			DIO_DDRB_REG =0x00;
		}
		else
		{
			DIO_DDRB_REG =0xFF;
		}
		break;

		case DIO_PORTC:
		if (direction == INPUT)
		{
			DIO_DDRC_REG =0x00;
		}
		else
		{
			DIO_DDRC_REG =0xFF;
		}
		break;

		case DIO_PORTD:
		if (direction == INPUT)
		{
			DIO_DDRD_REG =0x00;
		}
		else
		{
			DIO_DDRD_REG =0xFF;
		}
		break;
	}
}

/**********************************************************************************************************************
 *  END OF FILE: dio.c
 *********************************************************************************************************************/
