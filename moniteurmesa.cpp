#include "moniteurmesa.h"

MoniteurMESA::MoniteurMESA(int indexToWatch):
    indexToWatch(indexToWatch),
    isFree(true)
{
    isFree = new QWaitCondition();

}

void MoniteurMESA::acquire(){
    mutex.lock();
}

void MoniteurMESA::release(){

}

bool MoniteurMESA::isFinished(){
    //for(int i = 0; i < taskOver.size(); i++){
     //   if(!taskOver.at(i))
      //      return false;
    //}
    return true;
}
