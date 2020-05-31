/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Buffy.h
*/

#ifndef POO2_BUFFY_CRULL_LAGIER_BUFFY_H
#define POO2_BUFFY_CRULL_LAGIER_BUFFY_H

#include "../Hunter.h"

class Buffy : public Hunter {
private:
    const char ALIVE = true;
    const char REPRESENTATION = 'B';
    const char PREYS[1] = {'V'};
    const size_t SPEED = 2;

public:
    Buffy(size_t x, size_t y);

    virtual void setAction(Field& field);

    virtual void move(Field &field);

};


#endif //POO2_BUFFY_CRULL_LAGIER_BUFFY_H
