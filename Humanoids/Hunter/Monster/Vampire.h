/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Monster.h
*/

#ifndef POO2_BUFFY_CRULL_LAGIER_VAMPIRE_H
#define POO2_BUFFY_CRULL_LAGIER_VAMPIRE_H

#include "Humanoids/Hunter/Hunter.h"

class Vampire : public Hunter {
private:
    static const char ALIVE = false;
    static const char REPRESENTATION = 'V';
    const char PREYS[2] = {'B', 'H'};
    static const size_t SPEED = 2;

public :
    Vampire(size_t x, size_t y);
};


#endif //POO2_BUFFY_CRULL_LAGIER_VAMPIRE_H
