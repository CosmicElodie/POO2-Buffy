/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Wander.h
*/

#include "Wander.h"
#include "Action/Utils.h"

void Wander::execute(Field &f) {
    humanoid->setPositionX(humanoid->getNextPositionX());
    humanoid->setPositionY(humanoid->getNextPositionY());
}

Wander::Wander(Humanoid *humanoid) : Action(humanoid) {
    size_t direction = rand() % 8;
    walkTowards(direction);
}

void Wander::walkTowards(size_t direction) {
    switch(direction) {
        case (int)Utils::Direction::TOP :
            humanoid->setNextPositionY(humanoid->getPositionY()+humanoid->getSpeed());
            break;
        case (int)Utils::Direction::TOP_RIGHT :
            humanoid->setNextPositionX(humanoid->getPositionX()+humanoid->getSpeed());
            humanoid->setNextPositionY(humanoid->getPositionY()+humanoid->getSpeed());
            break;
        case (int)Utils::Direction::RIGHT :
            humanoid->setNextPositionX(humanoid->getPositionX()+humanoid->getSpeed());
            break;
        case (int)Utils::Direction::BOTTOM_RIGHT :
            humanoid->setNextPositionX(humanoid->getPositionX()+humanoid->getSpeed());
            humanoid->setNextPositionY(humanoid->getPositionY()-humanoid->getSpeed());
            break;
        case (int)Utils::Direction::BOTTOM :
            humanoid->setNextPositionY(humanoid->getPositionY()-humanoid->getSpeed());
            break;
        case (int)Utils::Direction::BOTTOM_LEFT :
            humanoid->setNextPositionX(humanoid->getPositionX()-humanoid->getSpeed());
            humanoid->setNextPositionY(humanoid->getPositionY()-humanoid->getSpeed());
            break;
        case (int)Utils::Direction::LEFT :
            humanoid->setNextPositionX(humanoid->getPositionX()-humanoid->getSpeed());
            break;
        case (int)Utils::Direction::TOP_LEFT :
            humanoid->setNextPositionX(humanoid->getPositionX()-humanoid->getSpeed());
            humanoid->setNextPositionY(humanoid->getPositionY()+humanoid->getSpeed());
            break;
        default:
            break;
    }
}
