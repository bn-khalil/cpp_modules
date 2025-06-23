#include <iostream>

class a{
    public:
    int sd;
    void sed(int sd) {
        sd = sd;
    }
};

// class b: public virtual a{
// };

// class c: public virtual a{

// };

// class d: public b, public c{

// };

int main() {
    a d;
    d.sed(1);
    return (0);
}