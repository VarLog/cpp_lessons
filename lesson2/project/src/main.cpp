#include <iostream>

#include "game.h"

int main(int argc, char** argv) {
    std::cout << "Intellectual game" << std::endl;

    Game game;

    return game.run();
}
