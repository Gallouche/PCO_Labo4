/**
 * -------------------------------------------------------------------------------
 * Laboratoire : PCO - Labo4
 * Fichier     : sorthandler.h
 * Auteur(s)   : Théo Gallandat & Kevin Moreira
 * Date        : 15/05/2017
 *
 * But         : Classe qui fourni un thread pour le tri d'un sous tableau
 * Remarque(s) : SortHandler est notre thread, qui va effectuer le tri de l'espace
 *              du tableau qui lui sera attribué. Cet espace du tab est compris
 *              entre firstIndex et lastIndex. Le thread tourne en boucle, trie
 *              sa partie et a l'aide des moniteurs firstmoniteur et lastmoniteur,
 *              il vérifie ses acces aux un ou deux index qu'il partage avec un autre
 *              thread (un si le thread est soit le premier, soit le dernier, car le
 *              firstIndex du premier n'est pas partagé et le lastIndex du dernier
 *              thread non plus). Pour sortir de la boucle, et terminer le thread,
 *              le thread doit avertir lorsqu'il a effectué ou pas des changements
 *              sur le tableau, il informe les moniteurs qui ensuite decider si
 *              les threads doivent s'arreter ou non.
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
    MoniteurMESA* firstMonitor; //premier moniteur qui va verifier le firstIndex
                                //(index qui sont partagés sont tjr le 1er ou dernier)
    MoniteurMESA* lastMonitor; //deuxieme moniteur qui va verifier le lastIndex
                                //(index qui sont partagés sont tjr le 1er ou dernier)
public:
    /**
     * @brief Constructeur de sortHandler
     * @param firstIndex : debut du sous tableau
     * @param lastIndex : fin du sous tableau
     * @param tab : tableau à trier
     * @param size : taille du tableau
     * @param fisrtMonitor: moniteur de l'index partagé du début du sous tableau
     * @param lastMonitor: moniteur de l'index de partagé fin du sous tableau
     */
    sortHandler(int firstIndex,int lastIndex,T* tab, qint64 size,
                MoniteurMESA* fisrtMonitor, MoniteurMESA* lastMonitor);
    /**
     * @brief redéfinition de la fonction run de Thread
     */
    void run();
};

#include "sorthandlerImpl.h"

#endif // SORTHANDLER_H
