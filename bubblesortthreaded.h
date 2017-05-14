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
        int tailleOpti = floor(size/nbThreads) + 1;
        //int tailleLastThread = size - tailleOpti;
        QList<int> listLengthTh = findThreadsLenght(size);
        QList<sortHandler <T>> threads;

        for(int i = 0; i < nbThreads; ++i)
        {

            //threads.push_back(new sortHandler<T>(index,
                                              //(index+tailleOpti),a));
        }
    }
    /**
     * @brief findThreadsLenght cette fonction permet de calculer la taille pour chaque longueur que chaque thread va calculer.
     * si nous faisions un basique length/size, le dernier thread aurait une taille differente (la plupart du temps) des premiers threads
     * Nous avons donc cette fonction qui va calculer la premiere longueur de thread et ensuite, la garder pour le premier thread et ensuite,
     * enlever ce thread du calcul. On soustrait sa longueur -1 à la taille, et on recommence le calcul pour les n-1 threads suivants avec la nouvelle taille.
     * cela va armoniser les taillles des threads.
     * @return une liste des longueur pour chacun des threads.
     */
    QList<int> findThreadsLenght(qint64 size)
    {
        QList<int> listLengthTh;
        qint64 currentSize = size;
        int currentNbTh = nbThreads;

        for(int i = 0; i < nbThreads; i++)
        {
            int lenghtTh = ceil( ( currentSize + (currentNbTh-1) )/currentNbTh );
            listLengthTh.push_back(lenghtTh);
            currentSize = currentSize - (lenghtTh - 1);
            currentNbTh--;
        }
        return listLengthTh;
    }
};

#endif // BUBBLESORTTHREADED_H
