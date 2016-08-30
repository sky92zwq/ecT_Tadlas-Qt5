#ifndef CS_FTFUNCTION_H
#define CS_FTFUNCTION_H
#include <QtCore/qobject.h>
#include <QLibrary>
#include <ftd2xx.h>
#include <qtcore/qt_windows.h>
#include <qstring.h>
#include <qstringlist.h>


class CS_ftfunction:public QLibrary
{
public:
//    explicit CS_ftfunction(QObject *parent = Q_NULLPTR);

     explicit CS_ftfunction();

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

    typedef FT_STATUS(WINAPI *PtrToSetBaudRate)(FT_HANDLE ftHandle, DWORD dwBaudRate);
    PtrToSetBaudRate m_pSetBaudRate;

    typedef FT_STATUS(WINAPI *PtrToCreateDeviceInfoList)(LPDWORD lpdwNumDevs);
    PtrToCreateDeviceInfoList m_pCreateDeviceInfoList;

    typedef FT_STATUS(WINAPI *PtrToGetDeviceInfoDetail)(DWORD dwIndex, LPDWORD lpdwFlags, LPDWORD lpdwType, LPDWORD lpdwID, LPDWORD lpdwLocId,
        PCHAR pcSerialNumber, PCHAR pcDescription, FT_HANDLE *ftHandle);
    PtrToGetDeviceInfoDetail m_pGetDeviceInfoDetail;
private:
    const QString fileName="ftd2xx.dll";
    DWORD numDEv;                        //预留给成员函数返回usb数量

public: /*builds a device information list and returns the number of D2XX devices
     * connected to the system. The list contains information about both unopen and open devices.*/
   DWORD getnumDEv();

public:
       FT_HANDLE m_ftHandle;
       FT_STATUS m_ftStatus;
       HMODULE m_hmodule;
private:
       bool isopen;
public:
       inline bool isopened()
       {
           return isopen;
       }
public:
//       BOOL loadftdll();

       FT_STATUS  Open(int iDevice);

       FT_STATUS  OpenEx(PVOID, DWORD);

       FT_STATUS  ListDevices(PVOID, PVOID, DWORD);

       FT_STATUS  Close();

       FT_STATUS  SetBitMode(UCHAR, UCHAR);

       FT_STATUS  Read(LPVOID, DWORD, LPDWORD);

       FT_STATUS  Write(LPVOID, DWORD, LPDWORD);

       FT_STATUS  ResetDevice();

       FT_STATUS  Purge(ULONG);

       FT_STATUS  SetTimeouts(ULONG, ULONG);

       FT_STATUS  GetQueueStatus(LPDWORD);

       FT_STATUS  SetBaudRate(DWORD dwBaudRate);

       FT_STATUS  CreateDeviceInfoList(LPDWORD lpdwNumDevs);

       FT_STATUS  GetDeviceInfoDetail(DWORD dwIndex, LPDWORD lpdwFlags, LPDWORD lpdwType, LPDWORD lpdwID, LPDWORD lpdwLocId,
        PCHAR pcSerialNumber, PCHAR pcDescription);

       FT_STATUS GetDeviceInfoDetail(DWORD numDevs);
public:
       //
       // Device status
       //
       QStringList status
        {
       "FT_OK",
       "FT_INVALID_HANDLE",
       "FT_DEVICE_NOT_FOUND",
       "FT_DEVICE_NOT_OPENED",
       "FT_IO_ERROR",
       "FT_INSUFFICIENT_RESOURCES",
       "FT_INVALID_PARAMETER",
       "FT_INVALID_BAUD_RATE",

       "FT_DEVICE_NOT_OPENED_FOR_ERASE",
       "FT_DEVICE_NOT_OPENED_FOR_WRITE",
       "FT_FAILED_TO_WRITE_DEVICE",
       "FT_EEPROM_READ_FAILED",
       "FT_EEPROM_WRITE_FAILED",
       "FT_EEPROM_ERASE_FAILED",
          "FT_EEPROM_NOT_PRESENT",
          "FT_EEPROM_NOT_PROGRAMMED",
          "FT_INVALID_ARGS",
          "FT_NOT_SUPPORTED",
          "FT_OTHER_ERROR"
       };


};

#endif // CS_FTFUNCTION_H
