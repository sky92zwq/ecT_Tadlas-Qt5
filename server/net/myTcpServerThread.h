#ifndef MYTCPSERVERTHREAD_H
#define MYTCPSERVERTHREAD_H

#include <QThread>
#include <QTcpSocket>

//! [0]
class MyTcpServerThread : public QThread
{
    Q_OBJECT

public:
    MyTcpServerThread(int socketDescriptor, QObject *parent);

    void run() override;

signals:
    void error(QTcpSocket::SocketError socketError);
private slots:
    void readCommand();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    int socketDescriptor;
};
//! [0]

#endif
