#include "Span.hpp"

int main() {
    Span span1(6);
    // Span span2(3);

    
    span1.addNumber(1);
    span1.addNumber(10);
    span1.addNumber(5);

    // span2.addNumber(2);
    // span2.addNumber(2);
    // span2.addNumber(2);

    // span1 = span2;

    std::vector<int> col;
    col.push_back(3);
    col.push_back(6);
    col.push_back(10);
    
    span1.addNumber(col);
    col.push_back(10);
    // span1.addNumber(5);
    // std::cout << span << std::endl;

    return 0;
}