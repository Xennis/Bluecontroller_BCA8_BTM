# Bluecontroller (BCA8-BTM)

Atmel Studio 6 C-Project to send and receive text over Bluetooth:

	Microcontroller <-> UART <->    Bluetooth    <-> COM Port <-> PC

Exactly:

	ATmega328p <-> USART0 <-> BTM-222 <->    Bluetooth    <-> Bluetooth dongle <-> COM Port <-> RS232 Terminal <-> PC
	
## Project

Author: Fabi Rosenthal (code@xennis.de), Florian T.

Licence: CC BY 3.0 (http://creativecommons.org/licenses/by/3.0/)

Documentation: http://wiki.xennis.de/artikel/Bluecontroller

Acknowledgement: Thanks to the support of Patrick W., Michael Dreher and Kamil Loska

## Hardware

* BCA8-BTM (Bluecontroller)
* ATmega328P (Microcontroller)
* BTM-222 (Bluetooth Module)

## Software

* Atmel Studio 6
* RS232 Terminal

## Code

Latest stable Version: Delta (tested and proven to work)

All Versions:
* Delta: stable
* Gamma: deprecated
* Beta: deprecated
* Alpha: deprecated

### Delta Version

Properties:
* Setup Bluecontroller *bluecontroller.c -> void bt_setut(void)*
* Send strings *bluecontroller.c -> void bt_puts(char\* s)*
* Receive strings (interrupt driven) *cmd.c -> ISR(USART_RX_vect)*
* Receive commands and react *cmd.c -> void checkCmd(void)*

Commands (for testing):
* *wusel* -> BC sends "xyz" back (intended as handshake ack)
* *ledOn* -> BC sends "abc" back and turns led on
* *ledOff* -> BC sends "123" back and turns led off