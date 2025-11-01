#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe( const PmergeMe& other ) {
    *this = other;
}

PmergeMe & PmergeMe::operator = ( const PmergeMe &other ) {
    if (this != &other)
        ;
    return ( *this );
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::pasreInput(const char ** av) {

    int i = 1;

    while (av[i]) {
        std::string ar(av[i]);

        // std::cout << ar << std::endl;
        if (ar.empty())
            return false;
        size_t j = 0;
        if (ar[0] == '+')
            j++;
        if (j >= ar.size())
            return false;
        for(; j < ar.size(); j++ ){
            if (!std::isdigit(ar[j]))
                return false;
        }
        long holder = std::atoi(ar.c_str());
        if (holder >= INT_MAX)  
            return false;
        this->store.push_back(static_cast<int>(holder));
        i++;
    }
    return true;
}

void PmergeMe::display( void ) {
    for( std::vector<int>::const_iterator it = this->store.begin(); it != this->store.end();it++) {
        std::cout << *it << " ";
    }
    std::cout<<std::endl;
}
