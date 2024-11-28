#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
    array1.clear();
    array2.clear();
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    array1 = other.array1;
    array2 = other.array2;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        array1 = other.array1;
        array2 = other.array2;
    }

    return *this;
}

template <typename Container>
void addElement(Container& container, int value)
{
    container.push_back(value);
}

void PmergeMe::Parse_Save(char* list)
{
    int number = 0;
    bool inNumber = false;

    for(const char* p = list; *p != '\0'; ++p)
    {
        if (std::isspace(*p))
        {
            if(inNumber)
            {
                addElement(array1,number);
                addElement(array2,number);
                inNumber = false;
                number = 0;
            }
        }
        else if (std::isdigit(*p))
        {
             int digit = *p - '0';
            if (number > (INT_MAX - digit) / 10)
                throw std::overflow_error("[Error] Number too large !");
            number = number * 10 + digit;
            inNumber = true;
            if(*(p+1) == '\0')
            {
                addElement(array1,number);
                addElement(array2,number);
            }
        }
        else
            throw std::invalid_argument("[Error] Invalid character in input !");
    }
}

void PmergeMe::printArrays()
{
// {   std::cout << "\n vector: \n";
//     for(size_t i = 0; i < array1.size(); i++)
//         std::cout<<array1[i]<< " ";
    // std::cout << "\n deque: \n";
    for(size_t i = 0; i < array2.size(); i++)
        std::cout<<array2[i]<< " ";
}

