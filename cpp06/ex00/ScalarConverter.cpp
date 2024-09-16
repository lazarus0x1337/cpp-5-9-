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

bool is_number(std::string str)
{
    int i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    for (; i < str.size() - 1; i++)
        if (!isdigit(str[i]))
            return false;
    if (str.back() != 'f' && !isdigit(str[i]))
        return false;
    return true;        
}


void ScalarConverter::convert(const std::string literal)
{
    // handling char :
    std::cout << "char: ";
    // if(is_number(literal))
    // {
    //     int num = stringToInt(literal,is_number(literal));
    //     if (num >= 32 && num <= 126)
    //        std::cout << "\'"<< (char)num<<"\'";
    //     else
    //         std::cout << "Non displayable"<<std::endl;
    // }
    // else
    //     std::cout << " "<<std::endl; 
}



// int stringToInt(const std::string& str, int flag)
// {
//     int num_exctracting;
//     if (flag == 1)
//         return (int)str[0];
//     std::istringstream converting(str);
//     converting >> num_exctracting;
//     return num_exctracting;
// }

// int is_number(std::string literal)
// {
//     //case for one caracter :
//     if (literal.size() == 1 && !isdigit(literal[0]))
//         return 1;
//     unsigned int i = 0;
//     int flag = 0;
//     if (literal[i] =='-' || literal[i] == '+')
//         i++;
//     for( ; i < literal.length() ; i++)
//     {
//         if (!isdigit(literal[i]))
//             return 0;
//         flag = 1;
//     }
//     if (flag)
//         return 2;
//     return 0;
// }


// int stringToInt(const std::string& str)
// {
//     int num_exctracting;
//     std::istringstream converting(str);
//     converting >> num_exctracting;
//     return num_exctracting;
// }

