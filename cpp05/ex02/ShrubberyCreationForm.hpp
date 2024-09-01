#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
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
class ShrubberyCreationForm : AForm
{
    private:
            std::string target;
    public:
            ShrubberyCreationForm();
            ShrubberyCreationForm(ShrubberyCreationForm &b);
            ShrubberyCreationForm& operator=(ShrubberyCreationForm &b);
            ~ShrubberyCreationForm();
            void execute(Bureaucrat const &executor) const;
            
};
