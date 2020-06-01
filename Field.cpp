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
    //on commence par initialiser le board.
    initializeBoard(width, height);

    //on créé les vampires.
    initializePeople(VAMPIRE_REPRESENTATION, nbVampires);

    //on créé les humains.
    initializePeople(HUMAN_REPRESENTATION, nbHumans);

    //on créé Buffy.
    initializePeople(BUFFY_REPRESENTATION, 1);

    //on placeHumanoids les humanoïdes sur le board.
    for(Humanoid* h : humanoids) {
        this->placeHumanoids(h->getPositionX(), h->getPositionY(), h->getRepresentation());
    }
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

void Field::initializeBoard(size_t width, size_t height)
{
    field = new char*[width];

    for (int w_unit = 0; w_unit < width; ++w_unit) {
        field[w_unit] = new char[height];
        for (int h_unit = 0; h_unit < height; ++h_unit) {
            field[w_unit][h_unit] = ' ';
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

void Field::placeHumanoids(size_t x, size_t y, char representation) {
    field[x][y] = representation;
}

void Field::printLine(std::ostream & os, Field & field) {
    size_t w = field.getWidth() + 1;
    os << SEPARATOR_2 ;
    os << std::setw(w) << std::setfill(SEPARATOR_3);
    os << SEPARATOR_2 << std::endl;
}


