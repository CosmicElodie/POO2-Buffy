/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Humanoid.h
*/

#ifndef POO2_BUFFY_CRULL_LAGIER_HUMANOID_H
#define POO2_BUFFY_CRULL_LAGIER_HUMANOID_H


#include <cstdio>

class Action;
class Field;

class Humanoid {
private :
    //L'humain est-il toujours en vie ?
    bool alive;

    //Représentation sur la console
    char representation;

    //la position de l'humanoide sur le terrain.
    size_t positionX, positionY;

    //la vitesse de déplacement d'un humanoid
    size_t speed;

    //l'action en cours de l'humanoid
    Action* action;

public :

    /**
     * Créé un humanoid avec les diverses informations ci-dessous..
     * @param alive : est-il en vie ou non (si non -> vampire ou autre monstre)
     * @param representation : le symbole qui le représente sur le plateau
     * @param x : sa position x
     * @param y : sa position y
     * @param speed : sa vitesse de déplacement
     */
    Humanoid(bool alive, const char representation, size_t x, size_t y, size_t speed);

    /**
     * Permet d'affecter au nouveau genre d'humanoid à un humanoid.
     * Ex : transformer un humanoid humain en humanoid vampire.
     * @param humanoid : le nouveau genre d'humanoid.
     * @return l'humanoid transformé en un nouveau genre d'humanoid.
     */
    Humanoid & operator=(const Humanoid& humanoid);

/**
     * Permet de savoir si un humain est en vie.
     * @return true si en vie, false sinon.
     */
    const bool isAlive() const;

    /**
     * Permet d'exécuter les actions
     * @param field : le terrain sur lequel se déroule les actions
     */
    void executeAction(Field & field);

    /**
     * Permet de définir les actions
     * @param field : le terrain sur lequel se déroule les actions
     */
    virtual void setAction(Field& field) = 0;

    virtual void move(Field &field);

    bool operator==(const Humanoid &humanoid) const;
    bool operator!=(const Humanoid &humanoid) const;

};


#endif //POO2_BUFFY_CRULL_LAGIER_HUMANOID_H
