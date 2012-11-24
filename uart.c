/*
 * uart.c
 *
 * Created: 30.10.2012 10:27:18
 * Author: Fabi & Florian
 */ 
#include "uart.h"

/* 
 * USART Initialization (Datasheet page 178)
 */
void uart_init(void)
{
	/* Set baud rate */
	UBRRnH = UBRR_VAL >> 8;
	UBRRnL = UBRR_VAL & 0xFF;
	/* Enable receiver and transmitter */
	//UCSRnB = (1<<RXEN0)|(1<<TXEN0);
	UCSRnB |= (1<<TXEN0);
	/* Set frame format: 8data, 1stop bit */
	UCSRnC = (0<<USBS0)|(3<<UCSZ00);
}

/*
 * Sending Frames with 5 to 8 Data Bit (Datasheet page 179)
 */
void uart_putc( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRnA & (1<<UDREn)) );
	/* Put data into buffer, sends the data */
	UDRn = data;
}
