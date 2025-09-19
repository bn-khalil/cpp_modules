#include <iostream>
#include <array>

// class a{
//     public:
//     ~a(){
//         throw 12;
//     }
// };

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
#include <stdexcept>

void f1(int a) {
    std::cout << a << std::endl;
}

int f1(float a) {
    std::cout << a << std::endl;
    return 12;
}

int main() {
    if (1 == 1)
        throw std::runtime_error("this is error");
    std::cout << "this sdfsdf" << std::endl;
    

    return (0);
}