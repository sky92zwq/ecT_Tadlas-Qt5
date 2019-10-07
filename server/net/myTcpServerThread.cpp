#include  <QtNetwork>
#include "myTcpServerThread.h"

MyTcpServerThread::MyTcpServerThread(int socketDescriptor, QObject *parent)
    : QThread(parent), socketDescriptor( socketDescriptor)
{

}

void MyTcpServerThread::run()
{
    QTcpSocket tcpSocket;
    if(!tcpSocket.setSocketDescriptor(socketDescriptor)){
        emit error(tcpSocket.error());
        return;
    }
    while (tcpSocket.waitForReadyRead())
    {
        /* code */
    }
    
}

void MyTcpServerThread::readCommand()
{

}
void MyTcpServerThread::displayError(QAbstractSocket::SocketError socketError)
{

}

