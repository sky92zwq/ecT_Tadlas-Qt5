#include "command.h"
#include <QDebug>

Command::Command(CS_ftfunction *u)
{
    usb=u;
}

Command::~Command()
{

}

void Command::add(quint8 command)
{
    QDataStream in(&TxBuffer,QIODevice::ReadWrite| QIODevice::Append );
    in <<(command);
}

void Command::add(quint16 command)
{
    QDataStream in(&TxBuffer,QIODevice::ReadWrite| QIODevice::Append );
    in <<(command);
}

void Command::remove(quint8 command)
{

    TxBuffer.chop(1);
}

void Command::remove(quint16 command)
{
    TxBuffer.chop(2);
}

void Command::clear()
{
    TxBuffer.clear();

}

DWORD Command::write()
{

    if(usb->Write(TxBuffer.data(),TxBuffer.length(),&BytesReceived)==FT_OK)
    {
        return BytesReceived;

    }
    else
        return 0;
}
