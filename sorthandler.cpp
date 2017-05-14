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
   while(true)
   {
       bool changes = false;
       T swap;
       for (int c = size - 1 ; c > 0; --c)
       {
           for (int d = 0 ; d < c; ++d)
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
               else
               {
                   if(firstIndex != 0)
                   {
                       firstMonitor->release();
                   }
                   if(lastIndex != size-1)
                   {
                       lastMonitor->release();
                   }
               }
               if (tab[d] > tab[d+1]) /* For decreasing order use < */
               {
                   changes  = true; //des changements vont être effectués dans le tableau
                   swap     = tab[d];
                   tab[d]   = tab[d+1];
                   tab[d+1] = swap;
               }
           }
       }

       if(changes == false)
       {
           //std::cout << "bbbbb" << std::endl;
           //break;
       }
   }
}
