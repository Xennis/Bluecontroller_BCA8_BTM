/*
 * Beta.c
 *
 * Created: 06.12.2012
 *  Program: Atmel Studio 6
 *  Author: Fabi Rosenthal, Florian T.
 *  Licence: CC BY 3.0 (http://creativecommons.org/licenses/by/3.0/)
 *  Code: http://github.com/Xennis/Bluecontroller_BCA8_BTM
 *  Documentation: http://wiki.xennis.de/artikel/Bluecontroller
 */
#include "bluecontroller.h"

int main(void)
{
	bt_init();
	/* write data persistent EEPROM/Flash => only necessary one time */
	bt_setut();

	while(1) {
		bt_puts("Was ");
		_delay_ms(1000);
	}
}

/*
 * Dieser Interrupt wird ausgelöst sobald neue Daten im USART-Empfangspuffer liegen
 */
ISR( USART_RX_vect )
{
	unsigned char buffer;

	/* Read data from buffer */
	buffer = UDR;

	if ( buffer == 'x' ) {
		bt_puts("HalloWelt ");
		_delay_ms(3000);
	}
	else if ( buffer == 'y' ) {
		bt_turn_off();
	}
	
	/* Send buffer back */
	//bt_putc(buffer);
}