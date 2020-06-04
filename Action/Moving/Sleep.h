/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Sleep.h
*/

#ifndef POO2_BUFFY_SLEEP_H
#define POO2_BUFFY_SLEEP_H

#include <Action/Action.h>

class Sleep : public Action {
private:

public:
    Sleep(Humanoid * humanoid);

    /**
     * Un humanoïde qui sleep ne fait rien d'autre que de rester sur place.
     * On initialise donc ses coordonnées à l'endroit où il est.
     * TODO : NEED REFACTOR AVEC WANDER
     * @param f : le field sur lequel évolue les humanoïdes.
     */
    void execute(Field &f) override;
};


#endif //POO2_BUFFY_SLEEP_H
