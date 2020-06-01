/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Hunter.h
*/

#ifndef POO2_BUFFY_CRULL_LAGIER_HUNTER_H
#define POO2_BUFFY_CRULL_LAGIER_HUNTER_H

#include <cmath>
#include <list>
#include "Humanoid.h"

class Hunter : public Humanoid {

private:
    //TODO voir comment faire pour multiples proies

public:
//ALIVE, REPRESENTATION, x, y, SPEED, ENNEMI
    Hunter(size_t alive, const char representation, size_t x, size_t y, const size_t speed);

    virtual void setAction(Field& field);

    /**
     * Calcule la distance qui sépare un chasseur d'une proie.
     * @param hunterPositionX : la composante X de la position du chasseur
     * @param hunterPositionY : la composante Y de la position du chasseur
     * @param preyPositionX : la composante X de la position de la proie
     * @param preyPositionY : la composante Y de la position de la proie
     * @return : la distance (norme mathématique) entre le chasseur et la proie.
     */
    float calculDistance(int hunterPositionX, int hunterPositionY, int preyPositionX, int preyPositionY);


    const Humanoid * findClosestPray(Hunter & hunter, const std::type_info* type, const std::list<Humanoid*>* humanoids);

};


#endif //POO2_BUFFY_CRULL_LAGIER_HUNTER_H
