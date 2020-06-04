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

Field::Field(size_t width, size_t height, size_t nbVampires, size_t nbHumans) : width(width), height(height)
{
    //on créé les humains.
    initializePeople(HUMAN_REPRESENTATION, nbHumans);

    //on créé les vampires.
    initializePeople(VAMPIRE_REPRESENTATION, nbVampires);

    //on créé Buffy.
    initializePeople(BUFFY_REPRESENTATION, 1);
}

void Field::initializePeople(const char representation, size_t number)
{
    //On initialise la seed selon le temps actuel, pour avoir une valeur différente à chaque fois.
    //srand( (unsigned)time(NULL) );

    for(int n = 0; n < number; ++n)
    {
        switch(representation)
        {
            case HUMAN_REPRESENTATION : humanoids.push_back(new LambdaHuman(rand() % width, rand() % height));
                break;
            case VAMPIRE_REPRESENTATION :
                humanoids.push_back(new Vampire(rand() % width, rand() % height));
                break;
            case BUFFY_REPRESENTATION : humanoids.push_back(new Buffy(rand() % width, rand() % height));
                break;
            default : throw("unrecognized humanoid representation");
        }
    }

}

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

void Field::printBoard() {
    //printLine(os, f);
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
    //printLine(os, f);
}

