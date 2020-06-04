/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : LambdaHuman.h
*/

#ifndef POO2_BUFFY_CRULL_LAGIER_LAMBDA_H
#define POO2_BUFFY_CRULL_LAGIER_LAMBDA_H

#include "../Humanoid.h"

class LambdaHuman : public Humanoid {
private :
    static const char REPRESENTATION = 'H';
    static const size_t SPEED = 1;
    static const char ALIVE = true;

public :
    LambdaHuman(size_t x, size_t y);

    virtual void setAction(Field& field);


};


#endif //POO2_BUFFY_CRULL_LAGIER_LAMBDA_H
