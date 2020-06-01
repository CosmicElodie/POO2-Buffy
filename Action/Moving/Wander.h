/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Wander.h
*/

#ifndef POO2_BUFFY_WANDER_H
#define POO2_BUFFY_WANDER_H


#include <cstdlib>
#include <Action/Action.h>

class Wander : public Action{
private :
    size_t speed;

public :
    /**
     * Cette action permet de se déplacer aléatoirement sur le plateau, selon une vitesse donnée.
     */
    Wander(size_t speed);

    virtual void execute(Field &f);

};


#endif //POO2_BUFFY_WANDER_H
