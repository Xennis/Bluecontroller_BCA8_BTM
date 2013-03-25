/**
 * @file	bluecontroller.h
 * @author	Fabi Rosenthal
 * @version	Epsilon
 * @date	25.03.2013
 *
 * @section LICENSE 
 *  Licence: CC BY 3.0 (http://creativecommons.org/licenses/by/3.0/)
 *
 * @section DESCRIPTION
 *  Code: http://github.com/Xennis/Bluecontroller_BCA8_BTM
 *
 *  Documentation: http://wiki.xennis.de/artikel/Bluecontroller
 */
#ifndef BLUECONTROLLER_H_
	#define BLUECONTROLLER_H_

	/* Include */
	#include "uart.h"		// Defines F_CPU => important to include before <util/delay.h>
	#include <inttypes.h>
	#include <avr/io.h>
	#include <util/delay.h>

	/* Define (BC=Bluecontroller) */
	
	/** PIN 19 (PB6): LED */
	#define BC_PIN_LED		PINB6 
	/** PIN 20 (PB7): BT-Reset */
	#define BC_PIN_RESET	PINB7
	#define BC_RESET_PORT	PORTB
	#define BC_RESET_PIN	PINB
	#define BC_RESET_DDR	DDRB
	/** Delay (in ms) after send a char */
	#define BC_PUTC_DELAY	10
	/** Activate bt_debug method */
	#define BC_DEBUG

	/* Method */
	void bt_init(void);
	void bt_setut(void);
	void bt_reset(void);
	void bt_turn_off(void);
	void bt_turn_on(void);
	void bt_escape_sequence(void);
	void bt_putc(char c);
	void bt_puts(char* s);
	void bt_send_cmd(char* s);
	//uint8_t bt_check_turn_off(void);
	void bt_debug(char* s);
	void bt_led_on(uint8_t i);

#endif /* BLUECONTROLLER_H_ */
