#include <iostream>
#include <list>
#include <set>
#include <vector>

template <class Container, class Predicate>
bool find_predicate(Container&& container, Predicate&& predicate) {
    for (const auto& element : container) {
        if (predicate(element) == true) {
            return true;
        }
    }
    return false;
}

template <class Container, class ElementType>
bool contains(Container&& container, ElementType&& element) {
    for (const auto& e : container) {
        if (e == element) {
            return true;
        }
    }
    return false;
}

int main(int, char**) {
    std::vector<int> vector = {1, 2, 3, 4};
    if (contains(vector, 3) == true) {
        std::cout << "Found!" << std::endl;
    }

    std::list<std::string> list = {"a", "bb", "cd"};
    if (contains(list, "bb") == true) {
        std::cout << "Found!" << std::endl;
    }

    std::set<double> set = {3.14, 2.71, -0.1};
    auto predicate = [](double num) {
        if (num <= 3.) {
            return true;
        }
        return false;
    };
    auto res = find_predicate(set, predicate);

    if (res == true) {
        std::cout << "Found!" << std::endl;
    }

    return 0;
}
