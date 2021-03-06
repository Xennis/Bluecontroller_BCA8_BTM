/**
 * @file	Epsilon.c
 * @author	Fabi Rosenthal, Florian Thaeter
 * @version	Epsilon
 * @date	18.05.2013
 *
 * @section LICENSE
 *  Licence: CC BY 3.0 (http://creativecommons.org/licenses/by/3.0/)
 *
 * @section DESCRIPTION 
 *	Code: http://github.com/Xennis/Bluecontroller_BCA8_BTM
 *
 *  Documentation: http://xennis.org/wiki/Bluecontroller
 *
 *	Program: Atmel Studio 6
 */
#include "cmd.h"

/**
 * @brief Main
 *
 *  Initializes Bluecontroller and checks the commands.
 */
void main(void)
{
	bt_init();

	/* Write data persistent EEPROM/Flash => only necessary one time */
	//bt_setut();
	
	while(1) {
		checkCmd();
	}
}