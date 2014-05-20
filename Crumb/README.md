# Crumb

Testing UART with Crumb Modul

## Project

Author: Fabi Rosenthal, Florian Thaeter

Documentation: http://xennis.org/wiki/AVR-GCC_-_UART

## Hardware

* Crumb328 V2.3 AVR ATmega Modul
* Atmel AVR ATmega328

## Software

* Atmel Studio 6
* RS232 Terminal

## Code Versions

### Basic

Code sends regularly "Hello".

Terminal's settings:
* Baud: 115200
* Data bits: 8
* Stop bits: 2
* Parity: None
* Flow control: None

Status: tested and proven to work

### Advanced

Code sends regularly "Hello". If you transmit an "x", it answers (interrupt driven) with "World".

Terminal's settings:
* Baud: 115200
* Data bits: 8
* Stop bits: 1
* Parity: None
* Flow control: None

Status: tested and proven to work