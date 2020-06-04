/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Hunter.h
*/

#include <algorithm>
#include <Action/Moving/Hunt.h>
#include <Action/Moving/Wander.h>
#include "Monster/Vampire.h"

Hunter::Hunter(size_t alive, const char representation, size_t x, size_t y, const size_t speed) :
        Humanoid(alive, representation, x, y, speed) {

    prey = nullptr;
}

void Hunter::setAction(Field &field) {

    prey = (findClosestPrey(field));

    //On créé un objet "Hunt" avec la proie référencée.
    Hunt * hunt = new Hunt(this, prey);
    this->setNextAction(hunt);
}

float
Hunter::calculateDistance(Hunter *hunter, Humanoid *prey) {
    return sqrt(
            pow(hunter->getPositionX() - hunter->getPositionY(), 2) +
            pow(prey->getPositionX() - prey->getPositionY(), 2));
}

Humanoid *
Hunter::findClosestPrey(Field &field) {
    const char preyRepresentation = ((this->getRepresentation() == 'B') ? 'V' : 'H');

    //on initialise à une valeur qui sera forcément hors des bornes du terrain.
    float distance = (std::max(field.getHeight(),field.getWidth()) + 1),
    newDistance;
    Humanoid *closestPrey = nullptr;

    for (auto &potentialPrey : field.getHumanoids()) {
        newDistance = calculateDistance(this,
                                        potentialPrey);
        if ((distance > newDistance) &&
            (potentialPrey->getRepresentation() == preyRepresentation)) {
            closestPrey = potentialPrey;
            distance = newDistance;
        }
    }
    return closestPrey;
}

