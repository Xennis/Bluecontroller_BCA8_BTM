/*
 * bluecontroller.h
 *
 *  Author: Fabi
 */ 
#ifndef BLUECONTROLLER_H_
	#define BLUECONTROLLER_H_

	#include <util/delay.h>

	void bt_init(void);
	void bt_setut(void);
	void bt_reset(void);
	void bt_escape_sequence(void);
	void bt_send_cmd(char* pc);
	void bt_puts(char* pc);
	void bt_putc(char c);

#endif
