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
    //référence sur la proie du chasseur
    Humanoid * prey;

public:

    /**
     * Permet de construire un chasseur selon les données indiquées.
     * @param alive : true si vivant (Buffy / LambdaHuman), false sinon (Vampire).
     * @param representation : la lettre qui représente le hunter. ('B' ou 'V' en l'occurence).
     * @param x : la composante de sa position x
     * @param y : la composante de sa position y
     * @param speed : sa vitesse de déplacement (aka le nombre de cases par tout)
     */
    Hunter(size_t alive, const char representation, size_t x, size_t y, const size_t speed);

    /**
     * Permet d'établir la prochaine action.
     * @param field : le terrain sur lequel se déroule l'action.
     */
    void setAction(Field& field) override;

    /**
     * Calcule la distance qui sépare un chasseur d'une proie.
     * @param hunterPositionX : la composante X de la position du chasseur
     * @param hunterPositionY : la composante Y de la position du chasseur
     * @param preyPositionX : la composante X de la position de la proie
     * @param preyPositionY : la composante Y de la position de la proie
     * @return : la distance (norme mathématique) entre le chasseur et la proie.
     */
    float calculateDistance(size_t hunterPositionX, size_t hunterPositionY, size_t preyPositionX, size_t preyPositionY);

    /**
     * Trouve la proie la plus proche du chasseur.
     * @param hunter : le chasseur
     * @param preyType : le preyType de proie(s) recherchée
     * @param humanoids : la liste des humanoïdes présents sur le board.
     * @return la proie la plus proche du chasseur.
     */
    const Humanoid * findClosestPray(Hunter & hunter, const std::type_info* preyType, std::list<Humanoid*>* humanoids);

};


#endif //POO2_BUFFY_CRULL_LAGIER_HUNTER_H
