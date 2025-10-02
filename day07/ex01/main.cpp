#include "iter.hpp"

template <typename K>
void increament(K & i){
    i++;
}

void _adding(std::string & str){
    str = "_" + str;
}

void multifloat(float & f){
    f *= 2;
}

template <typename T>
void display( const T & f){
    std::cout << f << std::endl;
}

int main(int, char**)
{
    int a[3] = {1, 2, 3};
    ::iter(a, 3, increament);
    std::cout << "applay increament on integers : " << std::endl;
    ::iter(const_cast<const int*>(a), 3, display);

    std::cout << "|====================================|" << std::endl;

    float flos[3] = {1.1f, 2.2f, 3.3f};
    ::iter(flos, 3, increament);
    std::cout << "applay increament on float : " << std::endl;
    ::iter(const_cast<const float*>(flos), 3, display);

    ::iter(flos, 3, multifloat);
    std::cout << "appaly multiplication in 2 : " << std::endl;
    ::iter(const_cast<const float*>(flos), 3, display);

    std::cout << "|====================================|" << std::endl;

    std::string str[3] = {"bn", "th", "kh"};
    ::iter(str, 3, _adding);
    std::cout << "adding _ to the beginning: " << std::endl;
    ::iter(const_cast<const std::string *>(str), 3, display);

    std::cout << "|====================================|" << std::endl;
    const std::string ques[3] = {"show", "how", "throw"};
    ::iter(ques, 3, display);

    return 0;
}