#include <iostream>
#include "Field.h"
#include "Hunter/Monster/Vampire.h"
#include "Hunter/Slayer/Buffy.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Field field(50, 50, 10, 20);
    std::cout << field;
    return 0;
}
