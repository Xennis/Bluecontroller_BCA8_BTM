/*
 * bluecontroller.h
 *
 *  Author: Fabi
 */ 
#ifndef BLUECONTROLLER_H_
	#define BLUECONTROLLER_H_

	/* include */
	#include <avr/io.h>
	#include "uart.h" // defines F_CPU => important to include before delay.h
	#include <util/delay.h>

	/* define */
	#define BTM222_RESET		PB7		// pin for the LED (ersetzt static_cast<byte>(7))
	#define BTM222_RESETPORT	PORTB	// port for the LED
	#define BTM222_RESETPIN		PINB
	#define BTM222_RESETDDR		DDRB

	/* method */
	void bt_init(void);
	void bt_setut(void);
	void bt_reset(void);
	void bt_escape_sequence(void);
	void bt_putc(char c);
	void bt_puts(char* s);
	void bt_send_cmd(char* s);

#endif /* BLUECONTROLLER_H_ */
