/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Field.h
*/

#ifndef POO2_BUFFY_CRULL_LAGIER_FIELD_H
#define POO2_BUFFY_CRULL_LAGIER_FIELD_H

#include <list>
#include <iostream>
#include "Humanoids/Humanoid.h"


class Field;
std::ostream & operator <<(std::ostream& os, Field & field);

class Field {
private :
    //tour
    size_t turn;

    //dimensions du terrain
    size_t width, height;

    //liste d'humanoides peuplant le terrain
    std::list<Humanoid*> humanoids;

    //représente le terrain de forme matricielle
    Field** field;
public :

    /**
     * Constructeur
     * Permet de créer un Field sans nécessairement passer des paramètres.
     * Le terrain aura alors une dimension de 50 x 50, et aucune personnes dessus.
     */
    Field();

    /**
     * Constructeur
     * Permet de créer un Field en précisant les dimensions et les personnes dessus.
     * @param humanoids : tous les humanoides, genre confondus.
     * @param width : la largeur du terrain
     * @param height : la longueur du terrain
     */
    explicit Field(const std::list<Humanoid *> &humanoids, size_t width, size_t height);

/**
     * Permet de gérer un tour de la simulation
     * @return
     */
    int nextTurn();

    /**
     * Permet d'avoir une visualisation graphique du terrain.
     * On créé une liste avec des dimensions du terrain.
     * On place les humanoides dessus, aux positions voulues.
     * Si une 'case' de la liste est null, on n'affiche rien, sinon on affiche la lettre représentant l'humanoide.
     */
    void printField() const;

};


#endif //POO2_BUFFY_CRULL_LAGIER_FIELD_H
