/**
 * -------------------------------------------------------------------------------
 * Laboratoire : PCO - Labo4
 * Fichier     : moniteurmesa.cpp
 * Auteur(s)   : Théo Gallandat & Kevin Moreira
 * Date        : 15/05/2017
 *
 * But         : Implémentation du moniteur mesa
 * Remarque(s) : R.A.S.
 -------------------------------------------------------------------------------
 */
#include "moniteurmesa.h"
#include <iostream>

/**
 * @brief Constructeur
 * @param indexToWatch index que l'on veu proteger
 */
MoniteurMESA::MoniteurMESA(int indexToWatch):
    indexToWatch(indexToWatch),
    isFree(true),
    nbStop(0)
{
    idFree = new QWaitCondition();
}

/**
 * @brief acces a la donnée critique
 */
void MoniteurMESA::acquire()
{
    mutex.lock();
    //Si la donnée est déja en cours d'utilisation par un autre
    //thread
    if(!isFree)
        //met le thread en attente
        idFree->wait(&mutex);
    else
        //sinon on signale que la donnée est utilisée.
        isFree = false;
    mutex.unlock();
}

/**
 * @brief relachement de la donnée critique
 */
void MoniteurMESA::release()
{
    //on dit que la donnée est libre et on reveille
    //un thread en attente.
    mutex.lock();
    isFree = true;
    idFree->wakeOne();
    mutex.unlock();
}

bool MoniteurMESA::isFinished(bool ecremFin)
{
    mutex.lock();

    bool finished = false;
    if(ecremFin)
        nbStop++;
    else if(!ecremFin && nbStop > 0)
        nbStop--;
    if(nbStop >= 50)
    {
        finished = true;
    }
    mutex.unlock();
    return finished;
}
