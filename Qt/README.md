# Qt2Bluecontroller

This Qt code searches the Bluecontrollers port and identifies it by a
handshake ack (acknowledgement). When it found the Bluecontroller, it
turns off and on the Bluecontrollers LED.

Note: see Bluecontroller *README.md* for more informations (commands,
...) 
	
## Project

Author: Fabi Rosenthal (code@xennis.de).

Licence: CC BY 3.0 (http://creativecommons.org/licenses/by/3.0/)

## Software and Code

* Qt Creator
* Qt 4.8.1 for Desktop
* QextSerialPort 1.2rc
* Bluecontroller Epsilon Version

## Installation

* Download *QextSerialPort 1.2rc* (https://code.google.com/p/qextserialport/wiki/Downloads)
* Copy it to */qextserialport*
* Build the Qt project
* Copy the *Bluecontroller Epsilon Version* to Bluecontroller device
* Connect your PC with the *Bluecontroller* (PIN code *1234*) 
* Run the Qt code

## Code

Tested and proven to work.

Code was tested with: Windows 7 64-Bit, Raspbian "wheezy" (Raspberry Pi)