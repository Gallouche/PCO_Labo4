#ifndef BUBBLESORTTHREADED_H
#define BUBBLESORTTHREADED_H

#include <isort.h>
#include "moniteurmesa.h"
#include <QList>
#include "sorthandler.h"

template<typename T>
class BubbleSortThreaded : public ISort<T>
{
private:
    int nbThreads;

public:

    BubbleSortThreaded(int nbThreads):
        nbThreads(nbThreads)
    {}

    virtual void sort(T a[], qint64 size)
    {
        int tailleOpti = size/nbThreads;
        int index = 0;
        QList<sortHandler<T>*> threads;

        for(int i = 0; i < nbThreads; ++i){

            threads.push_back(new sortHandler<T>(index,
                                              (index+tailleOpti),a, size));
        }
    }
};

#endif // BUBBLESORTTHREADED_H
