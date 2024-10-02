#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>
#include <iterator>

class NotFound : public std::exception{
    public:
            const char* what() const throw() {
        return "Element not found in the container";
    }
};

template <class T>  typename T::iterator easyfind(T& obj, int integer)
{
    typename T::iterator it = std::find(obj.begin(), obj.end(), integer);
     if (it == obj.end())
            throw NotFound();
    std::cout << "we found first occurence"<<std::endl;
    return (it);
}
