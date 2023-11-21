/*
 * Secure_Diagnostics_LCD_UART.c
 *
 * Created: 11/20/2023 2:35:01 PM
 * Author : Yomna
 */ 

#include"D:\NTI\Cyber_Security\Embedded_CyberSecurity_NTI\Task5\Secure_Diagnostics_LCD_UART\Secure_Diagnostics_LCD_UART\MCAL\DIO\Inc\dio.h"
#include"D:\NTI\Cyber_Security\Embedded_CyberSecurity_NTI\Task5\Secure_Diagnostics_LCD_UART\Secure_Diagnostics_LCD_UART\HAL\LCD\Inc\lcd.h"
#include"D:\NTI\Cyber_Security\Embedded_CyberSecurity_NTI\Task5\Secure_Diagnostics_LCD_UART\Secure_Diagnostics_LCD_UART\MCAL\UART\Inc\uart.h"
#include<stdlib.h>	
#include<util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#include "D:\NTI\Cyber_Security\Embedded_CyberSecurity_NTI\Task5\Secure_Diagnostics_LCD_UART\Secure_Diagnostics_LCD_UART\Service\ComM\comM_uart.h"
#include "D:\NTI\Cyber_Security\Embedded_CyberSecurity_NTI\Task5\Secure_Diagnostics_LCD_UART\Secure_Diagnostics_LCD_UART\HAL\LED\Inc\led.h"
#include "D:\NTI\Cyber_Security\Embedded_CyberSecurity_NTI\Task5\Secure_Diagnostics_LCD_UART\Secure_Diagnostics_LCD_UART\HAL\LCD\Inc\lcd.h"

#define F_CPU 16000000UL
/************global variable***********/
unsigned char rand_char();

extern u8 rx_buffer[RX_BUFFER_MAX_SIZE];
extern boolean mssg_isReceived ;

extern u8 arr[20][20];
extern u8 arr_index;
extern u8 currnt ;
int secureFlag=0;
int checkkeyflag=1;
int main(void)
{
	unsigned char values[4] = {6,8,2,6} ;
	lcd_vidInit();
	led_init();
	COM_M_init();
	for (int i=0;i<4;i++)
	{
		values[i] = values[i] +'0';
	}
	
	while (1)
	{

		if (msg_isrecieved())
		{
			lcd_vidSendCmd(_LCD_CLEAR);
			mssg_isReceived = FALSE;
			lcd_vidGotoRowColumn(0,0);
			if (rx_buffer[0] == '2' && rx_buffer[1] == '7')
			{
				if (rx_buffer[2] == '0')
				{
					if (rx_buffer[3]=='1')
					{
						lcd_vidDisplyStr("6701");
						lcd_vidDisplyStr(values);
						COM_M_TransmitStr(values);
						checkkeyflag=1;
					}
					else if (rx_buffer[3] == '2')
					{
						int j =0;
						for (int i=4;i<8;i++)
						{
							if (rx_buffer[i] == values[j]+'1'-48)
							{
								secureFlag=1;
							}
							else
							{
								secureFlag=0;
								checkkeyflag=0;
							}
							j++;
						}
						if (secureFlag && checkkeyflag)
						{
							lcd_vidDisplyStr("6702");
						}
						else
						{
							lcd_vidDisplyStr("7F 27 35");
						}
					}
				}
			}
			else if (rx_buffer[0]== '3' && rx_buffer[1] == '1' )
			{
				if (rx_buffer[2]=='0' && rx_buffer[3] == '1' &&rx_buffer[4] == 'A' &&rx_buffer[5] == 'A' && rx_buffer[6] == '0'&& rx_buffer[7] == '0' && secureFlag)
				{
					led_on(LED_YELLOW);
					lcd_vidDisplyStr("7101AA00");
				}
				else
				{
					lcd_vidDisplyStr("7F 31 33");
					led_off(LED_YELLOW);
				}

			}
			else
			{
				lcd_vidDisplyStr("invalid command");
			}
		}
	}
}


unsigned char rand_char() {
	static unsigned char seed = 123; // Initial seed value (can be any non-zero value)
	const unsigned char a = 166; // Multiplier
	const unsigned char c = 1;   // Increment
	const unsigned char m = 251; // Modulus

	seed = (a * seed + c) % m;
	return seed;
}
