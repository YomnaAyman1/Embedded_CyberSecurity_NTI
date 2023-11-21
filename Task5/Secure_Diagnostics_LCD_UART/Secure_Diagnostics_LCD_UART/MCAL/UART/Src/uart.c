 /**************************************************
 *  File		: Uart.c
 *	Module		: UART
 *	Target		: ATMEGA32
 *	Author		: Yomna
 *  Description	:
 *
 ***************************************************/
#include "D:\NTI\Cyber_Security\Embedded_CyberSecurity_NTI\Task5\Secure_Diagnostics_LCD_UART\Secure_Diagnostics_LCD_UART\MCAL\UART\Inc\uart.h"
#include <avr/interrupt.h>

static volatile void (*ptr_rx_callback)(void) = NULL;
static volatile void (*ptr_tx_callback)(void) = NULL;

u8 tx_buffer[TX_BUFFER_MAX_SIZE];
u8 rx_buffer[RX_BUFFER_MAX_SIZE];

u8 tx_index =0;
u8 rx_index =0;

volatile boolean mssg_isReceived = FALSE;

void UART_Init(u16 baudRate)
{
	SET_BIT(SREG ,7);
	/* Set baud rate */
	UART_UBRRH_REG = (u8)(baudRate>>8);
	UART_UBRRL_REG = (u8)baudRate;
	/* Enable receiver and transmitter */
	SET_BIT(UART_UCSRB_REG,RXEN_BIT_NO);  /* Enable Receiver*/
	SET_BIT(UART_UCSRB_REG,TXEN_BIT_NO);  /* Enable Transmitter */
	/* Set frame format: 8data, 1stop bit, Even Parity */
	UART_UCSRC_REG |= (1 << URSEL_BIT_NO)|UART_8_BIT_DATA | UART_EVEN_PARITY;

	
	/*	Enable Rx complete	*/
	SET_BIT(UART_UCSRB_REG,RXC_BIT_NO);
	/*	Enable Tx complete	*/
	SET_BIT(UART_UCSRB_REG,TXC_BIT_NO);
}

void UART_TransmitChr(u8 data)
{
	
	/* Wait for empty transmit buffer */
	UART_UDR_REG = data;
//	while (!(CHECK_BIT(UART_UCSRA_REG,UDRE_BIT_NO)))
//			
	/* Put data into buffer, sends the data */
	
}

u8 UART_ReceiveChr(void)
{
	/* Wait for data to be received */
//	while (!(CHECK_BIT(UART_UCSRA_REG,RXC_BIT_NO)))
//			;
	/* Get and return received data from buffer */
	return UART_UDR_REG;
}

void UART_TransmitStrPoll(u8 str[])
{
	while (*str != '\0')
	{
		UART_TransmitChr(*str);
		str++;
	}
}

void UART_TransmitStr(u8 *str)
{
	u8 i=0;
	/*	copy str into global tx buffer	*/
	for (i=0; i < TX_BUFFER_MAX_SIZE; i++)
	{
		tx_buffer[i] = str[i];
	}
	UART_TransmitChr(tx_buffer[tx_index]);
}

void uart_Receive_SetCallback(void (*uart_ptr)(void))
{
	ptr_rx_callback = uart_ptr;
}

void uart_Transmit_SetCallback(void (*uart_ptr)(void))
{
	ptr_tx_callback = uart_ptr;
}


ISR(USART_TXC_vect)
{
	if (ptr_tx_callback != NULL)
	{
		ptr_tx_callback();
	}
	/**/
}


ISR(USART_RXC_vect)
{
		if (ptr_rx_callback != NULL)
		{
			ptr_rx_callback();
		}
	
}