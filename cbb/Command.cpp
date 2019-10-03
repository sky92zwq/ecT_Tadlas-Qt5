#include "Command.h"

void Invoker::registercmd(QString cmd, Command* executer)
{
    cmdmp.insert(cmd,executer);
}

int Invoker::execute(QString cmd)
{
    cmdmp[cmd]->execute();
    return 0;
}