/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Action.h
*/

#ifndef POO2_BUFFY_CRULL_LAGIER_ACTION_H
#define POO2_BUFFY_CRULL_LAGIER_ACTION_H

#include <cstdlib>
#include "Field.h"
class Field;
class Humanoid;


class Action {

protected:
    Humanoid * humanoid;
public:

    /**
     * Réalise une action fait par l'humain passé en paramètre.
     * @param humanoid : l'humain qui performe l'action.
     */
    explicit Action(Humanoid * humanoid);

     /**
     * Permet d'exucéuter l'action courant en influant sur l'environnement.
     * @param f : l'environnement courant.
     */
     virtual void execute(Field &f) = 0;

};

#endif //POO2_BUFFY_CRULL_LAGIER_ACTION_H
