#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter &b)
{
    (void)b;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &b)
{
    (void)b;
    return (*this);
}

int stringToInt(const std::string& input)
{
    std::istringstream iss(input);
    int number;
    iss >> number;
    return number;
}

float stringToFloat(const std::string& input)
{
    std::istringstream iss(input);
    float number;
    iss >> number;
    return number;
}

double stringToDouble(const std::string& input)
{
    std::istringstream iss(input);
    double number;
    iss >> number;
    return number;
}

bool is_number(std::string str)
{
    unsigned int i = 0;
    int flag_dot = 0;
    int pos_dot  = -1;
    if (str[i] == '+' || str[i] == '-')
        i++;
    for (; i < str.size(); i++)
    {
        if (str[i] == 'f' && i != str.size() - 1)
            return false;
        if (str[i] == '.')
        {
            flag_dot++;
            pos_dot = i;
            continue;
        }
        if (!isdigit(str[i]) && str[i] != 'f')
            return false;
    }
    if (pos_dot != -1)
    {
        if (flag_dot != 1)
            return false;
        if (pos_dot == 0 || pos_dot == (int)(str.size() - 1))
            return false;
        else if (str[pos_dot + 1] == 'f')
            return false;
    }
    return true;        
}

int handle_char(std::string str)
{
    int num;
    std::cout << "char: ";
    if (str.size() == 1 && isalpha(str[0]))
    {
        std::cout << "\'"<< str[0]<<"\'"<<std::endl;
        return (2);
    }  
    if (is_number(str))
    {
        num = stringToInt(str);
        if (num >= 32 && num <= 126)
        {
            std::cout << "\'"<< (char)num<<"\'"<<std::endl;
            return (1);
        }
        else
            std::cout << "Non displayable"<<std::endl;
        return (1);
    }
    else
        std::cout << "impossible"<<std::endl;
    return (0);
}

void handle_int(int typ, std::string str)
{
    std::cout << "int: ";
    if (!typ)
        std::cout << "impossible"<<std::endl;
    else if (typ == 1)
        std::cout << stringToInt(str)<<std::endl;
    else
        std::cout << (int)str[0]<<std::endl;
}

void handle_irrational(int type,std::string type_literal, std::string str)
{
    
    std::cout << type_literal<<": ";
    if (!type)
    {
        if (type_literal[0] == 'f')
        {
            if (str == "-inf" || str == "-inff")
                std::cout << "-inff"<<std::endl;
            else if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
                std::cout << "+inff"<<std::endl;
            else    
                std::cout << "nanf"<<std::endl;
        
        }
        else
        {
            if (str == "-inf" || str == "-inff")
                std::cout << "-inf"<<std::endl;
            else if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
                std::cout << "+inf"<<std::endl;
            else    
                std::cout << "nan"<<std::endl;
        }
    }
    else if (type == 2)
    {
        if (type_literal[0] == 'f')
            std::cout << (float)str[0]<<"f"<<std::endl;
        else
            std::cout << (double)str[0]<<"f"<<std::endl;
    }
    else
    {
        if (type_literal[0] == 'f')
            std::cout <<stringToFloat(str)<<"f"<<std::endl;
        else
            std::cout << stringToDouble(str)<<std::endl;
    }
}

void ScalarConverter::convert(const std::string literal)
{
    int type = handle_char(literal);
    handle_int(type,literal);
    handle_irrational(type,"float",literal);
    handle_irrational(type,"double",literal);
}

