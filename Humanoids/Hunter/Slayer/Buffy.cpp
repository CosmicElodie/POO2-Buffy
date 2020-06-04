/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Buffy.h
*/

#include <Action/Moving/Wander.h>
#include "Buffy.h"
#include "Hunter/Monster/Vampire.h"

Buffy::Buffy(size_t x, size_t y) : Hunter(ALIVE, REPRESENTATION, x, y, SPEED) {}

void Buffy::setAction(Field &field) {
    bool isPreyOnBoard = false;
    for(Humanoid * h : field.getHumanoids())
    {
        if(typeid(h) == (typeid(Vampire)))
        {
            isPreyOnBoard = true;
            break;
        }
    }

    if(isPreyOnBoard)
    {
        Hunter::setAction(field);
    }
    else {
        Wander * wander = new Wander(this);
        this->setNextAction(wander);
    }
}
