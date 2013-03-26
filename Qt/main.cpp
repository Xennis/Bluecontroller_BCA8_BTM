#include <QtCore/QCoreApplication>
#include "PortControl/portcontrol.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PortControl *portControl = new PortControl();
    portControl->searchBluecontroller();
    portControl->testBluecontroller();
    
    return a.exec();
}
