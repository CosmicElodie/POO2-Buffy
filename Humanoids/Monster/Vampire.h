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
    const char ALIVE = false;
    const char REPRESENTATION = 'V';
    const char ENNEMI[2] = {'B', 'H'};
    const size_t SPEED = 2;
};


#endif //POO2_BUFFY_CRULL_LAGIER_VAMPIRE_H
