/*
 * Beta.c
 *
 * Created: 30.11.2012
 *  Program: Atmel Studio 6
 *  Author: Fabi Rosenthal
 *  Licence: CC BY 3.0 (http://creativecommons.org/licenses/by/3.0/)
 *  Code: http://github.com/Xennis/Bluecontroller_BCA8_BTM
 *  Documentation: http://wiki.xennis.de/artikel/Bluecontroller
 */
#include "bluecontroller.h"

int led(void);

int main(void)
{

	bt_init();
	/* write data persistent EEPROM/Flash => only necessary one time */
	//bt_setut();
	
	// TODO: Replace with bt_putc(MCUSR)?
	
	/* Wait for empty transmit buffer */
//	while ( !( UCSRA & (1<<UDRE)) ) // TODO: Missing semicolon?
//	UDR = MCUSR;

	//bt_check_turn_off()

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
	
	// TODO: Replace with bt_putc(buffer)?
	
	/* Send buffer back */
//	bt_putc(buffer);
	
	/* Wait for empty transmit buffer */
//	while ( !( UCSRA & (1<<UDRE)) );
	/* ... and immediately send back */
//	UDR = buffer;
}