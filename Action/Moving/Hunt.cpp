/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Hunt.h
*/

#include <algorithm>
#include <Action/Kill.h>
#include <Humanoids/Hunter/Hunter.h>
#include "Hunt.h"

Hunt::Hunt(Humanoid * hunter, Humanoid * prey) : Action(hunter), prey(prey) { }

void Hunt::execute(Field & f) {

    size_t x = humanoid->getPositionX();
    size_t y = humanoid->getPositionY();

    x = CalculateNewCoordinate(x, prey->getPositionX(), humanoid->getPositionX(), f.getWidth());
    y = CalculateNewCoordinate(y, prey->getPositionY(), humanoid->getPositionY(), f.getHeight());

    humanoid->setNextPositionX(x);
    humanoid->setNextPositionY(y);

    //On vérifie qu'il y ait une proie, qu'elle soit vivante.
    if(prey && prey->isAlive())
    {
        //si la proie est à proximité, on la tue, sinon on continue de la chasser.
        if(((Hunter*)humanoid)->calculateDistance((Hunter*)humanoid, prey) <= 1)
        {
            Kill * kill = new Kill(humanoid, prey);
            kill->execute(f);
            std::cout << "I'm dead at (" << prey->getPositionX() << ", " <<  prey->getPositionY() << ")\n";
        }
    }
}

size_t Hunt::CalculateNewCoordinate(int coordinate, int preyPosition, int humanPosition, size_t fieldSide)
{
    if(preyPosition < humanPosition)
    {
        int tempX = humanPosition - humanoid->getSpeed();
        coordinate = std::max(tempX, 0);
    }
    else if(preyPosition > humanPosition) {
        int tempX = humanPosition + humanoid->getSpeed();
        int tempY = fieldSide - 1;
        coordinate = std::min(tempX, tempY);
    }
    return coordinate;
}

