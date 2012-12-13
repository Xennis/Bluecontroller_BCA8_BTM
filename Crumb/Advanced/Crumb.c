/*
 * uart.h
 *
 * Created: 13.12.2012
 *  Program: Atmel Studio 6
 *  Author: Fabi Rosenthal, Florian T.
 *  Licence: CC BY 3.0 (http://creativecommons.org/licenses/by/3.0/)
 *  Code: http://github.com/Xennis/Bluecontroller_BCA8_BTM
 *  Documentation: http://wiki.xennis.de/artikel/AVR-GCC_-_UART
 */
#include "uart.h"

int main(void)
{
	uart_init();
	sei();
	uart_timer_init();
	
	while(1)
	{
		uart_puts("Hello ");
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
		uart_puts("World ");
		_delay_ms(3000);
	}
}