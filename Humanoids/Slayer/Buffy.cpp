/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Buffy.h
*/

#include "Buffy.h"

Buffy::Buffy(size_t x, size_t y) : Hunter(ALIVE, REPRESENTATION, x, y, SPEED, ENNEMI) {

}

void Buffy::setAction(Field &field) {
    Hunter::setAction(field);
}

void Buffy::move(Field &field) {
    Hunter::move(field);
}
