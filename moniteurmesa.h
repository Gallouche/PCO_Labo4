/**
 * -------------------------------------------------------------------------------
 * Laboratoire : PCO - Labo4
 * Fichier     : moniteurmesa.h
 * Auteur(s)   : Théo Gallandat & Kevin Moreira
 * Date        : 15/05/2017
 *
 * But         : Classe qui fourni un moniteur mesa pour la gestion des sections
 *               critiques.
 * Remarque(s) : R.A.S.
 -------------------------------------------------------------------------------
 */
#ifndef MONITEURMESA_H
#define MONITEURMESA_H

#include <QMutex>
#include <QVector>
#include <QWaitCondition>

class MoniteurMESA
{
protected:
    QMutex mutex;
    QWaitCondition* idFree;
    static QVector<bool> taskOver;
    int indexToWatch;
    bool isFree;
    int nbStop;

public:
    MoniteurMESA(int indexToWatch);
    virtual ~MoniteurMESA(){}
    void acquire();
    void release();
    bool isFinished();

};

#endif // MONITEURMESA_H
