#include "tcpserver.h"
#include "simplelistner.h"

sam::TcpServer::TcpServer() :
    sam::TcpServer::TcpServer(Q_NULLPTR, 5050)
{}
//---------------------------------------------------------------------------
sam::TcpServer::TcpServer(QObject *parent) :
    sam::TcpServer::TcpServer(parent, 5050)
{}
//---------------------------------------------------------------------------
sam::TcpServer::TcpServer(quint16 portNumber) :
    sam::TcpServer::TcpServer(Q_NULLPTR, portNumber)
{}
//---------------------------------------------------------------------------
sam::TcpServer::TcpServer(QObject *parent, quint16 portNumber) :
    QTcpServer(parent),
    mThreadPool{new QThreadPool(this)},
    mPortNumber{portNumber}
{
    //10 was selected for simplicity.
    this->mThreadPool->setMaxThreadCount(10);
}
//---------------------------------------------------------------------------
sam::TcpServer::~TcpServer()
{
    if (true == this->isListening())
    {
        this->close();
        this->mThreadPool->waitForDone(500);
        this->mThreadPool->clear();
    }
}
//---------------------------------------------------------------------------
bool sam::TcpServer::start()
{
    return this->listen(QHostAddress::Any, mPortNumber);
}
//---------------------------------------------------------------------------
void sam::TcpServer::incomingConnection(qintptr handle)
{
    if (handle)
    {
        //This part of code is inefficient based on memory usage :(
        SimpleListner *simpleListner = new SimpleListner(handle);
        simpleListner->setAutoDelete(true);
        this->mThreadPool->start(simpleListner);
    }
}
