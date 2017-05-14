#include "moniteurmesa.h"

MoniteurMESA::MoniteurMESA(int tailleTab):
    tailleTab(tailleTab),
{
    isFree = new QWaitCondition();

}

void MoniteurMESA::acquire(){
    mutex.lock();
}

void MoniteurMESA::release(){

}

bool MoniteurMESA::isFinished(){
    for(int i = 0; i < taskOver.size(); i++){
        if(!taskOver.at(i))
            return false;
    }
    return true;
}
