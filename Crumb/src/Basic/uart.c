/*
 * uart.c
 *
 * Created: 13.12.2012
 *  Program: Atmel Studio 6
 *  Author: Fabi Rosenthal, Florian T.
 *  Licence: CC BY 3.0 (http://creativecommons.org/licenses/by/3.0/)
 *  Code: http://github.com/Xennis/Bluecontroller_BCA8_BTM
 *  Documentation: http://wiki.xennis.de/artikel/AVR-GCC_-_UART
 */
#include "uart.h"
 
/* 
 * USART Initialization (Datasheet page 178)
 */
void uart_init( void )
{
	/* Set baud rate */
	UBRRH = UBRR_VAL >> 8;
	UBRRL = UBRR_VAL & 0xFF;
	/* Enable receiver and transmitter */
	UCSRB |= (1<<TXEN0);
	/* Set frame format: 8data, 2stop bit (USBS0) */
	UCSRC |= (1<<USBS0)|(3<<UCSZ00);
}
 
/*
 * Sending Frames with 5 to 8 Data Bit (Datasheet page 179)
 */
void uart_putc( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) );
	/* Put data into buffer, sends the data */
	UDR = data;
}
 
/*
 * Sending strings
 */
void uart_puts( char *s )
{
	/* while *s != '\0' so unequally "string-end characters (terminator) */
	while (*s)
	{
		uart_putc(*s);
		s++;
	}
}
