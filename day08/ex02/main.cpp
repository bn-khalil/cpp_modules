#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(){
    std::cout << "MutantStack Default constructor called!" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack( const MutantStack& other ):sk(other.sk) {
    std::cout << "Copy MutantStack constructor called!" << std::endl;
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator = ( MutantStack &other ) {
    std::cout << "Copy MutantStack assinement operator called!" << std::endl;
    if (this != &other)
        this->sk = other.sk;
    return ( *this );
}

template <typename T>
MutantStack<T>::~MutantStack() {
    std::cout << "MutantStack Destructor called!" << std::endl;
}

template <typename T>
void MutantStack<T>::push( T ele ) {
    this->sk.push(ele);
}

template <typename T>
void MutantStack<T>::pop(size_t index) {
    this->sk.pop(index);
}

template <typename T>
void operator ++ ( MutantStack<T> & other ) {
    other.sk++;
}

template <typename T>
void operator -- ( MutantStack<T> & other ) {
    other.sk--;
}

template <typename T>
MutantStack<T> & operator * ( MutantStack<T> & other ) {
    return other.sk;
}

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << *mstack << std::endl;

    // std::cout << mstack.top() << std::endl;
    // mstack.pop();
    // std::cout << mstack.size() << std::endl;
    // mstack.push(3);
    // mstack.push(5);
    // mstack.push(737);
    // //[...]
    // mstack.push(0);
    // MutantStack<int>::iterator it = mstack.begin();
    // MutantStack<int>::iterator ite = mstack.end();
    // ++it;
    // --it;
    // while (it != ite)
    // {
    // std::cout << *it << std::endl;
    // ++it;
    // }
    // std::stack<int> s(mstack);

    return 0;
}