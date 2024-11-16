#include "BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange()
{
    // std::ifstream file(DATABASE);
    // if (!file.is_open())
    // {
    //     std::cout << "Error opening file for writing.\n";
    //     exit(1);
    // }

}

BitcoinExchange::~BitcoinExchange()
{
    input.clear();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{

}

bool validDigits(std::string number)
{
    for(size_t i=0;i<number.size();i++)
        if(!std::isdigit(number[i]))
            return false;
    return true;
}
// bool isValidDate(const std::string& date)
// {
//     if (date.length() != 10 || (date[4] != '-' || date[7] != '-')) 
//         return (std::cout << "Error: invalid date.\n",false);
    
//     std::string year = date.substr(0, 4);
//     std::string month = date.substr(5, 2);
//     std::string day = date.substr(8, 2);
    
//     if (!validDigits(year) || !validDigits(month) || !validDigits(day))
//         return (std::cout << "Error: invalid date.\n",false);

//     int yearNum = std::atoi(year.c_str());
//     int monthNum = std::atoi(month.c_str());
//     int dayNum = std::atoi(day.c_str());

//     // Validate ranges for year, month, and day
//     if (yearNum < 0) return false;          // No negative years
//     if (monthNum < 1 || monthNum > 12) return false;
//     if (dayNum < 1 || dayNum > 31) return false; // Simplified day check

//     return true; // Passed all checks
// }


bool checkValue(std::string value)
{
    float amount = std::atof(value.c_str());
    if(amount < 0)
        return (std::cout << "Error: not a positive number.\n",false);
    if(amount > 1000)
        return (std::cout << "Error: too large a number.\n",false);
    return true;
}

void BitcoinExchange::readData(std::ifstream file)
{
    std::string line,key,value;
    float amount;
    while(std::getline(file,line))
    {
         std::istringstream lineStream(line);
        if (std::getline(lineStream, key, '|') && std::getline(lineStream, value))
        {
            if(key.empty() || value.empty())
            {
                std::cout << "Error: bad input\n";
                continue;
            }
            if(!checkValue(value))
                continue;
            process(key,amount);
        }
        else
            std::cout << "invalid format !\n";
    }
}

void BitcoinExchange::process(std::string key,float amount)
{
    input[key] = 
}