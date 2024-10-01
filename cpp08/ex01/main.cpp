#include "Span.hpp"
#include <stack>
int main()
{

    try {
        std::stack<int>a;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        //test for range of itr
        // std::vector<int> vec;
        // sp.addNumber(17);
        // sp.addNumber(9);
        // sp.addNumber(11);
        // sp.addnumbers(vec.begin(), vec.end());

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }catch(std::exception &e)
    {
        std::cout << e.what()<<std::endl;
    }
    return 0;
}