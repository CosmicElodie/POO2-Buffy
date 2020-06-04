/**
* Laboratoire   :
* Date          :
* Élèves        : Lagier Elodie
* Fichier       : Utils.h
*/

#ifndef POO2_BUFFY_UTILS_H
#define POO2_BUFFY_UTILS_H

class Utils {
private:

public:
    enum class Humanoid_representation {
        BUFFY   = 'B',
        LAMBDA_HUMAN   = 'H',
        VAMPIRE = 'V',
    };

    enum class Direction {
        TOP,
        TOP_RIGHT,
        RIGHT,
        BOTTOM_RIGHT,
        BOTTOM,
        BOTTOM_LEFT,
        LEFT,
        TOP_LEFT
    };
};

#endif //POO2_BUFFY_UTILS_H
