/**
 * @file	uart.h
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
#ifndef UART_H_
	#define UART_H_

	/* Define */
	#define MCU     atmega328p
	/** FOSC / Clock Speed (ATmega328P) */
	#define F_CPU	8000000UL 
	/** Baud rate (Bluecontroller) */
	#define BAUD	19200
	/** MYUBRR = 25 */
	#define MYUBRR	F_CPU/16/BAUD-1

	/* Include */
	#include <avr/io.h>
	#include <avr/interrupt.h>		// Used for sei(), cli() and ISR()

	/* Register names USART0 */
	#define UBRRH	UBRR0H
	#define UBRRL	UBRR0L

	#define UCSRA	UCSR0A
	#define UCSRB	UCSR0B
	#define UCSRC	UCSR0C

	#define UDR		UDR0
	#define UDRE	UDRE0
	#define UPE		UPE0

	#define DOR		DOR0
	#define FE		FE0
	#define RXC		RXC0
	#define TXB8	TXB80

	/* Method */
	void uart_init(unsigned int ubrr);
	void uart_putc(unsigned char data);

#endif /* UART_H_ */