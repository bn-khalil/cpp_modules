#include <iostream>
#include <array>

class As{
    public:
        int a;
        As(int a) {
            this->a = a;
        }
};

// class b: public virtual a{
// };

// class c: public virtual a{

// };

// class d: public b, public c{

// };

// void f2() {
//     // a d;
//     try
//     {
//         throw 21;
//         /* code */
//     }
//     catch(int e)
//     {
//         std::cerr << e << '\n';
//     }
// }
// #include <stdexcept>

// void f1(int a) {
//     std::cout << a << std::endl;
// }

// int f1(float a) {
//     std::cout << a << std::endl;
//     return 12;
// }


int main() {

    // float * a;

    // a = new float(12);

    // *a = *a;

    As * a = new As(12);

    *a = *a;

    // std::cout << *a ;
    return (0);
}