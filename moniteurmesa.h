#ifndef MONITEURMESA_H
#define MONITEURMESA_H

#include "QMutex"
#include "QWaitCondition"

class MoniteurMESA
{
protected:
    QMutex mutex;
    QWaitCondition cond;
    bool finish;

public:
    MoniteurMESA();
    virtual ~MoniteurMESA(){}

};

#endif // MONITEURMESA_H
