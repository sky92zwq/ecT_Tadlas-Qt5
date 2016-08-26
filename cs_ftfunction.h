#ifndef CS_FTFUNCTION_H
#define CS_FTFUNCTION_H
#include <QtCore/qobject.h>
#include <QLibrary>
#include <ftd2xx.h>
#include <qtcore/qt_windows.h>


class CS_ftfunction:public QLibrary
{
public:
//    explicit CS_ftfunction(QObject *parent = Q_NULLPTR);

     explicit CS_ftfunction();

//    explicit CS_ftfunction(const QString& fileName, int verNum, QObject *parent = Q_NULLPTR);
//    explicit CS_ftfunction(const QString& fileName, const QString &version, QObject *parent = Q_NULLPTR);


    ~CS_ftfunction();
public:
    typedef FT_STATUS(WINAPI *PtrToOpen)(int, FT_HANDLE *);
    PtrToOpen m_pOpen;

    typedef FT_STATUS(WINAPI *PtrToOpenEx)(PVOID, DWORD, FT_HANDLE *);
    PtrToOpenEx m_pOpenEx;

    typedef FT_STATUS(WINAPI *PtrToListDevices)(PVOID, PVOID, DWORD);
    PtrToListDevices m_pListDevices;

    typedef FT_STATUS(WINAPI *PtrToClose)(FT_HANDLE);
    PtrToClose m_pClose;

    typedef FT_STATUS(WINAPI *PtrToSetBitMode)(FT_HANDLE, UCHAR, UCHAR);
    PtrToSetBitMode m_pSetBitMode;

    typedef FT_STATUS(WINAPI *PtrToRead)(FT_HANDLE, LPVOID, DWORD, LPDWORD);
    PtrToRead m_pRead;

    typedef FT_STATUS(WINAPI *PtrToWrite)(FT_HANDLE, LPVOID, DWORD, LPDWORD);
    PtrToWrite m_pWrite;

    typedef FT_STATUS(WINAPI *PtrToResetDevice)(FT_HANDLE);
    PtrToResetDevice m_pResetDevice;

    typedef FT_STATUS(WINAPI *PtrToPurge)(FT_HANDLE, ULONG);
    PtrToPurge m_pPurge;

    typedef FT_STATUS(WINAPI *PtrToSetTimeouts)(FT_HANDLE, ULONG, ULONG);
    PtrToSetTimeouts m_pSetTimeouts;

    typedef FT_STATUS(WINAPI *PtrToGetQueueStatus)(FT_HANDLE, LPDWORD);
    PtrToGetQueueStatus m_pGetQueueStatus;
    FT_STATUS GetQueueStatus(LPDWORD);

    typedef FT_STATUS(WINAPI *PtrToSetBaudRate)(FT_HANDLE ftHandle, DWORD dwBaudRate);
    PtrToSetBaudRate m_pSetBaudRate;

    typedef FT_STATUS(WINAPI *PtrToCreateDeviceInfoList)(LPDWORD lpdwNumDevs);
    PtrToCreateDeviceInfoList m_pCreateDeviceInfoList;

    typedef FT_STATUS(WINAPI *PtrToGetDeviceInfoDetail)(DWORD dwIndex, LPDWORD lpdwFlags, LPDWORD lpdwType, LPDWORD lpdwID, LPDWORD lpdwLocId,
        PCHAR pcSerialNumber, PCHAR pcDescription, FT_HANDLE *ftHandle);
    PtrToGetDeviceInfoDetail m_pGetDeviceInfoDetail;
private:
    const QString fileName="ftd2xx.dll";

public:
       FT_HANDLE m_ftHandle;
       FT_STATUS m_ftStatus;
       HMODULE m_hmodule;
public:
//       BOOL loadftdll();

       FT_STATUS MYUSB_Open(int iDevice);

       FT_STATUS MYUSB_OpenEx(PVOID, DWORD);

       FT_STATUS MYUSB_ListDevices(PVOID, PVOID, DWORD);

       FT_STATUS MYUSB_Close();

       FT_STATUS MYUSB_SetBitMode(UCHAR, UCHAR);

       FT_STATUS MYUSB_Read(LPVOID, DWORD, LPDWORD);

       FT_STATUS MYUSB_Write(LPVOID, DWORD, LPDWORD);

       FT_STATUS MYUSB_ResetDevice();

       FT_STATUS MYUSB_Purge(ULONG);

       FT_STATUS MYUSB_SetTimeouts(ULONG, ULONG);

       FT_STATUS MYUSB_GetQueueStatus(LPDWORD);

       FT_STATUS MYUSB_SetBaudRate(DWORD dwBaudRate);

       FT_STATUS MYUSB_CreateDeviceInfoList(LPDWORD lpdwNumDevs);

       FT_STATUS MYUSB_GetDeviceInfoDetail(DWORD dwIndex, LPDWORD lpdwFlags, LPDWORD lpdwType, LPDWORD lpdwID, LPDWORD lpdwLocId,
        PCHAR pcSerialNumber, PCHAR pcDescription);

       FT_STATUS GetDeviceInfoDetail(DWORD numDevs);


};

#endif // CS_FTFUNCTION_H
