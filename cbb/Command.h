#ifndef COMMAND_H
#define COMMAND_H
#include <QString>
#include <QMap>
using namespace std;


class Command
{
public:
    virtual int execute() = 0;
};

class Invoker
{
public:
    void registercmd(QString, Command *);
    int execute(QString);
private:
    QMap<QString, Command*> cmdmp;

};
#endif
