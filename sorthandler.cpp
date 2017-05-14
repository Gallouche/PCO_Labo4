#include "sorthandler.h"

template<typename T>
sortHandler<T>::sortHandler(int firstIndex,int lastIndex,T* tab, qint64 size):
    firstIndex(firstIndex),
    lastIndex(lastIndex),
    tab(tab),
    size(size)
{}

template<typename T>
void sortHandler<T>::run(){
   while(true){
       T swap;
       for (int c = size - 1 ; c > 0; --c)
       {
           for (int d = 0 ; d < c; ++d)
           {
               if (tab[d] > tab[d+1]) /* For decreasing order use < */
               {
                   swap       = tab[d];
                   tab[d]   = tab[d+1];
                   tab[d+1] = swap;
               }
           }
       }
   }
}
