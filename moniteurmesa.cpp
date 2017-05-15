#include "moniteurmesa.h"
#include <iostream>
MoniteurMESA::MoniteurMESA(int indexToWatch):
    indexToWatch(indexToWatch),
    isFree(true)
{
    idFree = new QWaitCondition();
}

void MoniteurMESA::acquire()
{
        mutex.lock();
        idFree->wait(&mutex);
        mutex.unlock();
 }

void MoniteurMESA::release()
{
    mutex.lock();
    idFree->wakeOne();
    mutex.unlock();
}

bool MoniteurMESA::isFinished()
{
    nbStop++;
    std::cout << nbStop << std::endl;
    if(nbStop == 5)
        return true;
    return false;
}
