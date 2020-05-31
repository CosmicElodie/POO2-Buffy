/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Humanoid.h
*/

#include "Humanoid.h"

Humanoid::Humanoid(bool alive, const char representation, size_t x, size_t y, size_t speed) :
        alive(alive), representation(representation), positionX(x), positionY(y), speed(speed) {}

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
    //TODO
}

void Humanoid::move(Field &field) {
    //TODO
}

char Humanoid::getRepresentation() const {
    return representation;
}
