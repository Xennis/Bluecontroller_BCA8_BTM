#include "bluecontroller.h"

int main(void)
{

	bt_init();
	bt_setut();

    while(1)
    {
		bt_send_cmd("Hallo");
    }
}
