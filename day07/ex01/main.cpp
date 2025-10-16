#include "iter.hpp"

template <typename T>

void iter(T array[], size_t length, void (*funptr)(T &)) {
    for (size_t i = 0; i < length; i++)
        funptr(array[i]);
}

template <typename K>
void increament(K & i){
    i++;
}

void _adding(std::string & str){
    str = "_" + str;
}

template <typename T>
void display( const T & f){
    std::cout << f << std::endl;
}

int main(int, char**)
{
    int a[3] = {1, 2, 3};
    std::cout << "applay increament on integers : " << std::endl;
    ::iter(a, 3, increament);
    ::iter(const_cast<const int*>(a), 3, display);

    std::cout << "|====================================|" << std::endl;

    float flos[3] = {1.1f, 2.2f, 3.3f};
    std::cout << "applay increament on float : " << std::endl;
    ::iter(flos, 3, increament);
    ::iter(const_cast<const float*>(flos), 3, display);

    std::cout << "|====================================|" << std::endl;

    std::string str[3] = {"bn", "th", "kh"};
    std::cout << "adding _ to the beginning: " << std::endl;
    ::iter(str, 3, _adding);
    ::iter(const_cast<const std::string *>(str), 3, display);

    std::cout << "|====================================|" << std::endl;
    const std::string ques[3] = {"show", "how", "throw"};
    ::iter(ques, 3, display);

    return 0;
}