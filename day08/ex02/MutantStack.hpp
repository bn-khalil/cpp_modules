#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <iostream>
#include <stack>

template <typename T, typename container = std::deque<T> >

class MutantStack: public std::stack<T> {
    public:
        typedef typename container::iterator iterator;
        typedef typename container::const_iterator const_iterator;

        MutantStack(){
            std::cout << "MutantStack Default constructor called!" << std::endl;
        }
        
        MutantStack( const MutantStack& other ) {
            std::cout << "Copy MutantStack constructor called!" << std::endl;
            (void) other;
        }

        MutantStack<T> & 
        operator = ( MutantStack &other ) {
            std::cout << "Copy MutantStack assinement operator called!" << std::endl;
            (void) other;
            return ( *this );
        }

        ~MutantStack() {
            std::cout << "MutantStack Destructor called!" << std::endl;
        }

        iterator begin() {
            return this->c.begin();
        }

        iterator end() {
            return this->c.end();
        }

        const_iterator begin() const {
            return this->c.begin();
        }

        const_iterator end() const {
            return this->c.end();
        }
};

#endif