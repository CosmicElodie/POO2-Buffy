#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Field.h"
#include "Hunter/Monster/Vampire.h"

using namespace std;

void menu() {
    printf("\n%c>uit - %c>tatistics - %c>ext\n",'q', 's', 'n');
}

bool check(char userInput, Field & field) {
    switch (userInput) {
        case 'q' :
            std::cout << "Babaye ! (^-^)/";
            exit(EXIT_SUCCESS);
        case 's' :
            //cout << field.generateStatistics() << endl;
            return true;
        case 'n' :
            cout << "Turn " << (field.nextTurn() + 1) << endl;
            field.printField();
            return true;
        default :
            cout << "Erreur de saisie !" << endl;
            return false;
    }

}

int main(int argc, char *argv[]) {
    size_t fieldWidth, fieldHeight, nbHumans, nbVampires;
    if (argc != 5) {
        std::cout << "Vous avez rentré un nombre incorrect d'arguments.";
        return EXIT_FAILURE;
    }

    char userInput;
    bool isRunning = true;
    srand(time(NULL));

    fieldWidth = atoi(argv[1]);
    fieldHeight = atoi(argv[2]);
    nbVampires = atoi(argv[3]);
    nbHumans = atoi(argv[4]);

    Field field(fieldWidth, fieldHeight, nbVampires, nbHumans);
    field.printField();

    while(isRunning)
    {
        do {
            menu();
        } while (((userInput = getchar()) != '\n' && userInput != EOF) && check(userInput, field));
    }
}