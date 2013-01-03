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
#include "bluecontroller.h"

// global variables
unsigned char* cmdBuffer;	// used to store incoming commands
// declare methods
void checkCmd();
void readCmd(unsigned char nextChar);
void statusLED(int status);

/*
 * TODO: Change return type to void
 */
int main(void)
{
	bt_init();
	/* Write data persistent EEPROM/Flash => only necessary one time */
	//bt_setut();
	while(1) {
		bt_puts("Was ");
		_delay_ms(1000);
	}
}

/*
 * This method adds an incoming character to the commandBuffer and hands out
 * the command if \n occurs 
 */
void readCmd(unsigned char nextChar)
{	
	*cmdBuffer++ = nextChar;
		if(nextChar=='\n') {
			*cmdBuffer = '\0';		// finalize c string if command complete
			cli();					// disable interrupts for a while
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
	int v, status;
	v = strcmp(cmdBuffer,"wuseldusel");
	if(v==0) {
		//react to command wuseldusel
		status = 1;
	}
	v= strcmp(cmdBuffer,"ganzTollerBefehl");
	if(v==0) {
		// react to command gnazTollerBefehl);
		status = 1;
	}
	else {	// invalid command
		status = 2;
	}
	*cmdBuffer = '\0';				// reset commandBuffer 
	sei();							// enable interrupts again
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
			// TODO: long delay
			PORTB |= (1<<PB6);
			// TODO: long delay
		}			
		break;
	case 2:
			while(0) {				// TODO: not to long and not to short
			PORTB = (0<<PB6);
			// TODO: short delay
			PORTB |= (1<<PB6);
			// TODO: short delay
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
	unsigned char buffer;
	/* Read data from buffer */
	buffer = UDR;
	readCmd(buffer);
/*
	// react to characters
	if ( buffer == 'x' ) {
		bt_puts("HalloWelt ");
		_delay_ms(3000);
	}
	else if ( buffer == 'y' ) {
		bt_turn_off();
	}
*/	
	/* Send buffer back */
	//bt_putc(buffer);
}