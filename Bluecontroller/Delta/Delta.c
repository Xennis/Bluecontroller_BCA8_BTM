/*
 * Delta.c
 *
 * Created: 24.03.2013
 *  Program: Atmel Studio 6
 *  Author: Fabi Rosenthal, Florian Thaeter
 *  Licence: CC BY 3.0 (http://creativecommons.org/licenses/by/3.0/)
 *  Code: http://github.com/Xennis/Bluecontroller_BCA8_BTM
 *  Documentation: http://wiki.xennis.de/artikel/Bluecontroller
 */
#include "cmd.h"

int main(void)
{
	bt_init();

	/* Write data persistent EEPROM/Flash => only necessary one time */
	//bt_setut();
	
	while(1) {
		checkCmd();
	}
}