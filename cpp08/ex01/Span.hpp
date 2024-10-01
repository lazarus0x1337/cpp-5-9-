#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib> 

class Span
{
private:
        unsigned int N;
        std::vector<int> numbers;
public:
    Span();
    Span(unsigned int N);
    Span(const Span &b);
    Span& operator=(const Span &b);
    ~Span();
    void addNumber(int num);
    int shortestSpan() const;
    int longestSpan() const;
    
    template <class itr> void addnumbers(itr begin, itr end)
    {
        size_t count = std::distance(begin,end);
        std::cout << "count : " << count <<std::endl;
        if (numbers.size() + count > N)
            throw CapacityOverflowException();
        numbers.insert(numbers.end(),begin,end);
    }
    
    class CapacityOverflowException : public std::exception
    {
        public :
                const char* what() const throw()
                {
                    return "Capacity limit exceeded. Cannot add more elements.";
                }
    };

    class NoSpanException : public std::exception
    {
        public :
                const char* what() const throw()
                {
                    return "Not enough numbers to calculate a span.";
                }
    };
};
