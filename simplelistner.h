#ifndef SIMPLELISTNER_H
#define SIMPLELISTNER_H

#include <QRunnable>
#include <QTcpSocket>

namespace sam
{
class SimpleListner : public QRunnable
{
public:
    ///
    /// \brief Constructs a SimpleListner with no specified descriptor(-1)
    ///
    SimpleListner();
    ///
    /// \brief Constructs a SimpleListner with given descriptor
    /// \param socketDescriptor
    ///
    SimpleListner(qintptr socketDescriptor);
    ///
    /// \brief setSocketDescriptor
    /// \param socketDescriptor
    ///
    void setSocketDescriptor(qintptr socketDescriptor);

protected:
    void run();

private:
    qintptr mSocketDescriptor;
};//end of class SimpleListner

}//end of namespace sam
#endif // SIMPLELISTNER_H
