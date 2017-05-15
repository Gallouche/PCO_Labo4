/**
 * -------------------------------------------------------------------------------
 * Laboratoire : PCO - Labo4
 * Fichier     : bubblesortthreaded.h
 * Auteur(s)   : Théo Gallandat & Kevin Moreira
 * Date        : 15/05/2017
 *
 * But         : Classe qui tri un tableau séparant la tache en un nombre de
 *               threads donné.
 * Remarque(s) : Le principe adopter est de découper le tableau en fonction
 *              du nombre de threads voulu, et ce de façon la plus égale possible
 *              grace a la fonction findThreadsLenght que nous avons crée.
 *              Ensuite il s'agit de lancer des threads sorthandler afin qu'ils
 *              effectue le tri du sous tableau que qu'il leur est confié.
 *              Pour chaque index critique, nous crée un moniteur qui va gerer
 *              l'acces a la donnée, et ils sont passer en paramètre au 2 thread
 *              qui partage l'index critique.
 -------------------------------------------------------------------------------
 */
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
    //nombre de threads souhaité
    int nbThreads;
public:

    BubbleSortThreaded(int nbThreads):
        nbThreads(nbThreads)
    {}

    virtual void sort(T a[], qint64 size)
    {
        //liste des tailles des sous tableau
        QList<int> listLengthTh = findThreadsLenght(size);

        //liste des threads sortHandler
        QList<sortHandler <T>*> threads;

        //index du tableau initialisé au debut de ce dernier
        int index = 0;

        //List des moniteurs
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

        //on lance les threads
        for(int i = 0; i < threads.length(); i++)
        {
            threads.at(i)->start();
        }
        //on attend sur les threads
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
