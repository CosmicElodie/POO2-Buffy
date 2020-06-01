/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Hunt.h
*/

#include "Hunt.h"

void Hunt::execute(Field & f) {
    //TODO : recherche
}

Hunt::Hunt(size_t speed, Hunter * hunter, Humanoid * prey) : hunter(hunter), prey(prey), Action(speed) {
}
