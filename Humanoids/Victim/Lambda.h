/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Lambda.h
*/

#ifndef POO2_BUFFY_CRULL_LAGIER_LAMBDA_H
#define POO2_BUFFY_CRULL_LAGIER_LAMBDA_H

#include "../Humanoid.h"

class Lambda : public Humanoid {
private :
    static const char REPRESENTATION = 'H';
    static const size_t SPEED = 1;
    static const char ALIVE = true;


public :
    Lambda(size_t x, size_t y);

    void setAction(Field& field);

    virtual void move(Field &field);

};


#endif //POO2_BUFFY_CRULL_LAGIER_LAMBDA_H
