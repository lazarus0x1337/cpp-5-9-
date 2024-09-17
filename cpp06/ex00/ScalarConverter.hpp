#pragma once
#include <iostream>
#include <sstream>
#include <iomanip> 

class ScalarConverter
{       
                ScalarConverter();
                ScalarConverter(ScalarConverter &b);
        public:
                ScalarConverter& operator=(const ScalarConverter &b);
                ~ScalarConverter();
                static void convert(const std::string literal);
};

