#include "PmergeMe.hpp"

int main(int ac, const char **av) {

    if (ac <= 1) {
        std::cerr << "Error: program must take an argument." << std::endl;
        return 1;
    }

    PmergeMe m;

    if (!m.pasreInput(av)) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}