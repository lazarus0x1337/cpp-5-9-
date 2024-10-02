#include "Span.hpp"

Span::Span(){}
Span::Span(unsigned int N):N(N){}
Span::~Span(){}

void Span::addNumber(int num)
{
    if (numbers.size() >= N)
        throw CapacityOverflowException();
    numbers.push_back(num); 
}

int Span::shortestSpan() const
{
    int shortestspan;
    if (numbers.size() < 2)
        throw NoSpanException();
    shortestspan = abs(numbers[1] - numbers[0]);
    for (size_t i = 2; i < numbers.size() ;i++)
        if (abs(numbers[i] - numbers[i-1]) < shortestspan)
            shortestspan = abs(numbers[i] - numbers[i-1]); //  need to verifier this !!
    return  shortestspan;
}

int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw NoSpanException();
    std::vector<int>::const_iterator it_min = std::min_element(numbers.begin(), numbers.end());
    std::vector<int>::const_iterator it_max = std::max_element(numbers.begin(),numbers.end());
    return (*it_max - *it_min);
}

Span::Span(const Span &b):N(b.N)
{
    numbers = b.numbers;
}

Span& Span::operator=(const Span &b)
{
    if (this != &b)
    {
        N = b.N;
        numbers = b.numbers;
    }
    return *this;
}

