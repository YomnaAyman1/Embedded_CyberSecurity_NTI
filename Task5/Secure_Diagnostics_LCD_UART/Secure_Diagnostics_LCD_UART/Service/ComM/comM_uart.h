/*
 * com_M.h
 *
 * Created: 10/28/2023 
 *  Author: Yomna
 */ 


#ifndef COMM_UART_H_
#define COMM_UART_H_

#include "D:\NTI\Cyber_Security\Embedded_CyberSecurity_NTI\Task5\Secure_Diagnostics_LCD_UART\Secure_Diagnostics_LCD_UART\MCAL\UART\Inc\uart.h"

void COM_M_init(void);
void COM_M_TransmitStr(u8 *str);
boolean msg_isrecieved(void);
void RECEIVE_CALLBACK(void);
void TRANSMIT_CALLBACK(void);


#endif /* COMM_UART_H_ */