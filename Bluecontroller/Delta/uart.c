/*
 * uart.c
 *
 * Created: 24.03.2013
 *  Program: Atmel Studio 6
 *  Author: Fabi Rosenthal, Florian Thaeter
 *  Licence: CC BY 3.0 (http://creativecommons.org/licenses/by/3.0/)
 *  Code: http://github.com/Xennis/Bluecontroller_BCA8_BTM
 *  Documentation: http://wiki.xennis.de/artikel/Bluecontroller
 */
#include "uart.h"

/* 
 * USART Initialization (datasheet page 178)
 */
void uart_init( unsigned int ubrr )
{
	/* Set baud rate */
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;
	
	/* ... */
	UCSRA = (0<<U2X0);
	/* Enable receiver, transmitter and UART RX Complete Interrupt (activate global interrupt flag necessary) */
	UCSRB |= (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
	/* Set frame format: 8data, 1stop bit */
	UCSRC |= (1<<UCSZ01)|(1<<UCSZ00);
	
	/* Dummy read to clear UDR */
	UDR;
}

/*
 * Sending Frames with 5 to 8 Data Bit (datasheet page 179)
 */
void uart_putc( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE) ) );
	/* Put data into buffer, sends the data */
	UDR = data;
}