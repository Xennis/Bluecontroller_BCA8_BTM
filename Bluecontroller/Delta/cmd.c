/*
 * cmd.c
 *
 * Created: 24.03.2013 16:11:34
 *  Program: Atmel Studio 6
 *  Author: Fabi Rosenthal, Florian Thaeter
 *  Licence: CC BY 3.0 (http://creativecommons.org/licenses/by/3.0/)
 *  Code: http://github.com/Xennis/Bluecontroller_BCA8_BTM
 *  Documentation: http://wiki.xennis.de/artikel/Bluecontroller
 */ 
#include "cmd.h"

/* Global Variables */
volatile char uart_string[UART_MAXSTRLEN + 1] = "";	//used to store incoming commands
volatile uint8_t uart_str_complete = 0;     		//1 means complete received
volatile uint8_t uart_str_count = 0;


/*
 * This method checks if received command is a valid command and react to it.
 * Furthermore it resets the commandBuffer.
 *
 */
void checkCmd()
{
	while (uart_str_complete!=1);	//wait for complete command
	
	char* uart_string_val = (char *) uart_string;
	if(strcmp(uart_string_val, "wusel") == 0) {
		bt_puts("xyz");
	}
	else if(strcmp(uart_string_val, "dusel") == 0) {
		bt_puts("abc");
	}
	else {
		// send invalid command back
		bt_debug(uart_string_val);
	}

	uart_str_complete = 0;			// reset command
	sei(); // TODO: test
}

/*
 * This method is used for debugging purpose. If a correct command is detected
 * (status 1) the Bluecontorller LED blinks slow for a while. If an incorrect
 * command is detected (status 2) the LED blinks fast. In all other cases
 * (status 0) the LED is turned off.
 */
/*void statusLED(int status) {
	DDRB |= (1<<DDB6);			// define PortB->LED as output ... TODO: put it somewhere else
	switch (status)
	{
	case 1:
		while(0) {					// TODO: not to long and not to short
			PORTB = (0<<PB6);
			_delay_ms(1000);
			PORTB |= (1<<PB6);
			_delay_ms(1000);
		}			
		break;
	case 2:
			while(0) {				// TODO: not to long and not to short
			PORTB = (0<<PB6);
			_delay_ms(500);
			PORTB |= (1<<PB6);
			_delay_ms(500);
		}
		break;
	default:
		PORTB = (0<<PB6);
		break;
	}
}*/	

/*
 * This interrupt is fired if new data is available in USART receive buffer.
 *
 * Source: http://www.mikrocontroller.net/articles/AVR-GCC-Tutorial/Der_UART
 */
ISR( USART_RX_vect )
{
	unsigned char nextChar;
	/* Read data from buffer */
	nextChar = UDR;
	//readCmd(nextChar);
	if( uart_str_complete == 0 ) {	// only if uart_string is currently not in use
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
			cli(); // TODO: TESTEN
		}
	}
}