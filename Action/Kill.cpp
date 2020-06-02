/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Kill.h
*/

#include "Kill.h"

Kill::Kill(size_t speed, Hunter *hunter, Humanoid *prey) : hunter(hunter), prey(prey), Action(speed) {}

void Kill::execute(Field &f) {
    //TODO : remove people from field
    prey->setAlive(false);

}