#ifndef ECTCLASS_H
#define ECTCLASS_H
#include <QtCore>


class ECTClass
{
public:
    static ECTClass* getInstance()
    {
        static ECTClass instance;
        return &instance;
    }
    inline double calculatebuffer(unsigned char *buffer, int i){
        return (buffer[i]*256+buffer[i+1])*64/1*M_PI/2/400*2/8192*1000;
    }
private:
    ECTClass();               // Constructor
    ECTClass(const ECTClass&);              // Don't Implement
    ECTClass & operator=(const ECTClass&); // Don't implement
private:
    quint8 electrode_number=16;
    quint16 measuregapnumber;
    bool voidcalibrated=false;
    bool fullcalibrated=false;
public:
    QVector< double> datavoid;
    QVector< double> datafull;
    bool             differencemode=false;

public:
    void setelectrode_number(quint8 num);
    quint8 iselectrode_number();
    float indicator();
    quint16 measurenumber();
    void setvoidcalibration(unsigned char *rxbuffer);
    void setfullcalibration(unsigned char *rxbuffer);
public:
    bool alreadyVoidcalibtrated();
    bool alreadyFullcalibtrated();
};

#endif // ECTCLASS_H
