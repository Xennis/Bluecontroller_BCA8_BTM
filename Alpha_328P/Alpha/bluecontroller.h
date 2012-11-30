/*
 * bluecontroller.h
 *
 *  Author: Fabi
 */ 
#ifndef BLUECONTROLLER_H_
	#define BLUECONTROLLER_H_

	/* include */
	#include "uart.h" // defines F_CPU => important to include before delay.h
	#include <inttypes.h>  // not needed
	#include <avr/io.h>
	#include <util/delay.h>

	/* define */
	#define BTM222_RESET		PINB7		// pin for the LED (ersetzt static_cast<byte>(7))
	#define BTM222_RESET_PORT	PORTB	// port for the LED
	#define BTM222_RESET_PIN	PINB
	#define BTM222_RESET_DDR	DDRB

	/* method */
	void bt_init(void);
	void bt_setut(void);
	void bt_reset(void);
	void bt_escape_sequence(void);
	void bt_putc(char c);
	void bt_puts(char* s);
	void bt_send_cmd(char* s);

#endif /* BLUECONTROLLER_H_ */
