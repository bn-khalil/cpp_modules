#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <iomanip>


class PmergeMe
{
    private:
        std::deque<int> Dstore;
        std::vector<int> Vstore;
    public:
        PmergeMe();
        PmergeMe( const PmergeMe & other );
        PmergeMe & operator = ( const PmergeMe & other );
        ~PmergeMe();

        bool pasreInput(const char ** av);
        void displayVstore( void );
        void displayDstore( void );
        void mergeSortAlgVstore(int left, int right);
        void mergeSortAlgDstore(int left, int right);
        void mergerVstore(int left, int right, int middle);
        void mergerDstore(int left, int right, int middle);
        bool dup_Vstore();
        bool dup_Dstore();
        void mergeVstoreDetails();
        double processDurationVstore();
        double processDurationDstore();
};

#endif