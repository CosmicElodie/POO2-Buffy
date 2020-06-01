/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Hunter.h
*/

#include <Action/Moving/Hunt.h>
#include <Action/Moving/Wander.h>
#include "Hunter.h"

Hunter::Hunter(size_t alive, const char representation, size_t x, size_t y, const size_t speed) :
Humanoid(alive, representation, x, y, speed){
    prey = nullptr;

}

void Hunter::setAction(Field & field) {
    //TODO : tester si des "ennemis" sont présents dans la liste.
    //TODO : si oui, alors on définit une prey et hunt. Sinon alors wander/sleep.

    if(true) //à remplacer par "trouver proie"
    {
        Hunt * hunt = new Hunt(this->getSpeed(), this, prey);
        this->setNextAction(hunt);
    } else{
        Wander * wander = new Wander(this->getSpeed());
    }
}

float Hunter::calculateDistance(int hunterPositionX, int hunterPositionY, int preyPositionX, int preyPositionY){
    return sqrt(pow(hunterPositionX - hunterPositionY, 2) + pow(preyPositionX - preyPositionY, 2));
}

const Humanoid *Hunter::findClosestPray(Hunter & hunter, const std::type_info *type, const std::list<Humanoid *> *humanoids) {
    float distance = 0, newDistance = 0;
    Humanoid * pray = nullptr;

    for (auto humanoidIt = humanoids->begin(); humanoidIt != humanoids->end(); humanoidIt++ ){
        newDistance = calculateDistance(hunter.getPositionX(), hunter.getPositionY(),
                                        (*humanoidIt)->getPositionX(), (*humanoidIt)->getPositionY());
        if( (distance > newDistance) && typeid( *(*humanoidIt) ) == *type)
        {
            distance = newDistance;
            pray = (*humanoidIt);
        }
    }
    return pray;
}
