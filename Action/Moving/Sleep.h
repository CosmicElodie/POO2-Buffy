/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Sleep.h
*/

#ifndef POO2_BUFFY_SLEEP_H
#define POO2_BUFFY_SLEEP_H

#include <Action/Action.h>

class Sleep : public Action {
private:

public:
    Sleep();
    void execute(Field &f);

};


#endif //POO2_BUFFY_SLEEP_H
