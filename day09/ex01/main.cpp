#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Error: progam should take an RPN." << std::endl;
        return 1;
    }

    RPN rnp;
    if (!rnp.paseRpn(argv[1])) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    if (!rnp.execRpn()) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    rnp.displayResuts();


    return 0;
}
