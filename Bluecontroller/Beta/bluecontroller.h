/*
 * bluecontroller.h
 *
 * Created: 30.11.2012
 *  Program: Atmel Studio 6
 *  Author: Fabi Rosenthal
 *  Licence: CC BY 3.0 (http://creativecommons.org/licenses/by/3.0/)
 *  Code: http://github.com/Xennis/Bluecontroller_BCA8_BTM
 *  Documentation: http://wiki.xennis.de/artikel/Bluecontroller
 */
#ifndef BLUECONTROLLER_H_
	#define BLUECONTROLLER_H_

	/* include */
	#include "uart.h"		// defines F_CPU => important to include before <util/delay.h>
	#include <inttypes.h>
	#include <avr/io.h>
	#include <util/delay.h>

	/* define */
	#define BTM222_RESET		PINB7	// pin for the LED (TODO: ersetzt static_cast<byte>(7), PINB7 oder PORTB7?)
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
	uint8_t bt_check_turn_off(void);
	void bt_turn_off(void);
	void bt_turn_on(void);

#endif /* BLUECONTROLLER_H_ */
