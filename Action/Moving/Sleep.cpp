/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Sleep.h
*/

#include "Sleep.h"


void Sleep::execute(Field &f) {
    humanoid->setPositionX(humanoid->getPositionX());
    humanoid->setPositionY(humanoid->getPositionY());
}

Sleep::Sleep(Humanoid * humanoid) : Action(humanoid) {
}
