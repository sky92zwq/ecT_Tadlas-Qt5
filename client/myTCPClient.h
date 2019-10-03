#ifndef MYTCPCLIENT_H
#define MYTCPCLIENT_H

#include <QDataStream>
#include <QTcpSocket>
#include <QNetworkSession>


//! [0]
class MyTcpClient : public QObject
{
    Q_OBJECT
public:
    MyTcpClient();
    int sendCommand(const QString& cmd);
private slots:
    void readFortune();
    void displayError(QAbstractSocket::SocketError socketError);

private:

    QTcpSocket *tcpSocket = nullptr;
    QDataStream in;

    QNetworkSession *networkSession = nullptr;
};
//! [0]

#endif
