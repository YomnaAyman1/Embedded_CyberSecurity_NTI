/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  dio.h
 *       Module:  dio
 *
 *  Description:  dio APIs     
 *  
 *********************************************************************************************************************/
#ifndef DIO_H_H
#define DIO_H_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "D:\NTI\Cyber_Security\Embedded_CyberSecurity_NTI\Task5\Secure_Diagnostics_LCD_UART\Secure_Diagnostics_LCD_UART\LIB\bit_math.h"
#include "D:\NTI\Cyber_Security\Embedded_CyberSecurity_NTI\Task5\Secure_Diagnostics_LCD_UART\Secure_Diagnostics_LCD_UART\LIB\std_types.h"
#include "D:\NTI\Cyber_Security\Embedded_CyberSecurity_NTI\Task5\Secure_Diagnostics_LCD_UART\Secure_Diagnostics_LCD_UART\MCAL\DIO\Inc\dio_reg.h"
#include "D:\NTI\Cyber_Security\Embedded_CyberSecurity_NTI\Task5\Secure_Diagnostics_LCD_UART\Secure_Diagnostics_LCD_UART\MCAL\DIO\Inc\dio_types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void dio_vidConfigChannel(dio_portId_t port, dio_channelId_t channel, dio_direction_t direction);
void dio_vidWriteChannel(dio_portId_t port, dio_channelId_t channel, dio_level_t level);
void dio_vidWriteChannelGroup(dio_portId_t port,u8 value,u8 mask);
void dio_vidFlipChannel(dio_portId_t port, dio_channelId_t channel);
dio_level_t dio_dioLevelReadChannel(dio_portId_t port, dio_channelId_t channel);
void dio_vidEnablePullUp(dio_portId_t port, dio_channelId_t channel);
void dio_vidConfigPort(dio_portId_t port,  dio_direction_t direction);
void dio_vidWritePort(dio_portId_t port,  dio_level_t level);
 
#endif  /* DIO_H_H */

/**********************************************************************************************************************
 *  END OF FILE: dio.h
 *********************************************************************************************************************/
