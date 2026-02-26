#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe( const PmergeMe & other ) {
    this->Vstore = other.Vstore;
    this->Dstore = other.Dstore;
}

PmergeMe & PmergeMe::operator = ( const PmergeMe &other ) {
    if (this != &other) {
        this->Vstore = other.Vstore;
        this->Dstore = other.Dstore;
    }
    return ( *this );
}

PmergeMe::~PmergeMe() {}

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
        long holder = std::atol(ar.c_str());
        if (holder > INT_MAX)
            return false;
        this->Vstore.push_back(holder);
        this->Dstore.push_back(holder);
        i++;
    }
    startAlgoDetails();
    return true;
}

double PmergeMe::processDurationVstore() {
    double first = get_current_time();
    std::vector<std::vector<int> > suprator;
    for (size_t i = 0; i < Vstore.size(); i++)
    {
        std::vector<int> piece;
        piece.push_back(Vstore[i]);
        suprator.push_back(piece);
    }

    mergeSortAlgVstore(suprator);

    Vstore.clear();
    for (size_t i = 0; i < suprator.size(); i++) {
        Vstore.push_back(suprator[i][0]);
    }
    double second = get_current_time();
    return (second - first);
}

void PmergeMe::mergeSortAlgVstore(std::vector<std::vector<int> > & c_numbers) {
    std::vector<int> strg;
    std::vector<int> orders;
    std::vector<std::vector<int> > winners;


    if (c_numbers.size() <= 1)
        return;
    
    if (c_numbers.size() % 2 != 0) {
        strg = c_numbers.back();
        c_numbers.pop_back();
    }

    for (size_t i = 0; i < c_numbers.size(); i += 2) {
        if (c_numbers[i][0] < c_numbers[i+1][0])
            std::swap(c_numbers[i], c_numbers[i+1]);
        c_numbers[i].insert(c_numbers[i].end(), c_numbers[i+1].begin(), c_numbers[i+1].end());
        winners.push_back(c_numbers[i]);
    }
    
    mergeSortAlgVstore(winners);

    std::vector<std::vector<int> > bigs;
    std::vector<std::vector<int> > lows;

    size_t pair_s = winners[0].size() / 2;

    for (size_t i = 0; i < winners.size(); ++i) {
        std::vector<int> alpha(winners[i].begin(),  winners[i].begin() + pair_s);
        std::vector<int> beta(winners[i].begin() + pair_s, winners[i].end());
        bigs.push_back(alpha);
        lows.push_back(beta);
    }
    bigs.insert(bigs.begin(), lows[0]);

    orders = jacobVstore(lows.size());

    for (size_t i = 0; i < orders.size(); i++) {
        int index = orders[i];

        if (index == 1)
            continue ;
        std::vector<int> to_push = lows[index - 1];
        std::vector<std::vector<int> >::iterator it = std::lower_bound(bigs.begin(), bigs.end(), to_push);
        bigs.insert(it, to_push);
    }

    if (!strg.empty()) {
        std::vector<std::vector<int> >::iterator it = std::lower_bound(bigs.begin(), bigs.end(), strg);
        bigs.insert(it, strg);
    }
    c_numbers = bigs;
}

std::vector<int> PmergeMe::jacobVstore(size_t len_generated) {
    std::vector<int> inx;
    std::vector<int> jcb;

    if (len_generated <= 0)
        return inx;
    jcb.push_back(1);
    inx.push_back(1);
    if (len_generated == 1)
        return inx;
    jcb.push_back(3);
    while (jcb[jcb.size() - 1] < (int)len_generated)
        jcb.push_back(jcb[jcb.size() - 1] + 2 * jcb[jcb.size() - 2]);

    size_t lst_jcb = 1;
    for (size_t i = 1; i < jcb.size(); i++) {
        size_t track = jcb[i];

        if (track > len_generated)
            track = len_generated;

        for (size_t j = track; j > lst_jcb; j--)
            inx.push_back(j);
        
        lst_jcb = track;
    }
    return inx;
}

double PmergeMe::processDurationDstore() {
    std::deque<std::deque<int> > suprator;
    double first = get_current_time();
    for (size_t i = 0; i < Dstore.size(); i++)
    {
        std::deque<int> piece;
        piece.push_back(Dstore[i]);
        suprator.push_back(piece);
    }

    mergeSortAlgDstore(suprator);

    Dstore.clear();
    for (size_t i = 0; i < suprator.size(); i++) {
        Dstore.push_back(suprator[i][0]);
    }
    double second = get_current_time();
    return (second - first);
}

void PmergeMe::mergeSortAlgDstore(std::deque<std::deque<int> > & c_numbers) {
    std::deque<int> strg;  
    std::deque<int> orders;
    std::deque<std::deque<int> > winners;

    if (c_numbers.size() <= 1)
        return;
    
    if (c_numbers.size() % 2 != 0) {
        strg = c_numbers.back();
        c_numbers.pop_back();
    }

    for (size_t i = 0; i < c_numbers.size(); i += 2) {
        if (c_numbers[i][0] < c_numbers[i+1][0])
            std::swap(c_numbers[i], c_numbers[i+1]);
        c_numbers[i].insert(c_numbers[i].end(), c_numbers[i+1].begin(), c_numbers[i+1].end());
        winners.push_back(c_numbers[i]);
    }
    
    mergeSortAlgDstore(winners);

    std::deque<std::deque<int> > bigs;
    std::deque<std::deque<int> > lows;
    size_t pair_s = winners[0].size() / 2;

    for (size_t i = 0; i < winners.size(); ++i) {
        std::deque<int> alpha(winners[i].begin(),  winners[i].begin() + pair_s);
        std::deque<int> beta(winners[i].begin() + pair_s, winners[i].end());
        bigs.push_back(alpha);
        lows.push_back(beta);
    }
    bigs.insert(bigs.begin(), lows[0]);

    orders = jacobDstore(lows.size());

    for (size_t i = 0; i < orders.size(); i++) {
        int index = orders[i];

        if (index == 1)
            continue ;
        std::deque<int> to_push = lows[index - 1];
        std::deque<std::deque<int> >::iterator it = std::lower_bound(bigs.begin(), bigs.end(), to_push);
        bigs.insert(it, to_push);
    }

    if (!strg.empty()) {
        std::deque<std::deque<int> >::iterator it = std::lower_bound(bigs.begin(), bigs.end(), strg);
        bigs.insert(it, strg);
    }
    c_numbers = bigs;
}

std::deque<int> PmergeMe::jacobDstore(size_t len_generated) {
    std::deque<int> inx;
    std::deque<int> jcb;

    if (len_generated <= 0)
        return inx;
    jcb.push_back(1);
    jcb.push_back(3);
    while (jcb[jcb.size() - 1] < (int)len_generated)
        jcb.push_back(jcb[jcb.size() - 1] + 2 * jcb[jcb.size() - 2]);

    inx.push_back(1);


    size_t lst_jcb = 1;
    for (size_t i = 1; i < jcb.size(); i++) {
        size_t track = jcb[i];

        if (track > len_generated)
            track = len_generated;

        for (size_t j = track; j > lst_jcb; j--)
            inx.push_back(j);
        
        lst_jcb = track;
    }
    return inx;
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

double PmergeMe::get_current_time() {
    timeval	tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

void PmergeMe::startAlgoDetails() {
    double Vstoreduration;
    double Dstoreduration;

    std::cout << "Before: ";
    displayVstore();
    Vstoreduration = processDurationVstore();
    Dstoreduration = processDurationDstore();
    std::cout << "After:  ";
    displayVstore();

    std::cout << "Time to process a range of " 
    << this->Dstore.size() 
    << " elements with std::deque : " 
    << Dstoreduration 
    << " us" << std::endl;

    std::cout << "Time to process a range of " 
    << this->Vstore.size() 
    << " elements with std::vector : " 
    << Vstoreduration 
    << " us" << std::endl;
}