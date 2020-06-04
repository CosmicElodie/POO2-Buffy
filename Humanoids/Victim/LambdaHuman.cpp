/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : LambdaHuman.h
*/

#include <Action/Moving/Wander.h>
#include "LambdaHuman.h"


LambdaHuman::LambdaHuman(size_t x, size_t y) : Humanoid(ALIVE, REPRESENTATION, x, y, SPEED) { }

void LambdaHuman::setAction(Field &field) {
    Wander * wander = new Wander(this);
    setNextAction(wander);
}
