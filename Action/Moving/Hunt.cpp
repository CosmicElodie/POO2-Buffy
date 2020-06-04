/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Hunt.h
*/

#include <Action/Kill.h>
#include <Humanoids/Hunter/Hunter.h>
#include "Hunt.h"

Hunt::Hunt(Humanoid * hunter, Humanoid * prey) : Action(hunter), prey(prey) { }

void Hunt::execute(Field & f) {
    //On vérifie qu'il y ait une proie, qu'elle soit vivante.
    if(prey && prey->isAlive())
    {
        //si la proie est à proximité, on la tue, sinon on continue de la chasser.
        if(((Hunter*)humanoid)->calculateDistance((Hunter*)humanoid, prey) <= 1)
        {
            Kill * kill = new Kill(humanoid, prey);
            kill->execute(f);
        }



    }
}

