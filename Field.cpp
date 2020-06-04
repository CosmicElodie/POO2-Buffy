/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Field.h
*/

#include <list>
#include <iostream>
#include <iomanip>
#include <Humanoids/Hunter/Monster/Vampire.h>
#include <Humanoids/Victim/LambdaHuman.h>
#include <Humanoids/Hunter/Slayer/Buffy.h>
#include "Field.h"

const char VAMPIRE_REPRESENTATION = 'V';
const char HUMAN_REPRESENTATION = 'H';
const char BUFFY_REPRESENTATION = 'B';

Field::Field(size_t width, size_t height, size_t nbVampires, size_t nbHumans) :
width(width), height(height), nbVampires(nbVampires), nbHumans(nbHumans), turn(0)
{
    unsigned int x = rand() % width,
            y = rand() % height;
    for (int h = 0; h < nbHumans; ++h) {
        while (isTaken(x, y)) {
            x = rand() % width;
            y = rand() % height;
        }
        humanoids.push_back(new LambdaHuman(x, y));
    }
    for (int v = 0; v < nbVampires; ++v) {
        while (isTaken(x, y)) {
            x = rand() % width;
            y = rand() % height;
        }
        humanoids.push_back(new Vampire(x, y));
    }

    while (isTaken(x, y)) {
        x = rand() % width;
        y = rand() % height;
    }
    humanoids.push_back(new Buffy(x, y));
}

void Field::initializePeople(const char representation, size_t number)
{
    size_t x = rand() % width, y = rand() % height;

    for(int n = 0; n < number; ++n)
    {
        searchForFreePlace(x, y);
        switch(representation)
        {
            case HUMAN_REPRESENTATION :
                humanoids.push_back(new LambdaHuman(x, y));
                break;
            case VAMPIRE_REPRESENTATION :
                humanoids.push_back(new Vampire(x, y));
                break;
            case BUFFY_REPRESENTATION :
                humanoids.push_back(new Buffy(x, y));
                break;
            default : throw("unrecognized humanoid representation");
        }
    }
}

void Field::searchForFreePlace(size_t & x, size_t & y) {
    //Tant qu'il n'y a pas de place libre, on génère des nombres aléatoires pour les coordonnées de la position.
    while ((isTaken(x, y) && !isCorrect(x,y)) || (!isTaken(x, y) && !isCorrect(x,y))) {
        x = rand() % width;
        y = rand() % height;
    }
}

bool Field::isTaken(size_t x, size_t y)
{
    //On itère sur tous les humanoïdes présents pour savoir si l'emplacement est libre
    for(Humanoid* humanoid : humanoids) {
        if(humanoid->getPositionX() == x && humanoid->getPositionY() == y) {
            return true;
        }
    }
    return false;
}

bool Field::isCorrect(size_t x, size_t y) {
    return (x >= 0 && x < width && y >= 0 && y < height);
}

int Field::nextTurn()
{
// Déterminer les prochaines actions
    for (std::list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end(); it++)
        (*it)->setAction(*this);
// Executer les actions
    for (std::list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end(); it++) {
        (*it)->executeAction(*this);
        std::cout << "Je suis un " << (*it)->getRepresentation() << " (" << (*it)->getPositionX() << ", " << (*it)->getPositionY() << ")" << std::endl;
    }
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

void Field::printLine(Field & field) {
    size_t w = field.getWidth() + 1;
    std::cout << SEPARATOR_2 ;
    std::cout  << std::setw(w) << std::setfill(SEPARATOR_3);
    std::cout  << SEPARATOR_2 << std::endl;
}

void Field::printField() {
    printLine(*this);
    bool humand_found = false;
    for (size_t row = 0; row < width; ++row) {
        std::cout << SEPARATOR_1;
        for (size_t column = 0; column < height; ++column) {
            for(Humanoid * humanoid : humanoids) {
                if(humanoid->getPositionX() == row && humanoid->getPositionY() == column)
                {
                    humand_found = true;
                    std::cout << humanoid->getRepresentation();
                    break;
                }
            }
            if(!humand_found)
            {
                std::cout << " ";
            }
            humand_found = false;
        }
        std::cout << SEPARATOR_1 << std::endl;
    }
    printLine(*this);
}

