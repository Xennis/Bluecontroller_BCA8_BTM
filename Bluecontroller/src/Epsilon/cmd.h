/**
 * @file	cmd.h
 * @author	Florian Thaeter, Fabi Rosenthal
 * @version	Epsilon
 * @date	25.03.2013
 *
 * @section LICENSE
 *  Licence: CC BY 3.0 (http://creativecommons.org/licenses/by/3.0/)
 *
 * @section DESCRIPTION
 *  Code: http://github.com/Xennis/Bluecontroller_BCA8_BTM
 *
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
	void checkCmd(void);

#endif /* CMD_H_ */