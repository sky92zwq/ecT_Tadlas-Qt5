#include "mythreads.h"
#include <qmutex.h>

class Myusb
{
private:
    QMutex *lockthread;
    RWThread *rwthread1;
    RWThread *rwthread2;
    processThreadobj *processthreadobj;

    QByteArray RWbyte;
public:
    Myusb(/* args */);
    ~Myusb();

    void openusb();
    void closeusb();
    void dataacquisition();
    void startdataacquisition();
    void stopdataacquisition();

    void setrwthread1null();
    void setrwthread2null();
    void deletemylock();
};


