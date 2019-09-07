#include <QUdpSocket>


class UdpServer
{
public:
    void initSocket();
    void readPendingDatagrams();
private:
    QUdpSocket *udpSocket;
}

