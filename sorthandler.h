#ifndef SORTHANDLER_H
#define SORTHANDLER_H

#include <QThread>

template<typename T>
class sortHandler
{
public:
    sortHandler(int firstIndex,int lastIndex,T tab[]);
};
template class sortHandler<int>;
#endif // SORTHANDLER_H
