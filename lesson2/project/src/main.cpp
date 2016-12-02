#include <iostream>

int main(int argc, char** argv) {
    std::cout << "Hello world" << std::endl;

    auto f = [](auto&& i) {
        std::cout << i << std::endl;
    };

    f(3);

    return 0;
}
