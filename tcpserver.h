#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QThreadPool>
#include <QDebug>

namespace sam
{
class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    ///
    /// \brief Default constructor.
    ///
    /// \details Constructs a TcpServer with no parent and port number 5050
    ///
    TcpServer();
    ///
    /// \brief Constructs a TcpServer with given parent and port number 5050
    /// \param parent.
    ///
    explicit TcpServer(QObject *parent);
    ///
    /// \brief Constructs a TcpServer with no parent and given port number
    /// \param portNumber
    ///
    explicit TcpServer(quint16 portNumber);
    ///
    /// \brief Constructs a TcpServer with given parent and given port number
    /// \param parent
    /// \param portNumber
    ///
    TcpServer(QObject *parent, quint16 portNumber);
    ///
    /// \brief destructor.
    ///
    ~TcpServer();
    ///
    /// \brief start server
    ///
    /// \return If this function can open specified port and listening to it
    ///     successfully, returns true otherwise returns false.
    ///
    bool start();

protected:
    void incomingConnection(qintptr handle);

signals:

public slots:

private:
    QScopedPointer<QThreadPool> mThreadPool;
    quint16 mPortNumber;
};
}
#endif // TCPSERVER_H
