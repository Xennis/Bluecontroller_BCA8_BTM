/*
 * uart.c
 *
 * Created: 06.12.2012
 *  Program: Atmel Studio 6
 *  Author: Fabi Rosenthal, Florian T.
 *  Licence: CC BY 3.0 (http://creativecommons.org/licenses/by/3.0/)
 *  Code: http://github.com/Xennis/Bluecontroller_BCA8_BTM
 *  Documentation: http://wiki.xennis.de/artikel/Bluecontroller
 */
#include "uart.h"

/* 
 * USART Initialization (Datasheet page 178)
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
}

/*
 * Sending Frames with 5 to 8 Data Bit (Datasheet page 179)
 */
void uart_putc( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE) ) );
	/* Put data into buffer, sends the data */
	UDR = data;
}

/*
 * Timer Initialization
 */
void uart_timer_init( void ) {
	DDRD |= (1<<DDD6) | (1<<DDD5);
	// normale 8-bit PWM aktivieren (nicht invertiert),
	// Das Bit WGM10 wird im Datenblatt auch als PWM10 bezeichnet
	TCCR0A = (1<<COM0A0)|(1<<COM0A1)|(1<<COM0B0)|(1<<COM0B1)|(1<<WGM00);

	// Einstellen der PWM-Frequenz auf 14 kHz (Prescaler = 1)
	TCCR0B = (1<<CS00);
	TCNT0 = 255;
	OCR0A = 255;
	OCR0B = 235;
	// Interrupts für Timer1 deaktivieren
	// Achtung: Auch die Interrupts für die anderen Timer stehen in diesem Register
	// TIMSK &= ~0x3c;
}