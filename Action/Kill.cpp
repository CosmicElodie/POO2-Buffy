/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Kill.h
*/

#include "Kill.h"

Kill::Kill(Humanoid * hunter, Humanoid *prey) : Action(hunter), prey(prey){}

void Kill::execute(Field &f) {
    prey->setAlive(false);
}