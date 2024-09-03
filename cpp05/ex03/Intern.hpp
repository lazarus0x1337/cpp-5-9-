#pragma once
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
            Intern();
            Intern(Intern &b);
            Intern& operator=(const Intern &b);
            ~Intern();

            AForm* makeForm(std::string s1, std::string s2); 
};


