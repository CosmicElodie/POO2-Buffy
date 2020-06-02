/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Kill.h
*/

#ifndef POO2_BUFFY_KILL_H
#define POO2_BUFFY_KILL_H


#include "Action.h"

class Kill : public Action {

private:
    //Référence sur le chasseur
    Hunter *hunter;

    //Référence sur la proie
    Humanoid *prey;

public:
    /**
     * Permet à un chasseur de tuer une proie
     * @param speed : la vitesse du chasseur
     * @param hunter : le chasseur
     * @param prey : la proie
     */
    Kill(size_t speed, Hunter *hunter, Humanoid *prey);
    virtual void execute(Field &f);

};


#endif //POO2_BUFFY_KILL_H
