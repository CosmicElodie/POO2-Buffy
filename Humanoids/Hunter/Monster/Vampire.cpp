/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Monster.h
*/

#include <Action/Moving/Wander.h>
#include "Vampire.h"
#include "Hunter/Slayer/Buffy.h"
#include "Victim/LambdaHuman.h"

Vampire::Vampire(size_t x, size_t y) : Hunter(ALIVE, REPRESENTATION, x, y, SPEED) {}

void Vampire::setAction(Field& field) {
    bool isPreyOnBoard = false;
    for(Humanoid * h : field.getHumanoids())
    {
        if(typeid(h) == (typeid(LambdaHuman)))
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
    }
}