#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl; //mstack.back for list container
    mstack.pop(); // pop_back for list container
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(-37);
    mstack.push(9999);
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

    // example 2 : 
    MutantStack<int> ms;
    ms.push(10);
    ms.push(20);
    ms.push(30);
    ms.push(40);
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
        std::cout << *it << std::endl;
    return 0;
}