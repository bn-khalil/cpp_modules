#include <vector>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe( const PmergeMe& other ) {
    *this = other;
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
        this->Vstore.push_back(static_cast<int>(holder));
        this->Dstore.push_back(static_cast<int>(holder));
        i++;
    }
    startAlgoDetails();
    return true;
}

double PmergeMe::processDurationVstore() {
    std::vector<std::vector<int> > suprator;
    for (size_t i = 0; i < Vstore.size(); i++)
    {
        std::vector<int> piece;
        piece.push_back(Vstore[i]);
        suprator.push_back(piece);
    }

    long first = get_time();
    mergeSortAlgVstore(suprator);
    long second = get_time();

    Vstore.clear();
    for (size_t i = 0; i < suprator.size(); i++) {
        Vstore.push_back(suprator[i][0]);
    }
    return (second - first) / 1000000.0;
}

double PmergeMe::processDurationDstore() {
    std::deque<std::deque<int> > suprator;
    for (size_t i = 0; i < Dstore.size(); i++)
    {
        std::deque<int> piece;
        piece.push_back(Dstore[i]);
        suprator.push_back(piece);
    }

    long first = get_time();
    mergeSortAlgDstore(suprator);
    long second = get_time();

    Dstore.clear();
    for (size_t i = 0; i < suprator.size(); i++) {
        Dstore.push_back(suprator[i][0]);
    }
    return (second - first) / 1000000.0;
}


void PmergeMe::mergeSortAlgVstore(std::vector<std::vector<int> > & f_container) {
    bool is_strg = false;
    std::vector<int> strg;  
    std::vector<int> orders;
    std::vector<std::vector<int> > wins;


    if (f_container.size() <= 1)
        return;
    
    if (f_container.size() % 2 != 0) {
        strg = f_container.back();
        f_container.pop_back();
        is_strg = true;
    }

    for (size_t i = 0; i < f_container.size(); i += 2) {
        if (f_container[i][0] < f_container[i+1][0])
            std::swap(f_container[i], f_container[i+1]);
        f_container[i].insert(f_container[i].end(), f_container[i+1].begin(), f_container[i+1].end());
        wins.push_back(f_container[i]);
    }
    
    mergeSortAlgVstore(wins);

    std::vector<std::vector<int> > main;
    std::vector<std::vector<int> > pend;

    size_t pair_s = wins[0].size() / 2;

    for (size_t i = 0; i < wins.size(); ++i) {
        std::vector<int> alpha(wins[i].begin(),  wins[i].begin() + pair_s);
        std::vector<int> beta(wins[i].begin() + pair_s, wins[i].end());
        main.push_back(alpha);
        pend.push_back(beta);
    }
    main.insert(main.begin(), pend[0]);

    orders = jacobVstore(pend.size());

    for (size_t i = 0; i < orders.size(); i++) {
        int index = orders[i];

        if (index == 1)
            continue ;
        std::vector<int> to_push = pend[index - 1];
        std::vector<std::vector<int> >::iterator it = std::lower_bound(main.begin(), main.end(), to_push);
        main.insert(it, to_push);
    }

    if (is_strg) {
        std::vector<std::vector<int> >::iterator it = std::lower_bound(main.begin(), main.end(), strg);
        main.insert(it, strg);
    }
    f_container = main;
}

std::vector<int> PmergeMe::jacobVstore(size_t len_generated) {
    std::vector<int> inx;
    std::vector<int> jcb;

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



void PmergeMe::mergeSortAlgDstore(std::deque<std::deque<int> > & f_container) {
    bool is_strg = false;
    std::deque<int> strg;  
    std::deque<int> orders;
    std::deque<std::deque<int> > wins;

    if (f_container.size() <= 1)
        return;
    
    if (f_container.size() % 2 != 0) {
        strg = f_container.back();
        f_container.pop_back();
        is_strg = true;
    }

    for (size_t i = 0; i < f_container.size(); i += 2) {
        if (f_container[i][0] < f_container[i+1][0])
            std::swap(f_container[i], f_container[i+1]);
        f_container[i].insert(f_container[i].end(), f_container[i+1].begin(), f_container[i+1].end());
        wins.push_back(f_container[i]);
    }
    
    mergeSortAlgDstore(wins);

    std::deque<std::deque<int> > main;
    std::deque<std::deque<int> > pend;
    size_t pair_s = wins[0].size() / 2;

    for (size_t i = 0; i < wins.size(); ++i) {
        std::deque<int> alpha(wins[i].begin(),  wins[i].begin() + pair_s);
        std::deque<int> beta(wins[i].begin() + pair_s, wins[i].end());
        main.push_back(alpha);
        pend.push_back(beta);
    }
    main.insert(main.begin(), pend[0]);

    orders = jacobDstore(pend.size());

    for (size_t i = 0; i < orders.size(); i++) {
        int index = orders[i];

        if (index == 1)
            continue ;
        std::deque<int> to_push = pend[index - 1];
        std::deque<std::deque<int> >::iterator it = std::lower_bound(main.begin(), main.end(), to_push);
        main.insert(it, to_push);
    }

    if (is_strg) {
        std::deque<std::deque<int> >::iterator it = std::lower_bound(main.begin(), main.end(), strg);
        main.insert(it, strg);
    }
    f_container = main;
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

double PmergeMe::get_time() {
    timeval	tv;
    gettimeofday(&tv, NULL);
    return static_cast<double>(tv.tv_sec) * 1000000.0 + static_cast<double>(tv.tv_usec);
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
    << this->Vstore.size() 
    << " elements with deque : " 
    << std::fixed << std::setprecision(5)
    << Dstoreduration 
    << " us" << std::endl;

    std::cout << "Time to process a range of " 
    << this->Vstore.size() 
    << " elements with vector : " 
    << std::fixed << std::setprecision(5)
    << Vstoreduration 
    << " us" << std::endl;
}