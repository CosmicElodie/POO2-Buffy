#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "Field.h"
#include "Hunter/Monster/Vampire.h"
using namespace std;

void printInstructions();

bool checkInput(string input, bool& run);

int main(int argc, char *argv[]) {
    unsigned int gridWidth, gridHeight, humanCount, vampireCount;
    if (argc != 5) {
        return EXIT_FAILURE;
    }

    string input;
    bool run = true;
    srand (time(NULL));

    gridWidth = atoi(argv[1]);
    gridHeight = atoi(argv[2]);
    humanCount = atoi(argv[3]);
    vampireCount = atoi(argv[4]);

    Field simulation(gridWidth, gridHeight, humanCount, vampireCount);

    cout << "Initial simulation state : " << endl;
    simulation.printBoard();

    while (run) {
        printInstructions();

        do {
            cout << "Press a valid key" << endl;
            getline(cin, input);
            fflush(stdin);
        } while (!checkInput(input, run));

        if (!input.empty() && input.at(0) == 's') {
            //cout << simulation.stats() << endl;
        } else if (input.empty() || input.at(0) == 'n') {
            cout << "Turn " << (simulation.nextTurn() + 1) << endl;
            simulation.printBoard();
        }
    }

    return EXIT_SUCCESS;
}

bool checkInput(string input, bool& run) {
    if (input.empty()) {
        return true;
    } else if (input.size() > 1) {
        return false;
    }
    char i = input.at(0);

    if (i != 's' && i != 'n' && i != '\0' && i != 'q') {
        return false;
    }
    if (i == 'q') {
        run = false;
    }
    return true;
}

void printInstructions() {
    printf("\nValid keys :\n - %c or <enter> : next turn\n - %c : see statistics\n - %c : quit the program\n",
           'n', 's', 'q');
}