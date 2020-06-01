/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Lambda.h
*/

#include "Lambda.h"



Lambda::Lambda(size_t x, size_t y) : Humanoid(ALIVE, REPRESENTATION, x, y, SPEED) { }

void Lambda::setAction(Field &field) {

}

void Lambda::move(Field &field) {
    Humanoid::move(field);
}
