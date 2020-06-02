/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Hunter.h
*/

#include <Action/Moving/Hunt.h>
#include <Action/Moving/Wander.h>
#include <Action/Moving/Sleep.h>
#include "Hunter.h"
#include "./Monster/Vampire.h"
#include "./Victim/LambdaHuman.h"

Hunter::Hunter(size_t alive, const char representation, size_t x, size_t y, const size_t speed) :
Humanoid(alive, representation, x, y, speed){
    prey = nullptr;

}

void Hunter::setAction(Field & field) {
    const std::type_info *preyType = (this->getRepresentation() == 'B') ?  &(typeid(Vampire)) : &(typeid(LambdaHuman));

    if(preyType != nullptr)
    {
        Hunt * hunt = new Hunt(this->getSpeed(), this, prey);
        this->setNextAction(hunt);
    }else{
        if(this->getRepresentation() == 'B')
        {
            Wander * wander = new Wander(this->getSpeed());
            this->setNextAction(wander);
        } else{
            Sleep * sleep = new Sleep();
            this->setNextAction(sleep);
        }

    }
}

float Hunter::calculateDistance(size_t hunterPositionX, size_t hunterPositionY, size_t preyPositionX, size_t preyPositionY){
    return sqrt(pow(hunterPositionX - hunterPositionY, 2) + pow(preyPositionX - preyPositionY, 2));
}

const Humanoid *Hunter::findClosestPray(Hunter & hunter, const std::type_info *preyType, std::list<Humanoid *> *humanoids) {
    float distance = -1, newDistance = -1;
    Humanoid * prey = nullptr;

    for (auto humanoidIt = humanoids->begin(); humanoidIt != humanoids->end(); humanoidIt++ ){
        newDistance = calculateDistance(hunter.getPositionX(), hunter.getPositionY(),
                                        (*humanoidIt)->getPositionX(), (*humanoidIt)->getPositionY());
        if( ((distance <= -1) || (distance > newDistance)) && typeid( *(*humanoidIt) ) == *preyType)
        {
            prey = (*humanoidIt);
            distance = newDistance;
        }
    }
    return prey;
}

