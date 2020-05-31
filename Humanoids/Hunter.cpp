/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Hunter.h
*/

#include <cstring>
#include "Hunter.h"

Hunter::Hunter(size_t alive, const char representation, size_t x, size_t y, const size_t speed, const char _preys[]) :
Humanoid(alive, representation, x, y, speed){
    strcpy(preys, _preys);
}

void Hunter::setAction(Field &field) {

}

void Hunter::move(Field &field) {
    Humanoid::move(field);
}
