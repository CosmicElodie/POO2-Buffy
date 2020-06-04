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

class Wander : public Action {
private :

public :
    /**
     * Cette action permet de se déplacer aléatoirement sur le plateau, selon une vitesse donnée.
     */
    Wander(Humanoid * humanoid);

    virtual void execute(Field &f);

    void walkTowards(size_t direction);
};


#endif //POO2_BUFFY_WANDER_H
