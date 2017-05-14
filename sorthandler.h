#ifndef SORTHANDLER_H
#define SORTHANDLER_H

#include <QThread>
#include "moniteurmesa.h"
template<typename T>
class sortHandler : public QThread
{
    int firstIndex;
    int lastIndex;
    T* tab;
    qint64 size;
    MoniteurMESA* firstMonitor;
    MoniteurMESA* lastMonitor;
public:
    sortHandler(int firstIndex,int lastIndex,T* tab, qint64 size,
                MoniteurMESA* fisrtMonitor, MoniteurMESA* lastMonitor);
    void run();
};
template class sortHandler<int>;
#endif // SORTHANDLER_H
