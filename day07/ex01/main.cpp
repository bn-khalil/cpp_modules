#include "iter.hpp"

void _adding(std::string & str){
    str = "_" + str;
}

int main(int, char**)
{
    int a[3] = {1, 2, 3};
    std::cout << "applay increament on integers : " << std::endl;
    ::iter(a, 3, increament);
    ::iter(a, 3, display);

    std::cout << "|====================================|" << std::endl;

    float flos[3] = {1.1f, 2.2f, 3.3f};
    std::cout << "applay increament on float : " << std::endl;
    ::iter(flos, 3, increament);
    ::iter(flos, 3, display);

    std::cout << "|====================================|" << std::endl;

    std::string str[3] = {"bn", "th", "kh"};
    std::cout << "adding _ to the beginning: " << std::endl;
    ::iter(str, 3, _adding);
    ::iter(str, 3, display);

    std::cout << "|====================================|" << std::endl;
    const std::string ques[3] = {"show", "how", "throw"};
    ::iter(ques, 3, display);

    return 0;
}