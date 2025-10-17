
#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <iostream>
#include <stack>

template <typename T, typename container = std::deque<T>>
class MutantStack: public std::stack<T> {
    public:
        typedef typename std::
        MutantStack();
        MutantStack( const MutantStack & other );
        MutantStack & operator = ( MutantStack & other );
        ~MutantStack();

        void push( T ele );
        void pop(size_t index);
};

// template <typename T>
// void operator ++ ( MutantStack<T> & other );
// template <typename T>
// void operator -- ( MutantStack<T> & other );
// template <typename T>
// MutantStack<T> & operator * ( MutantStack<T> & other );

#endif