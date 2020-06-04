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
#include "Field.h"
#include "Humanoids/Humanoid.h"

class Humanoid;

class Field {
    /*
    friend std::ostream & operator <<(std::ostream& os, Field & f) {
        printLine(os, f);
        for (size_t row = 0; row < f.width; ++row) {
            std::cout << SEPARATOR_1;
            for (size_t column = 0; column < f.height; ++column) {
                for(Humanoid * humanoid : humanoids) {
                    if(humanoid->getPositionX() == row && humanoid->getPositionY() == column)
                    {
                        std::cout << humanoid.getRepresentation();
                    }
                    else {
                        std::cout << "";
                    }
                }
            }
            std::cout << SEPARATOR_1 << std::endl;
        }
        printLine(os, f);

        return os;
    }
    */
private :
    static const char SEPARATOR_1 = '|';
    static const char SEPARATOR_2 = '+';
    static const char SEPARATOR_3 = '-';

    //tour
    size_t turn;

    //dimensions du terrain
    size_t width, height;

    //liste d'humanoides peuplant le terrain
    std::list<Humanoid*> humanoids;

public :

    void printBoard();

    /**
     * Constructeur
     * Permet de créer un Field en précisant les dimensions et les personnes dessus.
     * @param width : la largeur du terrain
     * @param height : la longueur du terrain
     */
    explicit Field(size_t width, size_t height, size_t nbVampires, size_t nbHumans);


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

    size_t getTurn() const;

    size_t getWidth() const;

    size_t getHeight() const;

    const std::list<Humanoid *> &getHumanoids() const;

    static void printLine(Field & field);

};

#endif //POO2_BUFFY_CRULL_LAGIER_FIELD_H
