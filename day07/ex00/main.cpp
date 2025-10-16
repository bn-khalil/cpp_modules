#include "whatever.hpp"

template <typename T>
void swap(T & param1, T & param2) {
    T tmp = param1;
    param1 = param2;
    param2 = tmp;
}

template <typename U>
U min(U & param1, U & param2) {
    return param1 < param2 ? param1 : param2;
}

template <typename V>
V max(V & param1, V & param2) {
    return param1 > param2 ? param1 : param2;
}

int main( void ) {

    int a = 2;
    int b = 3;

    ::swap( a, b );
    increament(12.9f);

    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);

    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    return 0;
}