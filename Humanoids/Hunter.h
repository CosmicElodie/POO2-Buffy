/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Hunter.h
*/

#ifndef POO2_BUFFY_CRULL_LAGIER_HUNTER_H
#define POO2_BUFFY_CRULL_LAGIER_HUNTER_H

#include "Humanoid.h"

class Hunter : public Humanoid {

private:
    //TODO voir comment faire pour multiples proies

public:
//ALIVE, REPRESENTATION, x, y, SPEED, ENNEMI
    Hunter(size_t alive, const char representation, size_t x, size_t y, const size_t speed);

    virtual void setAction(Field& field);

    virtual void move(Field &field);

};


#endif //POO2_BUFFY_CRULL_LAGIER_HUNTER_H
