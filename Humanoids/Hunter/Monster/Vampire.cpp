/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Monster.h
*/

#include <Action/Moving/Sleep.h>
#include "Vampire.h"

Vampire::Vampire(size_t x, size_t y) : Hunter(ALIVE, REPRESENTATION, x, y, SPEED) {}

void Vampire::setAction(Field& field) {
    bool isPreyOnBoard = false;
    for(Humanoid * h : field.getHumanoids())
    {
        if(h->getRepresentation() == 'H')
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
        Sleep * sleep = new Sleep((Humanoid*)this);
        this->setNextAction(sleep);
    }
}