/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Action.h
*/

#ifndef POO2_BUFFY_CRULL_LAGIER_ACTION_H
#define POO2_BUFFY_CRULL_LAGIER_ACTION_H

#include <cstdlib>

class Field;
class Action {

private:

public:
    
    /**
     * Permet d'exucéuter l'action courant en influant sur l'environnement.
     * @param f : l'environnement courant.
     */
    void execute(Field &f);

};


#endif //POO2_BUFFY_CRULL_LAGIER_ACTION_H
