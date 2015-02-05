/**
 * @file	uart.c
 * @author	Florian Thaeter, Fabi Rosenthal
 * @version	Epsilon
 * @date	18.05.2013
 *
 * @section LICENSE
 *  Licence: CC BY 3.0 (http://creativecommons.org/licenses/by/3.0/)
 *
 * @section DESCRIPTION
 *  Code: http://github.com/Xennis/Bluecontroller_BCA8_BTM
 *
 *  Documentation: http://xennis.org/wiki/Bluecontroller
 */
#include "uart.h"

/**
 * @brief UART Initialization
 *
 *  USART Initialization (datasheet page 178)
 */
void uart_init( unsigned int ubrr )
{
	/* Set baud rate */
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;
	
	/* Enable double speed */
	UCSRA = (0<<U2X0);
	/* Enable receiver, transmitter and UART RX Complete Interrupt (activate global interrupt flag necessary) */
	UCSRB |= (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
	/* Set frame format: 8data, 1stop bit */
	UCSRC |= (1<<UCSZ01)|(1<<UCSZ00);
	
	/* Dummy read to clear UDR */
	UDR;
}

/**
 * @brief Send char
 *
 *	Sending Frames with 5 to 8 Data Bit (datasheet page 179)
 */
void uart_putc( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE) ) );
	/* Put data into buffer, sends the data */
	UDR = data;
}