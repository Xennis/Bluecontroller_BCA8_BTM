#include "portcontrol.h"

PortControl::PortControl()
{
    qDebug("Created PortControl");
    /* init */
    this->isBc = false;
    this->bcAck = "wusel";
    this->bcAckReturn = "xyz";
    this->bcCmdLedOn = "ledOn";
    this->bcCmdLedOff = "ledOff";
}


void PortControl::searchBluecontroller(){
    qDebug("Search Port");

    foreach (QextPortInfo info, QextSerialEnumerator::getPorts()) {
        qDebug() << "\t" << info.portName;

        /* Create port */
        PortSettings settings = {BAUD19200, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 10};
        port = new QextSerialPort(info.portName, settings, QextSerialPort::Polling);

        /* Open port */
        if (!port->isOpen()) {
            qDebug() << "\t\t" << "try open port";
            port->open(QIODevice::ReadWrite);
        }

        /* Check port is readable and writable */
        if (port->isOpen() && port->isReadable() && port->isWritable()) {
            qDebug() << "\t\t" << "port is open, readable and writeable";

            /* Dummy write and wait */
            this->writePort(this->bcAck);
            this->sleep(3);

            /* Send handshake ack to Bluecontroller */
            this->writePort(this->bcAck);

            int expectedLength = 3;
            QString returnData;

            while(returnData.length() < expectedLength) {
                QString ret = this->readPort();
                if (!ret.isEmpty()) {
                    //qDebug() << "Port->read" << ret;
                    returnData.append(ret);
                }
            }

            /* Check returnData is expected handshake ack */
            if (returnData == this->bcAckReturn) {
                qDebug() << "Bluecontroller was found at port " << port->portName();
                this->isBc = true;
                break;
            }
        }
    }
}


bool PortControl::writePort(QString s) {
    /* Strings have to end with \n (for Bluecontroller */
    if(!s.endsWith("\n")) {
        s += "\n";
    }
    qint64 result = port->write(QString(s).toLatin1());
    //qDebug() << "Port->write: " << s;

    if(result == -1) {
        return false;
    } else {
        return true;
    }
}


QString PortControl::readPort() {
    /* Wait for bytes (max. 2000 ms) */
    port->waitForReadyRead(2000);
    if (port->bytesAvailable()) {
        return QString::fromLatin1(port->readAll());
    } else {
        return QString("");
    }
}


void PortControl::testBluecontroller() {
    if(this->isBc) {
        for(int i=0; i<=3; i++) {
            this->sleep(2);
            this->writePort("ledOn");
            this->sleep(2);
            this->writePort("ledOff");
        }
    }
}
