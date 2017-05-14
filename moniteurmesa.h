#ifndef MONITEURMESA_H
#define MONITEURMESA_H

#include <QMutex>
#include <QVector>
#include <QWaitCondition>

class MoniteurMESA
{
protected:
    QMutex mutex;
    QWaitCondition isFree;
    static QVector<bool> taskOver;
    int tailleTab;
public:
    MoniteurMESA(int tailleTab);
    virtual ~MoniteurMESA(){}
    void acquire();
    void release();
    bool isFinished();

};

#endif // MONITEURMESA_H
