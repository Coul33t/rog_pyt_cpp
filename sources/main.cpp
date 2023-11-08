#include <iostream>

#include "include/engine.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Engine engine;

    engine.init();
    engine.run();

    return 0;
}
