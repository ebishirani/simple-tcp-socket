#include <QCoreApplication>

#include"tcpserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    sam::TcpServer tcpServer;
    tcpServer.start();

    return a.exec();
}
