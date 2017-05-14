#ifndef MONITEURMESA_H
#define MONITEURMESA_H

#include <QMutex>
#include <QVector>
#include <QWaitCondition>

class MoniteurMESA
{
protected:
    QMutex mutex;
    QWaitCondition idFree;
    static QVector<bool> taskOver;
    int indexToWatch;
    bool isFree;

public:
    MoniteurMESA(int indexToWatch);
    virtual ~MoniteurMESA(){}
    void acquire();
    void release();
    bool isFinished();

};

#endif // MONITEURMESA_H
