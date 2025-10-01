#include "Utils.hpp"
#include "DrivedA.hpp"
#include "DrivedB.hpp"
#include "DrivedC.hpp"

Base * generate(void) {
    std::time_t time = std::time(NULL);
    std::tm *n = std::localtime(&time);
    int rand = n->tm_sec % 6;
    if (rand < 2)
        return new DrivedA();
    else if (rand < 4)
        return new DrivedB();
    else if (rand < 6)
        return new DrivedC();
    return new DrivedA();
}

void identify(Base* p) {
    if (dynamic_cast<DrivedA*>(p))
        std::cout << "this is an object type DrivedA\n" << std::endl;
    else if (dynamic_cast<DrivedB*>(p))
        std::cout << "this is an object type DrivedB\n" << std::endl;
    else if (dynamic_cast<DrivedC*>(p))
        std::cout << "this is an object type DrivedC\n" << std::endl;
}

void identify(Base& p) {
    try {
        DrivedA driveda = dynamic_cast<DrivedA&>(p);
        (void) driveda;
        std::cout << "this is an object type DrivedA\n" << std::endl;
        return ;
    } catch(std::exception &e ) {}

    try
    {
        DrivedB drivedb = dynamic_cast<DrivedB&>(p);
        (void) drivedb;
        std::cout << "this is an object type DrivedB\n" << std::endl;
        return ;
    }
    catch(const std::exception& e) {}

    try
    {
        DrivedC drivedc = dynamic_cast<DrivedC&>(p);
        (void) drivedc;
        std::cout << "this is an object type DrivedC\n" << std::endl;
        return ;
    }
    catch(const std::exception& e){}
}
