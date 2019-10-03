#include "myTCPClient.h"

MyTcpClient::MyTcpClient():tcpSocket(new QTcpSocket(this))
{
    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);

    connect(tcpSocket, &QIODevice::readyRead, this, &MyTcpClient::readFortune);
    connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
            this, &MyTcpClient::displayError);

    tcpSocket->connectToHost("127.0.0.1",4545);
}

int MyTcpClient::sendCommand(const QString& cmd)
{
    //TO DO
}

void MyTcpClient::readFortune()
{

}

void MyTcpClient::displayError(QAbstractSocket::SocketError socketError)
{
    
}