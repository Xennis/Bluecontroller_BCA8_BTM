/**
 * @file	cmd.c
 * @author	Fabi Rosenthal, Florian Thaeter
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
#include "cmd.h"

/* Global Variables */
volatile char uart_string[UART_MAXSTRLEN + 1] = "";	// Used to store incoming commands
volatile uint8_t uart_str_complete = 0;     		// 1 means complete received
volatile uint8_t uart_str_count = 0;


/**
 * @brief Check commands
 *
 *  This method checks if received command is a valid command and react to it.
 *  Furthermore it resets the commandBuffer.
 */
void checkCmd()
{
	/* Wait for complete command */
	while (uart_str_complete!=1);
	
	char* uart_string_val = (char *) uart_string;
	if(strcmp(uart_string_val, "wusel") == 0) {
		bt_puts("xyz");
	}
	else if(strcmp(uart_string_val, "ledOn") == 0) {
		bt_puts("abc");
		bt_led_on(1);
	}
	else if(strcmp(uart_string_val, "ledOff") == 0) {
		bt_puts("123");
		bt_led_on(0);
	}
	else {
		/* Send invalid command back */
		bt_debug(uart_string_val);
	}

	/* Reset command */
	uart_str_complete = 0;
	sei(); // TODO: necessary?
}

/**
 * @brief Interrupt USART_RX_vect
 *
 *  This interrupt is fired if new data is available in USART receive buffer.
 *
 *  Source: http://www.mikrocontroller.net/articles/AVR-GCC-Tutorial/Der_UART
 */
ISR( USART_RX_vect )
{
	unsigned char nextChar;
	/* Read data from buffer */
	nextChar = UDR;
	/* Only if uart_string is currently not in use */
	if( uart_str_complete == 0 ) {
		if( nextChar != '\n' &&
		nextChar != '\r' &&
		uart_str_count < UART_MAXSTRLEN ) {
			uart_string[uart_str_count] = nextChar;
			uart_str_count++;
		}
		else {
			uart_string[uart_str_count] = '\0';
			uart_str_count = 0;
			uart_str_complete = 1;
			cli(); // TODO: necessary?
		}
	}
}