/*
  Objekt für die Portsteuerung. Alles was über die RS232-Schnittstelle gesendet werden soll, wird hier gemacht.
  */

#ifndef PORTCONTROL_H
#define PORTCONTROL_H

#include <QObject>
#include <QtCore>

#include "qextserialport.h"
#include "qextserialenumerator.h"

class PortControl : public QThread
{
    Q_OBJECT
public:
    explicit PortControl();

    /**
      * Search Bluecontroller
      *
      *     Searches the port and tries to connect with it.
      */
    void searchBluecontroller();

    /**
      * Test Bluecontroller
      *
      *     Sends the commands "ledOn" and "ledOff" to the
      *     Bluecontroller.
      */
    void testBluecontroller();

    /**
      * Write port
      *
      *     Sends a string.
      *
      * @return true, if writing was sucessful
      */
    bool writePort(QString);

    /**
      * Read port
      *
      *     Waits (active) for bytes and return them.
      *
      * @return Received string (or empty string)
      */
    QString readPort();

private:
    /** Port */
    QextSerialPort *port;
    /** True, if Bluecontroller was found */
    bool isBc;
    /** Handschake ack */
    QString bcAck;
    /** Handshake returning ack */
    QString bcAckReturn;
    /** Command to turn led on */
    QString bcCmdLedOn;
    /** Command to turn led off */
    QString bcCmdLedOff;
};

#endif // PORTCONTROL_H
