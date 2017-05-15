/**
 * -------------------------------------------------------------------------------
 * Laboratoire : PCO - Labo4
 * Fichier     : sorthandler.h
 * Auteur(s)   : Théo Gallandat & Kevin Moreira
 * Date        : 15/05/2017
 *
 * But         : Classe qui fourni un thread pour le tri d'un sous tableau
 * Remarque(s) : R.A.S.
 -------------------------------------------------------------------------------
 */
#ifndef SORTHANDLER_H
#define SORTHANDLER_H

#include <QThread>
#include "moniteurmesa.h"
template<typename T>
class sortHandler : public QThread
{
    int firstIndex;
    int lastIndex;
    T* tab;
    qint64 size;
    MoniteurMESA* firstMonitor;
    MoniteurMESA* lastMonitor;
public:
    sortHandler(int firstIndex,int lastIndex,T* tab, qint64 size,
                MoniteurMESA* fisrtMonitor, MoniteurMESA* lastMonitor);
    void run();
};
template class sortHandler<int>;
#endif // SORTHANDLER_H
