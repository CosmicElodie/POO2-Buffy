/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Humanoid.h
*/

#include "Humanoid.h"

Humanoid::Humanoid(bool alive, const char representation, size_t x, size_t y, size_t speed) :
        alive(alive), representation(representation),
        positionX(x), positionY(y), nextPositionX(x), nextPositionY(y),
        speed(speed) {}

Humanoid &Humanoid::operator=(const Humanoid &humanoid) {
    if (*this != humanoid) {
        this->alive = humanoid.alive;
        this->representation = humanoid.representation;
        this->positionX = humanoid.positionX;
        this->positionY = humanoid.positionY;
        this->speed = humanoid.speed;
    }
    return *this;
}

bool Humanoid::operator==(const Humanoid &humanoid) const {
    return (this->alive == humanoid.alive &&
            this->representation == humanoid.representation &&
            this->positionX == humanoid.positionX &&
            this->positionY == humanoid.positionY &&
            this->speed == humanoid.speed);
}

bool Humanoid::operator!=(const Humanoid &humanoid) const {
    return !(*this == humanoid);
}


const bool Humanoid::isAlive() const {
    return alive;
}

void Humanoid::executeAction(Field &field) {
    //positionX = nextPositionX;
    //positionY = nextPositionY;
    nextAction->execute(field);
}

char Humanoid::getRepresentation() const {
    return representation;
}

size_t Humanoid::getPositionX()  {
    return positionX;
}

size_t Humanoid::getPositionY() {
    return positionY;
}

size_t Humanoid::getSpeed() const {
    return speed;
}

void Humanoid::setNextAction(Action *nextAction) {
    Humanoid::nextAction = nextAction;
}

