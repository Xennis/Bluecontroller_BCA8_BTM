# Qt2Bluecontroller

This Qt code searches the Bluecontrollers port and identifies it by a
handshake ack (acknowledgement). When it found the Bluecontroller, it
turns off and on the Bluecontrollers LED.

Note: see Bluecontroller *README.md* for more informations (commands,
...) 
	
## Project

Institute of Computer Engineering, University of Lübeck:

* Author: Fabi Rosenthal (code@xennis.de)
* Supervisor: Dipl.-Ing. Patrick Weiss, Dipl.-Inf. Alexander Gabrecht

### mReS - Modular Rehabilitation System

This project was developed as part of the mReS project at the Institute of Computer Engineering - University of Lübeck:

mReS is a modular rehabilitation system for training of hand function after stroke. The modularity allows a broad spectrum of training and progress assessment possibilities while reducing the complexity and cost. This facilitates a wider distribution into clinics and home rehabilitation. The system makes of visual feedback distortion, which has been introduced as a new concept in neurorehabilitation. The patient is encouraged to reach beyond prior achievements by giving slightly distorted feedback.

mReS project: http://www.iti.uni-luebeck.de/en/research/mobile-robotics/mres.html

### Informations

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