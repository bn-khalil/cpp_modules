#include "Span.hpp"

int main() {
    Span span1(3);
    Span span2(3);
    
    span1.addNumber(1);
    span1.addNumber(1);
    span1.addNumber(1);

    span2.addNumber(2);
    span2.addNumber(2);
    span2.addNumber(2);

    span1 = span2;
    

    return 0;
}