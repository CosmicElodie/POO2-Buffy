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

class Humanoid;

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

protected:
    //Représentation du field sous forme matricielle
    char** field;

public :

    /**
     * Constructeur
     * Permet de créer un Field en précisant les dimensions et les personnes dessus.
     * @param width : la largeur du terrain
     * @param height : la longueur du terrain
     */
    explicit Field(size_t width, size_t height, size_t nbVampires, size_t nbHumans);

    /**
     * Sert à initialiser le board.
     * @param width : la largeur du board
     * @param height : la longueur du board
     */
    void initializeBoard(size_t width, size_t height);

    /**
     * Permet de répartir les différents acteurs sur le board.
     * @param representation : la lettre qui représente l'humanoide.
     * @param number : le nombre d'humanoides à dépsoer sur le board.
     */
    void initializePeople(const char representation, size_t number);

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

    size_t getTurn() const;

    size_t getWidth() const;

    size_t getHeight() const;

    const std::list<Humanoid *> &getHumanoids() const;

    void place(size_t x, size_t y, char representation);

};

#endif //POO2_BUFFY_CRULL_LAGIER_FIELD_H
