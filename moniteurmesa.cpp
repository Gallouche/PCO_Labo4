#include "moniteurmesa.h"
#include <iostream>
MoniteurMESA::MoniteurMESA(int indexToWatch):
    indexToWatch(indexToWatch),
    isFree(true)
{}

void MoniteurMESA::acquire()
{
        mutex.lock();
        std::cout << "aall"<< std::endl;
        idFree.wait(&mutex);
        std::cout << "bbbbba"<< std::endl;
        mutex.unlock();
 }

void MoniteurMESA::release()
{
    idFree.wakeOne();
}

bool MoniteurMESA::isFinished(){
    //for(int i = 0; i < taskOver.size(); i++){
     //   if(!taskOver.at(i))
      //      return false;
    //}
    return true;
}
