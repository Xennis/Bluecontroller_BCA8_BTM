#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

int main(void)
{

	bt_init();
	bt_setut();

    while(1)
    {
		bt_send_cmd("AT");
    }
}
