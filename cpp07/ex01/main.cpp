#include "iter.hpp"

int main()
{
    int a[] = {1, 5 ,1337, -11 ,23 ,109 };
    iter(a,6,printelement<int>);
    std::cout << "\n";
    char ch[] = {'a','b','c','d','e'};
    iter(ch,5,printelement<char>);
    std::cout << "\n";
    std::string strArray[] = {"aaaaaaa","bbbbbbbb","ccccccc","dddddddddd"};
    iter(strArray,4,printelement<std::string>);
}


template <class T> void printelement(T elem)
{
    std::cout << elem <<" ";
}
template <class T, class F> void iter(T* array,std::size_t len, F func)
{
    if (len == 0) 
        return;
    for (std::size_t i = 0; i < len ; i++)
        func(array[i]);
}