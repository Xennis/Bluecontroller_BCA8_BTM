/*
 * cmd.h
 *
 * Created: 24.03.2013
 *  Program: Atmel Studio 6
 *  Author: Florian Thaeter, Fabi Rosenthal
 *  Licence: CC BY 3.0 (http://creativecommons.org/licenses/by/3.0/)
 *  Code: http://github.com/Xennis/Bluecontroller_BCA8_BTM
 *  Documentation: http://wiki.xennis.de/artikel/Bluecontroller
 */ 
#ifndef CMD_H_
	#define CMD_H_

	/* Include */
	#include "bluecontroller.h"
//	#include <stdio.h> // TODO: notwendig?
	#include <string.h>		// Used for strcmp()

	/* Define */
	#define UART_MAXSTRLEN	10

	/* Method */
	void checkCmd();

#endif /* CMD_H_ */