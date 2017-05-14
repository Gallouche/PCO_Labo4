#ifndef SORTHANDLER_H
#define SORTHANDLER_H

#include <QThread>

template<typename T>
class sortHandler : public QThread
{
    int firstIndex;
    int lastIndex;
    T* tab;
    qint64 size;
public:
    sortHandler(int firstIndex,int lastIndex,T* tab, qint64 size);
    void run();
};

template class sortHandler<int>;


#endif // SORTHANDLER_H
