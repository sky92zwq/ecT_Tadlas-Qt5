#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QStringList>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>

//! [0]
class MyTcpServer : public QObject
{
    Q_OBJECT

public:
    MyTcpServer( QObject *parent = 0);

protected:
    // void incomingConnection(qintptr socketDescriptor) override;
private slots:
    void readFromClt();
    void acceptConnection();
private:
    QThread *serverthr;
    QTcpSocket *cltsocket;
    QTcpServer *tcpserver;
};
//! [0]

#endif
