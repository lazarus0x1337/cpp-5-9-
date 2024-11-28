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
double Ford_Johnson_algo(container& c)
{
    std::clock_t start = std::clock();
    std::vector<std::pair<int, int>> pairs;
    container smaller;
    container larger;
    size_t n = c.size();

    for (size_t i = 0 ; i < n/2 ; i++)
    {
        if (c[2*i] > c[2*i + 1])
            pairs.push_back({c[2*i + 1], c[2*i]});
        else
            pairs.push_back({c[2*i], c[2*i+1]});
    }
    if (n % 2 != 0)
        larger.push_back(c[n - 1]);

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        smaller.push_back(pairs[i].first);
        smaller.push_back(pairs[i].second);
    }

    std::sort(smaller.begin(), smaller.end());

    for (size_t i = 0; i < larger.size(); ++i)
    {
        typename container::iterator pos = std::lower_bound(smaller.begin(), smaller.end(), larger[i]);
        smaller.insert(pos, larger[i]);
    }
    std::clock_t end = std::clock();
    c.clear(); 
    c.insert(c.end(), smaller.begin(), smaller.end());
    return ((static_cast<double>(end - start) / CLOCKS_PER_SEC) * 100000);
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
    double elapsed_time_vector = Ford_Johnson_algo(array1);
    printArrays("after: ");
    double elapsed_time_deque = Ford_Johnson_algo(array2);
    std::cout << "\nTime taken to process a range of "<<array1.size()<<" elements with std::vector  : "<< std::fixed << std::setprecision(5) << elapsed_time_vector << " us" << std::endl;
    std::cout << "\nTime taken to process a range of "<<array1.size()<<" elements with std::deque  : "<< std::fixed << std::setprecision(5) << elapsed_time_deque << " us" << std::endl;
}
