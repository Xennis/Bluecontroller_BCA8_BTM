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
	
	while(1)
	{
		uart_puts("Hallo");
		_delay_ms(1000); // Unnecessary
	}
}