#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

class NotFound : public std::exception{
    public:
            const char* what() const throw() {
        return "Element not found in the container";
    }
};

template <class T> void easyfind(T obj, int integer)
{
    
     if (std::find(obj.begin(), obj.end(), integer) == obj.end())
            throw NotFound();
    std::cout << "we found first occurence"<<std::endl;
}