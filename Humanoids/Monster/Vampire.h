/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Monster.h
*/

#ifndef POO2_BUFFY_CRULL_LAGIER_VAMPIRE_H
#define POO2_BUFFY_CRULL_LAGIER_VAMPIRE_H

#include "../Hunter.h"

class Vampire : public Hunter {
private:
    const char ALIVE = false;
    const char REPRESENTATION = 'V';
    const char PREYS[2] = {'B', 'H'};
    const size_t SPEED = 2;

public :
    Vampire(size_t x, size_t y);
};


#endif //POO2_BUFFY_CRULL_LAGIER_VAMPIRE_H
