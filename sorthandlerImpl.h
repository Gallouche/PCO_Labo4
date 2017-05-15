/**
 * -------------------------------------------------------------------------------
 * Laboratoire : PCO - Labo4
 * Fichier     : sorthandlerImpl.h
 * Auteur(s)   : Théo Gallandat & Kevin Moreira
 * Date        : 15/05/2017
 *
 * But         : Implémentation du thread sorthandler
 * Remarque(s) : R.A.S.
 -------------------------------------------------------------------------------
 */
#include "sorthandler.h"
#include <iostream>
template<typename T>
sortHandler<T>::sortHandler(int firstIndex,int lastIndex,T* tab, qint64 size,
                            MoniteurMESA* firstMonitor, MoniteurMESA* LastMonitor):
    firstIndex(firstIndex),
    lastIndex(lastIndex),
    tab(tab),
    size(size),
    firstMonitor(firstMonitor),
    lastMonitor(LastMonitor)
{}

template<typename T>
void sortHandler<T>::run()
{
   bool finished = true;
   while(finished)
   {
       bool changes = false;
       T swap;
       for (int c = lastIndex ; c > firstIndex; --c)
       {
           for (int d = firstIndex ; d < c; ++d)
           {
               //cas ou d est au firstIndex, et ou firstIndex est different du tout premier index du tableau,
               //donc pas besoin de gerer les moniteurs car il n'y a pas de double acces à cette index
               // nous devons demander au moniteur si l'index est utilisé (mise en queue par le moniteur au cas ou utilisé)
               if(firstIndex != 0 && d == firstIndex)
               {
                    firstMonitor->acquire();
               }
               //cas ou c est au lastIndex et ou il n'est pas le tout dernier element du tableau (au quel cas il
               //n' y aurait pas besoin de verifier, pas d'acces multiple a cet index), nous appelons acces de ce monitor
               else if(lastIndex != size-1 && c == lastIndex)
               {
                   lastMonitor->acquire();
               }
               if (tab[d] > tab[d+1]) /* For decreasing order use < */
               {
                   changes  = true; //des changements vont être effectués dans le tableau
                   swap     = tab[d];
                   tab[d]   = tab[d+1];
                   tab[d+1] = swap;
               }
               if(firstIndex != 0 && d == firstIndex)
               {
                   firstMonitor->release();
               }
               else if(lastIndex != size-1 && c == lastIndex)
               {
                   lastMonitor->release();
               }
           }
       }
       if(!changes)
       {
           if(firstIndex != 0)
                finished = !firstMonitor->isFinished();
           if(lastIndex != size-1)
               finished = !lastMonitor->isFinished();
       }
   }
   std::cout << "aass" <<std::endl;

}
