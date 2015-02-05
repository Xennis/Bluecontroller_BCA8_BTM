# Bluecontroller (BCA8-BTM)

Atmel Studio 6 C-Project to send and receive text over Bluetooth:

	Microcontroller <-> UART <->    Bluetooth    <-> COM Port <-> PC

Exactly:

	ATmega328p <-> USART0 <-> BTM-222 <->    Bluetooth    <-> Bluetooth dongle <-> COM Port <-> RS232 Terminal <-> PC
	
## Project

Institute of Computer Engineering, University of Lübeck:

* Author: Fabi Rosenthal, Florian Thaeter, Mai Linh E. Nguyen
* Supervisor: Dipl.-Ing. Patrick Weiss, Dipl.-Inf. Alexander Gabrecht

### mReS - Modular Rehabilitation System

This project was developed as part of the mReS project at the Institute of Computer Engineering - University of Lübeck:

mReS is a modular rehabilitation system for training of hand function after stroke. The modularity allows a broad spectrum of training and progress assessment possibilities while reducing the complexity and cost. This facilitates a wider distribution into clinics and home rehabilitation. The system makes of visual feedback distortion, which has been introduced as a new concept in neurorehabilitation. The patient is encouraged to reach beyond prior achievements by giving slightly distorted feedback.

mReS project: http://www.iti.uni-luebeck.de/en/research/mobile-robotics/mres.html

### Informations

Licence: CC BY 3.0 (http://creativecommons.org/licenses/by/3.0/)

Documentation (article): http://xennis.org/wiki/Bluecontroller

Documentation (Doxygen): http://xennis.github.io/Bluecontroller_BCA8_BTM/Bluecontroller/doc/html/

Acknowledgement: Thanks to the support of Michael Dreher and Kamil Loska

### Hardware

* BCA8-BTM (Bluecontroller)
* ATmega328P (Microcontroller)
* BTM-222 (Bluetooth Module)

### Software

* Atmel Studio 6
* RS232 Terminal

## Code

Latest stable version: v1.1 aka Epsilon (tested and proven to work)

### Epsilon version (v1.1) 

Properties:
* Setup Bluecontroller *bluecontroller.c* -> `void bt_setut(void)`
* Send strings: *bluecontroller.c* -> `void bt_puts(char\* s)`
* Receive strings (interrupt driven): cmd.c -> `ISR(USART_RX_vect)`
* Receive commands and react: *cmd.c* -> `void checkCmd(void)`

Commands (for testing):
* `wusel` -> BC sends "xyz" back (intended as handshake ack)
* `ledOn` -> BC sends "abc" back and turns led on
* `ledOff` -> BC sends "123" back and turns led off
