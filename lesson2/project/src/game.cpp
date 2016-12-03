#include "game.h"

#include <iostream>
#include <random>
#include <sstream>

int Game::run() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 9);

    while (std::cin.good()) {
        auto a = dis(gen);
        auto b = dis(gen);

        auto answer = 0;

        std::cout << a << " + " << b << std::endl;
        std::cin >> answer;

        if (answer == a + b) {
            ++score_;
            std::cout << "Correct! You score: " << score_ << std::endl;
        } else {
            std::cout << "You made a mistake. The right answer is " << (a + b) << std::endl;
        }
    }

    return 0;
}
