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

template <typename container>
void binaryInsert(container& sorted, int value)
{
    typename container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

template <typename container>
void Ford_Johnson_algo(container& c)
{
    size_t n = c.size();
    if (n <= 1)
        return ; 
    container smaller, larger;
    for (size_t i = 0; i < n / 2; i++)
    {
        int a = c[2 * i];
        int b = c[2 * i + 1];
        if (a < b) {
            smaller.push_back(a);
            larger.push_back(b);
        } else {
            smaller.push_back(b);
            larger.push_back(a);
        }
    }
    if (n % 2 == 1)
        larger.push_back(c.back());
    Ford_Johnson_algo(larger);
    container S =  larger;
    binaryInsert(S, smaller[0]);
    for (size_t i = 1; i < smaller.size(); ++i)
        binaryInsert(S, smaller[i]);
    c.clear();
    c.insert(c.end(), S.begin(), S.end());
}



void PmergeMe::addElement(int value)
{
    array1.push_back(value);
    array2.push_back(value);
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
                addElement(number);
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
                addElement(number);
        }
        else
            throw std::invalid_argument("[Error] Invalid character in input !");
    }
}

void PmergeMe::printArrays(std::string txt)
{
    std::cout << txt;
    for(size_t i = 0; i < array2.size(); i++)
        std::cout<<array1[i]<< " ";
    std::cout << std::endl;
}


void PmergeMe::sort()
{
    std::clock_t start = std::clock();
    Ford_Johnson_algo(array1);
    printArrays("after: ");
    std::clock_t end = std::clock();
    double time1 = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000;
    std::clock_t start1 = std::clock();
    Ford_Johnson_algo(array2);
    std::clock_t end1 = std::clock();
    double time2 = (static_cast<double>(end1 - start1) / CLOCKS_PER_SEC) * 1000000;
    std::cout << "\nTime taken to process a range of "<<array1.size()<<" elements with std::vector  : " << time1 << " us" << std::endl;
    std::cout << "Time taken to process a range of "<<array1.size()<<" elements with std::deque  : " << time2 << " us" << std::endl;
}
