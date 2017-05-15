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
MoniteurMESA::MoniteurMESA(int indexToWatch):
    indexToWatch(indexToWatch),
    isFree(true)
{
    idFree = new QWaitCondition();
}

void MoniteurMESA::acquire()
{
        mutex.lock();
        idFree->wait(&mutex);
        mutex.unlock();
 }

void MoniteurMESA::release()
{
    mutex.lock();
    idFree->wakeOne();
    mutex.unlock();
}

bool MoniteurMESA::isFinished()
{
    nbStop++;
    std::cout << nbStop << std::endl;
    if(nbStop == 5)
        return true;
    return false;
}
