/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Hunter.h
*/

#include <Action/Moving/Hunt.h>
#include <Action/Moving/Wander.h>
#include "Monster/Vampire.h"
#include "Victim/LambdaHuman.h"
#include "Hunter.h"

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
Hunter::calculateDistance(Hunter * hunter, Humanoid * prey) {
    return sqrt(
            pow(hunter->getPositionX() - hunter->getPositionY(), 2) +
            pow(prey->getPositionX() - prey->getPositionY(), 2));
}

Humanoid *
Hunter::findClosestPrey(Field &field) {
    const std::type_info *preyType = (this->getRepresentation() == 'B') ? &(typeid(Vampire)) : &(typeid(LambdaHuman));

    float distance = -1, newDistance = -1;
    Humanoid *current_prey = nullptr;

    for (auto &prey : field.getHumanoids()) {
        newDistance = calculateDistance(this,
                                        prey);
        if (((distance <= -1) || (distance > newDistance)) && typeid(*prey) == *preyType) {
            current_prey = prey;
            distance = newDistance;
        }
    }
    return current_prey;
}

