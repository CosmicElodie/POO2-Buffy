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
    //Référence sur la proie
    Humanoid * prey;


public :
    Hunt(Humanoid * hunter, Humanoid * prey);

    virtual void execute(Field &f);

    const bool isKillable() const;
};


#endif //POO2_BUFFY_HUNT_H
