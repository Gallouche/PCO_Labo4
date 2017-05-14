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
        QList<sortHandler> threads = new QList<sortHandler>;

        for(int i = 0; i < nbThreads; ++i){
            if(i = 0 || i == (nbThreads-1)){

            }
            threads.push_back(new sortHandler(index,
                                              (index+tailleOpti),a));
        }
    }
};

#endif // BUBBLESORTTHREADED_H
