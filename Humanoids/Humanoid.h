/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Humanoid.h
*/

#ifndef POO2_BUFFY_CRULL_LAGIER_HUMANOID_H
#define POO2_BUFFY_CRULL_LAGIER_HUMANOID_H


#include <cstdio>
#include "../Field.h"

class Humanoid {
private :
    //L'humain est-il toujours en vie ?
    bool alive;

    //Représentation sur la console
    const char letter;

    //la position de l'humanoide sur le terrain.
    size_t positionX, positionY;

public :

    //TODO : initialiser au bol les gens sur le terrain
    Humanoid(bool alive, const char letter);

/**
     * Permet de savoir si un humain est en vie.
     * @return true si en vie, false sinon.
     */
    const bool isAlive() const;

    /**
     * Permet d'exécuter les actions
     * @param field : le terrain sur lequel se déroule les actions
     */
    void executeAction(Field * field);

    /**
     * Permet de définir les actions
     * @param field : le terrain sur lequel se déroule les actions
     */
    void setAction(Field<Humanoid> * field);

};


#endif //POO2_BUFFY_CRULL_LAGIER_HUMANOID_H
