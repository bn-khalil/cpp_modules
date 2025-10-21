#include "Span.hpp"

int main()
{
    // TEST 1
    
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    try{
        sp.addNumber(-1);
        sp.addNumber(-3);
    } catch(const std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "|---------------------------------|" << std::endl;

    // TEST 2

    Span tes = Span(10);
    tes.addNumber(1);
    tes.addNumber(2);
    tes.addNumber(3);
    tes.addNumber(4);
    tes.addNumber(5);
    
    Span com = Span(5);
    com.addNumber(6);
    com.addNumber(7);
    com.addNumber(8);
    com.addNumber(9);

    tes.addNumbers(com.begin(), com.end());
    std::cout << tes.shortestSpan() << std::endl;
    std::cout << tes.longestSpan() << std::endl;

    std::cout << "|---------------------------------|" << std::endl;

    // TEST 3

    Span big = Span(11000);
    for(int i = 0; i < 11000; i++) {
        big.addNumber(i + 1);
    }

    std::cout << big.shortestSpan() << std::endl;
    std::cout << big.longestSpan() << std::endl;

    std::cout << "|---------------------------------|" << std::endl;
    // TEST 4
    
    Span sin = Span(1);
    sin.addNumber(42);

    try{
        std::cout << sin.shortestSpan() << std::endl;
        std::cout << sin.longestSpan() << std::endl;
    } catch(const std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}