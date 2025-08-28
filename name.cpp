#include <iostream>

class a{
    public:
    ~a(){
        throw 12;
    }
};

// class b: public virtual a{
// };

// class c: public virtual a{

// };

// class d: public b, public c{

// };

void f2() {
    // a d;
    try
    {
        throw 21;
        /* code */
    }
    catch(int e)
    {
        std::cerr << e << '\n';
    }
}

void f1() {
    f2();
}

int main() {
        f1();
    
    return (0);
}

