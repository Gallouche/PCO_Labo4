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
    isFree(true),
    nbStop(0)
{
    idFree = new QWaitCondition();
}

void MoniteurMESA::acquire()
{
        mutex.lock();
        if(!isFree)
            idFree->wait(&mutex);
        else
            isFree = false;
        mutex.unlock();
 }

void MoniteurMESA::release()
{
    mutex.lock();
    isFree = true;
    idFree->wakeOne();
    mutex.unlock();
}

bool MoniteurMESA::isFinished()
{
    mutex.lock();

    bool finished = false;
    nbStop++;
    if(nbStop == 5)
    {
        std::cout << "fini" << std::endl;
        finished = true;
    }
    mutex.unlock();
    return finished;
}
