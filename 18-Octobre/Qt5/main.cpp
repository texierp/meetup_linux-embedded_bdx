#include <QCoreApplication>
#include "CWaRP7Broadcast.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    WaRP7Broadcast Server;

    return a.exec();
}
