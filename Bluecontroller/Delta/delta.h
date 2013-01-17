/*
 * uart.h
 *
 * Created: 17.01.2013
 *  Program: Atmel Studio 6
 *  Author: Florian Thaeter, Fabian Rosenthal
 *  Licence: CC BY 3.0 (http://creativecommons.org/licenses/by/3.0/)
 *  Code: http://github.com/Xennis/Bluecontroller_BCA8_BTM
 *  Documentation: http://wiki.xennis.de/artikel/Bluecontroller
 */
#ifndef DELTA_H_
	#define DELTA_H_

	/* Define */
	#define UART_MAXSTRLEN 10
	/* Include */
	#include "bluecontroller.h"
	/* Method */
	void checkCmd();
	void statusLED(int status);
	/* Global Viariables */
	volatile char uart_string[UART_MAXSTRLEN + 1] = "";	//used to store incoming commands
	volatile uint8_t uart_str_complete = 0;     		//1 means complete received 
	volatile uint8_t uart_str_count = 0;

#endif /* DELTA_H_ */
