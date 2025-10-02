
#include "ScalarConverter.hpp"

int main(int ac, char *av[]){

    if (ac != 2) {
        std::cout << "Error: " << "invalid arguments" << std::endl;
        return 0;
    }
    ScalarConverter::convert(std::string(av[1]));
    return 0;
}