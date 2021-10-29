#include "simplelistner.h"

#include <QRunnable>
#include <QTcpSocket>

sam::SimpleListner::SimpleListner() :
    sam::SimpleListner::SimpleListner(-1)
{}
//---------------------------------------------------------------------------
sam::SimpleListner::SimpleListner(qintptr socketDescriptor) :
    mSocketDescriptor{socketDescriptor}
{}
//---------------------------------------------------------------------------
void sam::SimpleListner::setSocketDescriptor(qintptr socketDescriptor)
{
    this->mSocketDescriptor = socketDescriptor;
}
//---------------------------------------------------------------------------
void sam::SimpleListner::run()
{
    if (!this->mSocketDescriptor)
    {
        return;
    }
    //Make a tcpsocket to communicate with new connected client.
    QTcpSocket socket;
    socket.setSocketDescriptor(this->mSocketDescriptor);
    bool canUseSocket = (socket.isValid() && socket.isOpen());
    if (true == canUseSocket)
    {
        //Wait for 30 seconds to receive data from client.
        bool waitResult = socket.waitForReadyRead();

        QByteArray readedData("Time out, Please reconnect to transmit data");
        if (true == waitResult)//Check did client send data?
        {
            readedData = socket.readAll();
        }
        socket.write(readedData);
        socket.flush();
        socket.waitForBytesWritten();
        socket.close();
    }
}
//---------------------------------------------------------------------------
