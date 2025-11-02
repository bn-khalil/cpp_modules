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

bool PmergeMe::dup_Vstore() {
    std::vector<int>::const_iterator index = this->Vstore.begin();
    while(index != this->Vstore.end()) {
        for(
            std::vector<int>::const_iterator it = index + 1;
            it != this->Vstore.end() ;
            it++) {
            if (*it == *index)
                return false;
        }
        index++;
    }
    return true;
}

bool PmergeMe::dup_Dstore() {
    std::deque<int>::const_iterator index = this->Dstore.begin();
    while(index != this->Dstore.end()) {
        for(
            std::deque<int>::const_iterator it = index + 1;
            it != this->Dstore.end() ;
            it++) {
            if (*it == *index)
                return false;
        }
        index++;
    }
    return true;
}

bool PmergeMe::pasreInput(const char ** av) {

    int i = 1;

    while (av[i]) {
        std::string ar(av[i]);

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
        this->Vstore.push_back(static_cast<int>(holder));
        this->Dstore.push_back(static_cast<int>(holder));
        i++;
    }
    if (!dup_Vstore())
        return false;
    if (!dup_Vstore())
        return false;
    std::cout << "Before: ";
    displayVstore();
    mergeSortAlgVstore(0, this->Vstore.size() - 1);
    std::cout << "After:  ";
    displayVstore();
    return true;
}

void PmergeMe::mergerVstore(int left, int right, int middle) {
    std::vector<int> pair_1;
    std::vector<int> pair_2;
    
    for (int i = left; i <= middle; i++) {
        pair_1.push_back(this->Vstore[i]);
    }
    for (int i = middle + 1; i <= right; i++) {
        pair_2.push_back(this->Vstore[i]);
    }

    size_t i = 0;
    size_t j = 0;
    size_t r = left;

    for (;i < pair_1.size()  && j < pair_2.size();){
        if (pair_1[i] <= pair_2[j])
            this->Vstore[r++] = pair_1[i++];
        else
            this->Vstore[r++] = pair_2[j++];
    }

    for (; i < pair_1.size();){
        this->Vstore[r++] = pair_1[i++];
    }

    for (; j < pair_2.size() ;) {
        this->Vstore[r++] = pair_2[j++];
    }
}

void PmergeMe::mergeSortAlgVstore(int left, int right) {
    if (left >= right)
        return ;
    int container_mid = left + (right - left) / 2;
    mergeSortAlgVstore(left, container_mid);
    mergeSortAlgVstore(container_mid + 1, right);
    mergerVstore(left, right, container_mid);
}

void PmergeMe::displayVstore( void ) {
    for( std::vector<int>::const_iterator it = this->Vstore.begin();
    it != this->Vstore.end();
    it++) {
        std::cout << *it << " ";
    }
    std::cout<<std::endl;
}

void PmergeMe::displayDstore( void ) {
    for( std::deque<int>::const_iterator it = this->Dstore.begin();
     it != this->Dstore.end();
     it++) {
        std::cout << *it << " ";
    }
    std::cout<<std::endl;
}

void PmergeMe::displayToProcessVstore(){

};