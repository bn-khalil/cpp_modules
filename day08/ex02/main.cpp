#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "TEST 1 |=======================================|" << std::endl;

    // TEST 1

    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    std::cout << "TEST 2 |=======================================|" << std::endl;

    // TEST 2

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator b = lst.begin();
    std::list<int>::iterator e = lst.end();
    ++b;
    --b;
    while (b != e)
    {
        std::cout << *b << std::endl;
        ++b;
    }

    std::cout << "TEST 3 |=======================================|" << std::endl;

    // TEST 3

    MutantStack<std::string> stk;

    stk.push("bn");
    stk.push("kb");

    MutantStack<std::string>::iterator sit = stk.begin();
    MutantStack<std::string>::iterator site = stk.end();

    std::cout << *sit << std::endl;
    --site;
    std::cout << *site << std::endl;

    return 0;
}