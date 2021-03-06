/**
 * -------------------------------------------------------------------------------
 * Laboratoire : PCO - Labo4
 * Fichier     : moniteurmesa.h
 * Auteur(s)   : Théo Gallandat & Kevin Moreira
 * Date        : 15/05/2017
 *
 * But         : Classe qui fourni un moniteur mesa pour la gestion des sections
 *               critiques.
 * Remarque(s) : Les 2 thread vont demander des acces au moniteur qui va soit leur
 *               donner l'acces, soit les faire attendre.
 *               Nous avons rencontrer des probleme pour l'arret des tris, nous avons
 *               donc (pour ne pas rester bloquer) qu'apres un certain nombres de tours
 *               sans changement dans le tableau, le tri est fini et le thread le signal
 *               au moniteur. Ce nombre est arbitraire
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
    //index que l'on va proteger
    int indexToWatch;
    //bool pour savoir si l'acces sur la variable est libre ou pas
    bool isFree;
    //compteur de tours pour l'arret du tri
    int nbStop;

public:
    MoniteurMESA(int indexToWatch);
    virtual ~MoniteurMESA(){}
    //demande d'acces a la variable
    void acquire();
    //relachement de la variable
    void release();
    //savoir si le travail est terminé
    bool isFinished(bool ecremFin);

};

#endif // MONITEURMESA_H
