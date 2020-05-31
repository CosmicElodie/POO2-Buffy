#include <iostream>
#include "Field.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Field field(50, 50, 10, 20);
    field.printField();
    return 0;
}
