#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <climits>
#include <stdexcept>
#include <iomanip>
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
            void printArrays(std::string txt);
            void addElement(int value);
            void sort();
};

