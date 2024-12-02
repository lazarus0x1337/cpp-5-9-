#include "BitcoinExchange.hpp"

bool isValidFloat(const std::string& str ,float& value, bool flaginput) {
    if (str.empty())
        return false;
    std::istringstream iss(str);
    iss >> value;
    if (flaginput)
    {
        if(value < 0)
        return (std::cout << "Error: not a positive number.\n",false);
        if(value > 1000)
        return (std::cout << "Error: too large a number.\n",false);
        if (!(!iss.fail() && iss.eof()))
            std::cout << "Error:  bad input.\n\""<<str<<"\"";
    }
    return (!iss.fail() && iss.eof());
}

BitcoinExchange::BitcoinExchange()
{
    std::string line,key,value;
    std::ifstream file(DATABASE);
    float result;
    if (!file.is_open())
    {
        std::cout << "DATABASE NOT EXIST .\n";
        exit(1);
    }
    while(std::getline(file,line))
    {
         std::istringstream lineStream(line);
        if (std::getline(lineStream, key, ',') && std::getline(lineStream, value))
            if (isValidFloat(value,result, false))
                data[key] = result;
    }
}

BitcoinExchange::~BitcoinExchange()
{
    data.clear();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
        this->data = other.data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
        if (this != &other)
            this->data = other.data;
        return *this;  
}


std::string trim(const std::string& str)
{
    size_t start = 0;
    while (start < str.size() && std::isspace(str[start]))
        ++start;
    size_t end = str.size();
    while (end > start && std::isspace(str[end - 1]))
        --end;
    return str.substr(start, end - start);
}

bool  isValidDate(std::string key)
{
    if (!isdigit(key[0]) || !isdigit(key[1]) || !isdigit(key[2]) || !isdigit(key[3]) ||
        key[4] != '-' || !isdigit(key[5]) || !isdigit(key[6]) || key[7] != '-' ||
        !isdigit(key[8]) || !isdigit(key[9]))
    {
        std::cout << "Error: Invalid Date !"<<std::endl;
        return false;
    }
    int month = std::stoi(key.substr(5, 2));
    int day = std::stoi(key.substr(8, 2));
    if (month < 1 || month > 12)
    {
        std::cout << "Error: Invalid month !"<<std::endl;
        return false;
    }
    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day < 1 || day > daysInMonth[month - 1])
    {
        std::cout << "Error: Invalid day !"<<std::endl;
        return false;
    }
    return true;
}
void BitcoinExchange::readData(std::ifstream& file)
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
            if(!(isValidFloat(value,amount,true)) ||  !isValidDate(key))
                continue;
           process(trim(key),amount);
        }
        else
            std::cout << "Error:invalid format !\n";
    }
}

void BitcoinExchange::process(std::string key,float amount)
{
    /*
        lower_bound(key): This function returns the first element 
        where the key is greater than or equal to key
    */
    std::map<std::string, float>::iterator it = data.find(key);
    if (it != data.end())
        std::cout << key<<" => "<< amount << " = " << (amount * it->second)<< "\n";
    else
    {
        it = data.lower_bound(key);
        if (it != data.begin() && it != data.end())
            std::cout << key<<" => "<< amount <<" = " << (amount * std::prev(it)->second) << "\n";
        else
            std::cout << "Error: i cant get lower date.\n";
    }
}