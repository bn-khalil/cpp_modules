#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <vector>
#include <climits>


class PmergeMe
{
    private:
        std::vector<int> store;

    public:
        PmergeMe();
        PmergeMe( const PmergeMe & other );
        PmergeMe & operator = ( const PmergeMe & other );
        ~PmergeMe();

        bool pasreInput(const char ** av);

        void display( void );
};

#endif