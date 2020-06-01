/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Hunt.h
*/

#ifndef POO2_BUFFY_HUNT_H
#define POO2_BUFFY_HUNT_H


#include <Action/Action.h>

class Hunt : public Action {

private :

public :
    Hunt(size_t speed);
    virtual void execute(Field &f);
};


#endif //POO2_BUFFY_HUNT_H
