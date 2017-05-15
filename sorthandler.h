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
    int firstIndex; //premier index de la partie du tableau que ce thread va devoir gerer
    int lastIndex;  //dernier index de la partie du tableau que ce thread va devoir gerer
    T* tab;         //tableau a trier
    qint64 size;    //taille du tableau a trier
    MoniteurMESA* firstMonitor; //premier moniteur qui va verifier le firstIndex (index qui sont partagés sont tjr le 1er ou dernier)
    MoniteurMESA* lastMonitor; //deuxieme moniteur qui va verifier le lastIndex (index qui sont partagés sont tjr le 1er ou dernier)
public:
    sortHandler(int firstIndex,int lastIndex,T* tab, qint64 size,
                MoniteurMESA* fisrtMonitor, MoniteurMESA* lastMonitor);
    void run();
};

#include "sorthandlerImpl.h"

#endif // SORTHANDLER_H
