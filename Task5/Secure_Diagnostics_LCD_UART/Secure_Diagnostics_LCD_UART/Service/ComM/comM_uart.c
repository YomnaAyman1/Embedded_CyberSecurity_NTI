/*
 * com_M.c
 *
 * Created: 10/28/2023 
 *  Author: Yomna
 */ 
#include "comM_uart.h"
#include <stdio.h>

extern u8 tx_buffer[TX_BUFFER_MAX_SIZE];
extern u8 rx_buffer[RX_BUFFER_MAX_SIZE];

u8 arr[20][20];
u8 arr_index = 0;
u8 currnt = 0;

extern u8 tx_index ;
extern u8 rx_index ;
extern volatile boolean mssg_isReceived;

void COM_M_init(void)
{
  UART_Init(UART_BAUDRATE_9600);
  uart_Receive_SetCallback(RECEIVE_CALLBACK);
  uart_Transmit_SetCallback(TRANSMIT_CALLBACK);
	
}

void COM_M_TransmitStr(u8 *str)
{
	u8 i=0;
	/*	copy str into global tx buffer	*/
	for (i=0; i < TX_BUFFER_MAX_SIZE; i++)
	{
		arr[arr_index][i] = str[i];
	}
	arr_index++;
	if((currnt<=arr_index) && arr[currnt][0] != '\0' ){
			UART_TransmitChr(arr[currnt][tx_index]);

		
		//check if buffer not empty
		if((CHECK_BIT(UART_UCSRA_REG,UDRE_BIT_NO))){
			
		}
		else{
			UART_TransmitChr(arr[currnt][tx_index]);
		}
	}
	else
	{
		UART_TransmitStr("error");
	}
	
}

boolean msg_isrecieved(void)
{
	return mssg_isReceived;
}


void TRANSMIT_CALLBACK(void)
{
	tx_index++;
	
	if (
	(arr[currnt][tx_index] != '\0') &&
	(tx_index < TX_BUFFER_MAX_SIZE)
	)
	{
		UART_TransmitChr(arr[currnt][tx_index]);
	}
	else
	{
		tx_index=0;
		currnt++;
	}
}

void RECEIVE_CALLBACK(void)
{
	volatile u8 loc_byte=0;
	loc_byte = UART_ReceiveChr();
	
	if (loc_byte != '\r')
	{
		rx_buffer[rx_index] = loc_byte;
		rx_index++;
	}
	else
	{
		rx_buffer[rx_index] = '\0';
		rx_index=0;
		mssg_isReceived = TRUE;
	}
	
}
