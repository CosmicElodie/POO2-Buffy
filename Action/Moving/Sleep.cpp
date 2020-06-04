/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Sleep.h
*/

#include "Sleep.h"

Sleep::Sleep(Humanoid * humanoid) : Action(humanoid) { }

void Sleep::execute(Field &f) {
    humanoid->setPositionX(humanoid->getPositionX());
    humanoid->setPositionY(humanoid->getPositionY());
}
