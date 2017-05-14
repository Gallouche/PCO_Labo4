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
        QList<int> listLengthTh = findThreadsLenght(size);
        QList<sortHandler <T>*> threads;

        int index = 0;
        QList<MoniteurMESA*> listMESA = QList<MoniteurMESA*>();
        for(int i = 0; i < nbThreads; ++i)
        {
            // on ajoute un sortHandler, avec comme index de base index,
            // et comme index final index + longueur -1, le moins 1 car si l'index est de 0 et la longueur 6
            // l'index final doit être le 5 (on compte le premier index) et non pas le 6
            int indexFinal = (index + listLengthTh.at(i) - 1);
            listMESA.push_back(new MoniteurMESA(indexFinal));
            if(i == 0)//pour le premier thread, pas besoin de moniteurMESA pour le premier index
            {
                threads.push_back(new sortHandler<T>(index, indexFinal, a, size, NULL, listMESA.at(i)));
            }
            else if(i == nbThreads-1)//si dernier thread pas besoin de moniteurMESA pour le dernier index
            {
                threads.push_back(new sortHandler<T>(index, indexFinal, a, size, listMESA.at(i-1), NULL));
            }
            else
            {
                    threads.push_back(new sortHandler<T>(index, indexFinal, a, size, listMESA.at(i-1) ,listMESA.at(i)));
            }
            index = indexFinal;
        }

        for(int i = 0; i < threads.length(); i++)
        {
            threads.at(i)->start();
        }
        for(int i = 0; i < threads.length(); i++)
        {
            threads.at(i)->wait();
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
