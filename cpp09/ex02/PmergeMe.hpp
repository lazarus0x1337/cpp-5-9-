#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <climits>
#include <stdexcept>
class PmergeMe
{
    private:
            std::vector <int> array1;
            std::deque <int> array2;
    public:
            PmergeMe();
            PmergeMe(const PmergeMe& e);
            PmergeMe& operator=(const PmergeMe& other);
            ~PmergeMe();
            void Parse_Save(char* list);
            void printArrays();
};

