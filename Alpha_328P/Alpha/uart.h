/*
 * uart.h
 *
 * Created: 20.11.2012 18:25:59
 *  Author: Fabi
 */ 
#ifndef UART_H_
	#define UART_H_

	/* ATmega328P specific */
	//#ifdef _AVR_IOM328P_H_
	
	/* define */
	#define MCU     atmega328p
	#define F_CPU	8000000UL	// Clock Speed (ATmega328P)
	#define BAUD	19200		// Baud rate (Bluecontroller
	#define MYUBRR	F_CPU/16/BAUD-1

	/* include */
	#include <avr/io.h>
	#include <avr/interrupt.h>	// used for sei(), cli() and ISR()

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

	/* method */
	void uart_init(unsigned int ubrr);
	void uart_timer_init(void);
	void uart_putc(unsigned char data);

#endif /* UART_H_ */