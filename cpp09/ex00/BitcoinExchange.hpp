#pragma once
#include <sstream>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#define DATABASE "data.csv"
class BitcoinExchange
{
        private:
                std::map<std::string, float> data;
        public:
                BitcoinExchange();
                BitcoinExchange(const BitcoinExchange& other);
                BitcoinExchange& operator=(const BitcoinExchange& other);
                ~BitcoinExchange();
                void readData(std::ifstream& file);
                void process(std::string key,float amount);
};


