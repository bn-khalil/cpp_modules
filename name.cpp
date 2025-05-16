#include <iostream>

namespace student{
    std::string name = "stend";
};

namespace cla{
    std::string name = "clas";
};

class Name{
    public:
    int s;
};

int main() {
    int a  = 4;
    int c = 5;

    int &rf = a;
    std::cout<< rf;
    rf = c;
    std::cout<< rf;
    return (0);
}