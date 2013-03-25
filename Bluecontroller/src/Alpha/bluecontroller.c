/*
 * bluecontroller.c
 *
 * This file uses methods, which are Copyright (c) by Michael Dreher
 * Source: http://code.google.com/r/michaeldreher42-bluecontroller/source/browse/bluecontroller/examples/Setup_BlueController/Setup_BlueController.pde
 *
 * This sketch only works, when __no__ bluetooth connection is established or when the escape sequence is __not__ disabled
 *
 * Additionally this is a demo of new bootloader functions:
 *   soft_reset() (works with optiboot and other bootloaders which clear the wdt and MCUSR)
 *   enter_bootloader() (works only with BlueController optiboot bootloader and magic-word mechanism)
 */ 
#include "bluecontroller.h"

/*
 * Initialization
 */
void bt_init(void)
{
	/* Configure port D */
	DDRD &= ~(1<<DDD2);
	PORTD |= (1<<PORTD2);
	/* Configure port B */
	DDRB |= (1<<DDB7);
	PORTB |= (1<<PORTB7);
	
	/* UART and timer */
	uart_init(MYUBRR);
	sei();
	uart_timer_init();
	_delay_ms(100);
}

/*
 * Setup bluecontroller
 */
void bt_setut(void)
{
	//clear_wdt(); // only necessary without bootloader (which clears wdt and MCUSR) to avoid endless boot loop
	//pinMode(ledPin, OUTPUT);      // sets the digital pin as output
	bt_reset();
	//blinkLed(200);
	//set_btbaudrate(19200); // must match the bootloader setting

	// these setting make the connection as transparent as possible
	bt_send_cmd("\rAT"); // make sure the module is not in sleep mode
	bt_send_cmd("ATE0"); // disable echo
	bt_send_cmd("ATQ1"); // disable result code
	bt_send_cmd("ATC1"); // enable flow control: without this, avrdude under Windows will hang
	bt_send_cmd("ATR1"); // device is slave  
	bt_send_cmd("ATN=BlueController"); // set new name
	bt_send_cmd("ATP=1234"); // set PIN
	bt_send_cmd("ATD0"); // accept connections from any bt device
	bt_send_cmd("ATX0"); // disable escape character (default)
	//bt_send_cmd("ATS1"); // enable powerdown of rs-232 driver (default)
	bt_send_cmd("ATO"); // reconnect to peer

	_delay_ms(1000); // allow module to save setting in flash
	bt_reset(); // activate new settings
}

/*
 * Reset the bluetooth module
 *
 * This terminates the current bluetooth connection.
 */
void bt_reset(void)
{
	BTM222_RESET_DDR |= _BV(BTM222_RESET);
//	DDRB |= 0x10000000; /* PB7 als Ausgang */
	BTM222_RESET_PORT &= ~_BV(BTM222_RESET);
//	PORTB &= 0x01111111; /* PB7 auf 0 */
	_delay_ms(50);
	BTM222_RESET_PORT |= _BV(BTM222_RESET);
//	PORTB |= 0x10000000; /* PB7  auf 1 */
	BTM222_RESET_DDR &= ~_BV(BTM222_RESET);
//	DDRB &= 0x01111111;
	/* Wait until the bt module is up and running */
	_delay_ms(6000);
}

/*
 * Send escape sequence (+++).
 */
void bt_escape_sequence(void)
{
	_delay_ms(1200);
	bt_puts("+++");
	_delay_ms(1200);  
}

/*
 * Send a bluetooth command character.
 */
void bt_putc(char c)
{
	uart_putc(c);
	/* Slow down communcation for BTM-222 */
	_delay_ms(50); 
}

/*
 * Send a bluetooth command string (char*).
 */
void bt_puts(char* s)
{
	/* While *s != '\0' so unequally "string-end characters" (terminator) */
	while(*s)
	{
 		bt_putc(*(s++));
	}
}

/*
 * Send a bluetooth command.
 */
void bt_send_cmd(char* s)
{
	bt_puts(s);
	/* Carriage return at end (ASCII 13) */
	bt_putc('\r');
}



/*
 * Wait and check, if no command to keep it on
 *
 * @return 1 wenn aktiv, 0 wenn nicht aktiv
 */
uint8_t bt_check_turn_off() {
	
	uint8_t      i;
	uint8_t	bt=0;
	DDRB|= (1<<DDB7);
	PORTB|= (1<<PORTB7);
	for (i = 30; i> 1; i--)
	{
		led();
		_delay_ms(1000);
		if ( !(PIND & (1<<PIND2)) ) {
			bt=1;
			i=1;
			//led();
			_delay_ms(250);
			
		}
		
	}
	return bt;
}

void bt_turn_of(void) {
	// if(bt==0) { ...
	PORTB&= ~(1<<PORTB7);
}