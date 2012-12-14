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
	int v;
	v = strcmp(cmdBuffer,"wuseldusel");
	if(v==0) {
		//react to command wuseldusel
	}
	v= strcmp(cmdBuffer,"ganzTollerBefehl");
	if(v==0) {
		// react to command gnazTollerBefehl);
	}
	*cmdBuffer = '\0';				// reset commandBuffer 
	sei();							// enable interrupts again
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
>>>>>>> Add delta branch
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