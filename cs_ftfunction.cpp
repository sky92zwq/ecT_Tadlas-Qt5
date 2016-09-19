#include "cs_ftfunction.h"
#include <QDebug>
#include <qmessagebox.h>


CS_ftfunction::CS_ftfunction()
    :isopen(false),QLibrary("ftd2xx.dll", Q_NULLPTR){

}

CS_ftfunction::~CS_ftfunction()
{
    // insert your code here
}

DWORD CS_ftfunction::getnumDEv()
{
    FT_STATUS getnum=CS_ftfunction:: CreateDeviceInfoList(&numDEv);
    return numDEv;
}



FT_STATUS CS_ftfunction::Open(int iDevice){
    this->m_pOpen =(CS_ftfunction::PtrToOpen)this->resolve("FT_Open");
    if(this->m_pOpen==NULL){
    qDebug("failed, Link to FT_Open is failed!");
    return FT_INVALID_HANDLE;
    }
    else
    {
        qDebug("ok, Link to FT_Open is ok!");
        FT_STATUS open=(*m_pOpen)(iDevice,&m_ftHandle);
       if(open==FT_OK)isopen=true;
       return open;
    }
}

FT_STATUS CS_ftfunction::OpenEx(PVOID pArg1, DWORD dwFlags)
{
    this->m_pOpenEx=(CS_ftfunction::PtrToOpenEx)this->resolve("FT_OpenEx");
    if(this->m_pOpenEx==NULL){
        qDebug("failed, Link to FT_OpenEx is failed!");
        return FT_INVALID_HANDLE;
    }
    else
        return (*m_pOpenEx)(pArg1, dwFlags, &m_ftHandle);
}

FT_STATUS CS_ftfunction::ListDevices(PVOID pArg1, PVOID pArg2, DWORD dwFlags){
    this->m_pListDevices=(CS_ftfunction::PtrToListDevices)this->resolve("FT_ListDevices");
    if(this->m_pListDevices ==NULL){
        qDebug("failed, Link to FT_ListDevices is failed!");
        return FT_INVALID_HANDLE;
    }
    else
        return (*m_pListDevices)(pArg1, pArg2, dwFlags);
}

FT_STATUS CS_ftfunction::Close(){
    this->m_pClose=(CS_ftfunction::PtrToClose)this->resolve("FT_Close");
    if(this->m_pClose ==NULL){
        qDebug("failed, Link to FT_Close is failed!");
        return FT_INVALID_HANDLE;
    }
    else{
        qDebug("ok, Link to FT_Close is ok!");
        FT_STATUS close=(*m_pClose)(m_ftHandle);
        if(close==FT_OK)isopen=false;
        return close;

    }
}

FT_STATUS CS_ftfunction::SetBitMode(UCHAR ucMask, UCHAR ucMode){
    this->m_pSetBitMode=(CS_ftfunction::PtrToSetBitMode)this->resolve("FT_SetBitMode");
    if(this->m_pSetBitMode ==NULL){
        qDebug("failed, Link to FT_SetBitmode is failed!");
        return FT_INVALID_HANDLE;
    }
    else{
        qDebug("ok, Link to FT_SetBitmode is ok!");
        return (*m_pSetBitMode)(m_ftHandle, ucMask, ucMode);
    }
}

FT_STATUS CS_ftfunction::Read(LPVOID lpvBuffer, DWORD dwBuffSize, LPDWORD lpdwBytesRead){
    this->m_pRead=(CS_ftfunction::PtrToRead)this->resolve("FT_Read");
    if(this->m_pRead ==NULL){
        qDebug("failed, Link to FT_Read is failed!");
        return FT_INVALID_HANDLE;
    }
    else{
        qDebug("ok, Link to FT_Read is ok!");
        return (*m_pRead)(m_ftHandle, lpvBuffer, dwBuffSize, lpdwBytesRead);
    }
}

FT_STATUS CS_ftfunction::Write(LPVOID lpvBuffer, DWORD dwBuffSize, LPDWORD lpdwBytes){
    this->m_pWrite=(CS_ftfunction::PtrToWrite)this->resolve("FT_Write");
    if(this->m_pWrite ==NULL){
        qDebug("failed, Link to FT_Write is failed!");
        return FT_INVALID_HANDLE;
    }
    else{
        qDebug("ok, Link to FT_Write is ok!");
        return (*m_pWrite)(m_ftHandle, lpvBuffer, dwBuffSize, lpdwBytes);

    }
}

FT_STATUS CS_ftfunction::ResetDevice(){
    this->m_pResetDevice=(CS_ftfunction::PtrToResetDevice)this->resolve("FT_ResetDevice");
    if(this->m_pResetDevice ==NULL){
        qDebug("failed, Link to FT_ResetDevice is failed!");
        return FT_INVALID_HANDLE;
    }
    else
        return (*m_pResetDevice)(m_ftHandle);
}

FT_STATUS CS_ftfunction::Purge(ULONG dwMask){
    this->m_pPurge=(CS_ftfunction::PtrToPurge)this->resolve("FT_Purge");
    if(this->m_pPurge ==NULL){
        qDebug("failed, Link to FT_Purge is failed!");
        return FT_INVALID_HANDLE;
    }
    else
        return (*m_pPurge)(m_ftHandle, dwMask);
}

FT_STATUS CS_ftfunction::SetTimeouts(ULONG dwReadTimeout, ULONG dwWriteTimeout){
    this->m_pSetTimeouts=(CS_ftfunction::PtrToSetTimeouts)this->resolve("FT_SetTimeouts");
    if(this->m_pSetTimeouts ==NULL){
        qDebug("failed, Link to FT_SetTimeouts is failed!");
        return FT_INVALID_HANDLE;
    }
    else{

        qDebug("ok, Link to FT_SetTimeouts is ok!");
        return (*m_pSetTimeouts)(m_ftHandle, dwReadTimeout, dwWriteTimeout);
    }
}

FT_STATUS CS_ftfunction::GetQueueStatus(LPDWORD lpdwAmountInRxQueue){
    this->m_pGetQueueStatus=(CS_ftfunction::PtrToGetQueueStatus)this->resolve("FT_GetQueueStatus");
    if(this->m_pGetQueueStatus ==NULL){
        qDebug("failed, Link to FT_GetQueueStatus is failed!");
        return FT_INVALID_HANDLE;
    }
    else
        return (*m_pGetQueueStatus)(m_ftHandle, lpdwAmountInRxQueue);
}

FT_STATUS CS_ftfunction::SetBaudRate(DWORD dwBaudRate){
    this->m_pSetBaudRate=(CS_ftfunction::PtrToSetBaudRate)this->resolve("FT_SetBaudRate");
    if(this->m_pSetBaudRate ==NULL){
        qDebug("failed, Link to FT_SetBaudRate is failed!");
        return FT_INVALID_HANDLE;
    }
    else
       return (*m_pSetBaudRate)(m_ftHandle, dwBaudRate);
}

FT_STATUS CS_ftfunction::CreateDeviceInfoList(LPDWORD lpdwNumDevs){
    this->m_pCreateDeviceInfoList=(CS_ftfunction::PtrToCreateDeviceInfoList)this->resolve("FT_CreateDeviceInfoList");
    if(this->m_pCreateDeviceInfoList ==NULL){
        qDebug("failed, Link to FT_CreateDeviceInfoList is failed!");
        return FT_INVALID_HANDLE;
    }
    else
        return (*m_pCreateDeviceInfoList)(lpdwNumDevs);
}

FT_STATUS CS_ftfunction::GetDeviceInfoDetail(DWORD dwIndex, LPDWORD lpdwFlags, LPDWORD lpdwType, LPDWORD lpdwID, LPDWORD lpdwLocId,
 PCHAR pcSerialNumber, PCHAR pcDescription){
    this->m_pGetDeviceInfoDetail=(CS_ftfunction::PtrToGetDeviceInfoDetail)this->resolve("FT_GetDeviceInfoDetail");
    if(this->m_pGetDeviceInfoDetail ==NULL){
        qDebug("failed, Link to FT_GetDeviceInfoDetail is failed!");
        return FT_INVALID_HANDLE;
    }
    else
        return (*m_pGetDeviceInfoDetail)(dwIndex, lpdwFlags, lpdwType, lpdwID, lpdwLocId, pcSerialNumber, pcDescription, &m_ftHandle);
}

FT_STATUS CS_ftfunction::GetDeviceInfoDetail(DWORD numDevs){}
