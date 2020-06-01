/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Hunter.h
*/

#include <cstring>
#include "Hunter.h"

Hunter::Hunter(size_t alive, const char representation, size_t x, size_t y, const size_t speed) :
Humanoid(alive, representation, x, y, speed){}

void Hunter::setAction(Field &field) {

}

void Hunter::move(Field &field) {
    Humanoid::move(field);
}
