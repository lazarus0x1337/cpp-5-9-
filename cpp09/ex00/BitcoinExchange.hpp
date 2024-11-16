#pragma once
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#define DATABASE "data.csv"
class BitcoinExchange
{
private:
        std::map<std::string, float> input;
public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        void readData(std::ifstream file);
        void process(std::string key,float amount);
};


