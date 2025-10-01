#include "Base.hpp"
#include "DrivedA.hpp"
#include "DrivedB.hpp"
#include "DrivedC.hpp"
#include "Utils.hpp"

int main(){
    std::cout << "generate Drived object\n" << std::endl;
    Base *hold = generate();

    std::cout << "|======================================|" << std::endl;
    std::cout << "identify Drived type with using pointer: " << std::endl;
    identify(hold);

    std::cout << "|======================================|" << std::endl;
    std::cout << "identify Drived type with using reference: " << std::endl;
    identify(*hold);

    delete hold;
    return 0;
}