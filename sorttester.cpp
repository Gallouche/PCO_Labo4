
#include <iostream>
#include <ctime>


#include "sorttester.h"


#include "bubblesort.h"
#include "bubblesortthreaded.h"


SortTester::SortTester()
{
}

void SortTester::test(qint64 tabSize, int nbThreads)
{
    srand(time(0));

    int *tab = new int[tabSize];

    for(qint64 i=0;i<tabSize;i++)
        tab[i] = rand();

    // A remplacer par BubbleSortThreaded
    //BubbleSort<int> sorter;
    BubbleSortThreaded<int> sorter(nbThreads);

    sorter.sort(tab,tabSize);

    int initial = tab[0];
    bool error  = false;

    for(qint64 i=0;i<tabSize;i++)
    {
        if(initial > tab[i])
        {
            error = true;
            break;
        }
        initial = tab[i];
    }

    if(error)
       std::cout << "ERREUR " << std::endl;
    else
       std::cout << "Tri valide " << std::endl;

    delete[] tab;
}
