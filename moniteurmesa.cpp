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
        std::cout << "debut"<< std::endl;
        idFree->wait(&mutex);
        std::cout << "fin"<< std::endl;
        mutex.unlock();
 }

void MoniteurMESA::release()
{
    idFree->wakeOne();
}

bool MoniteurMESA::isFinished()
{
    nbStop++;
    std::cout << nbStop << std::endl;
    if(nbStop == 5)
        return true;
    return false;
}
