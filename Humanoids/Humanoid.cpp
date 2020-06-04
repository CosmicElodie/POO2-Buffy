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

void Humanoid::setAlive(bool alive) {
    Humanoid::alive = alive;
}

void Humanoid::setNextPositionX(size_t nextPositionX) {
    Humanoid::nextPositionX = nextPositionX;
}

void Humanoid::setNextPositionY(size_t nextPositionY) {
    Humanoid::nextPositionY = nextPositionY;
}

size_t Humanoid::getNextPositionX() const {
    return nextPositionX;
}

size_t Humanoid::getNextPositionY() const {
    return nextPositionY;
}

void Humanoid::setNextAction(Action *nextAction) {
    this->nextAction = nextAction;
}

void Humanoid::setPositionX(size_t positionX) {
    Humanoid::positionX = positionX;
}

void Humanoid::setPositionY(size_t positionY) {
    Humanoid::positionY = positionY;
}

