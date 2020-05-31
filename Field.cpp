/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Field.h
*/

#include <list>
#include <iostream>
#include <iomanip>
#include "Field.h"

Field::Field() : turn(0), width(50), height(50) {}

Field::Field(const std::list<Humanoid *> &humanoids, size_t width, size_t height) : humanoids(humanoids), width(width), height(height){}

int Field::nextTurn()
{
// Déterminer les prochaines actions
    for (std::list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end(); it++)
        (*it)->setAction(*this);
// Executer les actions
    for (std::list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end(); it++)
        (*it)->executeAction(*this);
// Enlever les humanoides tués
    for (std::list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end(); )
        if (!(*it)->isAlive()) {
            delete *it; // destruction de l’humanoide référencé
            it = humanoids.erase(it); // suppression de l’élément dans la liste
        }
        else
            ++it;
    return turn++;
}

void Field::printField() const {
    size_t l = width;
    for (size_t row = width; row > 0; --row) {
        for (size_t column = height; height > 0; --column) {
           std::cout << std::setw(l) << std::setfill('-') << field[row][column];
        }
        std::cout << std::endl;
    }
}

size_t Field::getTurn() const {
    return turn;
}

size_t Field::getWidth() const {
    return width;
}

size_t Field::getHeight() const {
    return height;
}

const std::list<Humanoid *> &Field::getHumanoids() const {
    return humanoids;
}
