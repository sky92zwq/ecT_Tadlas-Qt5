#ifndef ECTCLASS_H
#define ECTCLASS_H
#include <QtCore>
#include <stdlib.h>


class ECTClass
{
public:
    static ECTClass* getInstance()
    {
        static ECTClass    instance;
        return &instance;
    }
private:
    ECTClass(){}               // Constructor
    ECTClass(ECTClass const&);              // Don't Implement
    ECTClass & operator=(ECTClass const&); // Don't implement
private:
    quint8 electrode_number;
    quint16 measuregapnumber;
public:
    void setelectrode_number(quint8 num);
    quint8 iselectrode_number();
    quint16 indicator();
    quint16 measurenumber();
};
#endif // ECTCLASS_H
