#include "tcpserver.h"


MyTcpServer::MyTcpServer(QObject *parent) 
{
    qDebug("i am tcpserver, serverthr=%p", serverthr);
    tcpserver = new QTcpServer(this);
    tcpserver->listen(QHostAddress::Any,4545);
    connect(tcpserver, SIGNAL(newConnection()),this,SLOT(acceptConnection()));
    cltsocket = new QTcpSocket(this);
}

// void MyTcpServer::incomingConnection(qintptr socketDescriptor)
// {
//     // if(!serverthr)
//     // {
//     //     return;
//     // }
//     // connect(serverthr, SIGNAL(finished()), serverthr, SLOT(deleteLater()));
//     // serverthr->start();
// }

void MyTcpServer::readFromClt()
{
    
}

void MyTcpServer::acceptConnection()
{
    this->cltsocket = this->tcpserver->nextPendingConnection();
    connect(this->cltsocket, &QIODevice::readyRead,this,&MyTcpServer::readFromClt);
}