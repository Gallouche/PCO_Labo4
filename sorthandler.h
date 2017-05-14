#ifndef SORTHANDLER_H
#define SORTHANDLER_H

#include <QThread>

template<typename T>
class sortHandler
{
public:
    sortHandler(int firstIndex,int lastIndex,T tab[]);
};

#endif // SORTHANDLER_H
