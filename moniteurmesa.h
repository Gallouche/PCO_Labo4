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
    int tailleTab;
    bool isFree;

public:
    MoniteurMESA(int tailleTab);
    virtual ~MoniteurMESA(){}
    void acquire();
    void release();
    bool isFinished();

};

#endif // MONITEURMESA_H
