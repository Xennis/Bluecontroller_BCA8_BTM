/*
 * uart.h
 *
 * Created: 13.12.2012
 *  Program: Atmel Studio 6
 *  Author: Fabi Rosenthal, Florian Thaeter
 *  Code: http://github.com/Xennis/Bluecontroller_BCA8_BTM
 *  Documentation: http://wiki.xennis.de/artikel/AVR-GCC_-_UART
 */
#include <avr/io.h>
 
#ifndef UART_H_
	#define UART_H_
 
	/* Define */
	#define F_CPU	20000000UL		// Clock Speed = 20.000MHz
	#define BAUD	115200			// Baud rate
	#define UBRR_VAL	((F_CPU+BAUD*8)/(BAUD*16)-1) // = 10
 
	/* Includes */
	#include <avr/io.h>
	#include <util/delay.h>			// Uses defined F_CPU
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
 
 	void uart_init(void);
 	void uart_putc(unsigned char data);
	void uart_puts(char *s);
 
#endif /* UART_H_ */