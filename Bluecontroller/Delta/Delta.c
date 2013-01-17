/*
 * Delta.c
 *
 * Created: 13.12.2012
 *  Program: Atmel Studio 6
 *  Author: Fabi Rosenthal, Florian Thaeter
 *  Licence: CC BY 3.0 (http://creativecommons.org/licenses/by/3.0/)
 *  Code: http://github.com/Xennis/Bluecontroller_BCA8_BTM
 *  Documentation: http://wiki.xennis.de/artikel/Bluecontroller
 */


#include "delta.h"


int main(void)
{
	bt_init();
	/* Write data persistent EEPROM/Flash => only necessary one time */
	//bt_setut();
	/*
	while(1) {
		bt_puts("Was ");
		_delay_ms(1000);
	}
	*/
	while(1) {
		checkCmd();
	}
}



/*
 * This method checks if received command is a valid command and react to it.
 * Furthermore it resets the commandBuffer.
 *
 */
void checkCmd()
{
	while(uart_str_complete!=1);	//wait for complete command
	int v, status;
	v = strcmp(uart_string,"wuseldusel");
	if(v==0) {
		//TODO react to command
		bt_puts("xyz");
		status = 1;
	}
	else {	// invalid command
		status = 2;
	}
	uart_str_complete = 0;			// reset command
	statusLED(status);
}

/*
 * This method is used for debugging purpose. If a correct command is detected
 * (status 1) the Bluecontorller LED blinks slow for a while. If an incorrect
 * command is detected (status 2) the LED blinks fast. In all other cases
 * (status 0) the LED is turned off.
 */
void statusLED(int status) {
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
}		

/*
 * This interrupt is fired if new data is available in USART receive buffer
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
		}
	}
}