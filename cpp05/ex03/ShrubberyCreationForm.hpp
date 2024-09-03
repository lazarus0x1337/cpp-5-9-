#pragma once
#include "AForm.hpp"
#include <fstream>

#define ASCII_TREE \
"       _-_        \n" \
"    /~~   ~~\\    \n" \
" /~~         ~~\\ \n" \
"{               }\n" \
" \\  _-     -_  / \n" \
"   ~  \\\\ //  ~   \n" \
"_- -   | | _- _  \n" \
"  _ -  | |   -_  \n" \
"      // \\\\      \n"
class ShrubberyCreationForm :public AForm
{
    private:
            std::string target;
    public:
            ShrubberyCreationForm();
            ShrubberyCreationForm(ShrubberyCreationForm &b);
            ShrubberyCreationForm(std::string name, std::string target);
            ShrubberyCreationForm& operator=(const ShrubberyCreationForm &b);
            ~ShrubberyCreationForm();
            void execute(Bureaucrat const &executor) const;
            
};
