/*
 * bluecontroller.c
 *
 * This file uses methods, which are Copyright (c) by Michael Dreher
 * Source: http://code.google.com/r/michaeldreher42-bluecontroller/source/browse/bluecontroller/examples/Setup_BlueController/Setup_BlueController.pde
 */ 
#include "bluecontroller.h"
#include "uart.h"

/*
 * Initialization
 */
void bt_init(void)
{
	uart_init();
	_delay_ms(100);
}

/*
 * Setup bluecontroller
 */
void bt_setut()
{
  // [...]
  bt_reset();
  _delay_ms(6000); //wait until the bt module is up and running
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
 * Send escape sequence (+++).
 */
void bt_escape_sequence(void)
{
  _delay_ms(1200);
  bt_puts("+++");
  _delay_ms(1200);  
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
 * Send a bluetooth command string (char*).
 */
void bt_puts(char* s)
{
  /* while *s != '\0' so unequally "string-end characters" (terminator) */
  while(*s)
  {
    bt_putc(*(s++));
  }
}

/*
 * Send a bluetooth command character.
 */
void bt_putc(char c)
{
  uart_putc(c);
  /* Slow down communcation for BTM-22 */
  _delay_ms(50); 
}









//#define BTM222RESET static_cast<byte>(7)  // select the pin for the LED
#define BTM222RESET 111 // ??? ersetzt dieses static_cast<byte>(7)
#define BTM222RESETPORT PORTB // select the port for the LED
#define BTM222RESETPIN PINB
#define BTM222RESETDDR DDRB

// reset the bluetooth module
// this terminates the current bluetooth connection so it is not necessary to
// terminate it manually from the Android phone
void bt_reset(void)
{
  BTM222RESETDDR |= _BV(BTM222RESET);
  BTM222RESETPORT &= ~_BV(BTM222RESET);
  _delay_ms(50);
  BTM222RESETPORT |= _BV(BTM222RESET);
  BTM222RESETDDR &= ~_BV(BTM222RESET);
}

