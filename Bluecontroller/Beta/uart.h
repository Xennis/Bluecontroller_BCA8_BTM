/*
 * uart.h
 *
 * Created: 30.11.2012
 *  Program: Atmel Studio 6
 *  Author: Fabi Rosenthal, Florian T.
 *  Licence: CC BY 3.0 (http://creativecommons.org/licenses/by/3.0/)
 *  Documentation: http://wiki.xennis.de/artikel/Bluecontroller
 */
#ifndef UART_H_
	#define UART_H_

	/* ATmega328P specific */
	//#ifdef _AVR_IOM328P_H_
	
	/* Define */
	#define MCU     atmega328p
	#define F_CPU	8000000UL		// FOSC / Clock Speed (ATmega328P)
	#define BAUD	19200			// Baud rate (Bluecontroller)
	#define MYUBRR	F_CPU/16/BAUD-1	// =25

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
	//#endif

	/* Method */
	void uart_init(unsigned int ubrr);
	void uart_timer_init(void);
	void uart_putc(unsigned char data);

#endif /* UART_H_ */