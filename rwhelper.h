#ifndef RWHELPER_H
#define RWHELPER_H
#include <QString>
#include <QFile>
#include <QDataStream>
#include <QTextStream>


template<typename T>
class RWhelper
{
public:
    RWhelper();

    void readtxt(T *content,QString name);
    void writetxt(T *f,int *fsize,QString name);
};


//impletetion
template<typename T>
RWhelper<T>::RWhelper()
{

}
template<typename T>
void RWhelper<T>::readtxt(T *content,const QString name)
{
    QFile senfile(name);
    if (!senfile.open(QIODevice::ReadOnly | QIODevice::Text))
        return ;

    QTextStream outsenfile(&senfile);
    outsenfile.skipWhiteSpace();
    outsenfile.seek(0);
//    QString nouse;
    int i=0;
    while(!outsenfile.atEnd())
    {

            outsenfile>>content[i];
            i++;
//            nouse=outsenfile.readLine();
    }
    senfile.close();
}
template<typename T>
void RWhelper<T>::writetxt(T*f,int *fsize,const QString name)
{

    QFile file(name);
    file.open(QIODevice::ReadOnly);//  | QIODevice::Text|QIODevice::Truncate))
    QTextStream in(&file);
    file.close();//new

    file.open(QIODevice::Truncate);
    file.close();

    file.open(QIODevice::WriteOnly);

    for(int i=0;i<fsize[0];i++) {
        for(int j=0;j<fsize[1];j++)
        {

            in<<f[i+j*fsize[0]]<<"\r\n";
        }
    }

    file.close();
}

#endif // RWHELPER_H
