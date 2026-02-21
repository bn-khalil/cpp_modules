#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <deque>
#include <sys/time.h>

class PmergeMe
{
    private:
        std::vector<int> Vstore;
        std::deque<int> Dstore;
    public:
        PmergeMe();
        PmergeMe( const PmergeMe & other );
        PmergeMe & operator = ( const PmergeMe & other );
        ~PmergeMe();

        bool pasreInput(const char ** av);
        void displayVstore( void );
        void displayDstore( void );
        void startAlgoDetails();
        double get_time(void);

        double processDurationVstore();
        double processDurationDstore();

        void mergeSortAlgVstore(std::vector<std::vector<int> > & f_container);
        void mergeSortAlgDstore(std::deque<std::deque<int> > & f_container);

        std::vector<int> jacobVstore(size_t len_generated);
        std::deque<int> jacobDstore(size_t len_generated);

};

#endif