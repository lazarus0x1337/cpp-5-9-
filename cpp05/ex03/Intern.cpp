#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(Intern &b)
{
    (void)b;
}
Intern& Intern::operator=(const Intern &b)
{
    (void)b;
    return (*this);
}

AForm* Intern::makeForm(std::string _name, std::string _target)
{
    int i;
    AForm *p = NULL;
    std::string Make[] = {"robotomy request", "presidential pardon", "shrubbery creation"};

    if (_name.empty() || _target.empty())
    {
        std::cout << "error : empty string !!"<<std::endl;
        return  p;
    }
    for(i =0; i < 3 ; i++)
        if (Make[i] == _name)
        {
            std::cout << "creation form : "<<std::endl;
            break;
        }
    switch (i)
    {
        case 0:
                p = new RobotomyRequestForm(_name,_target);
                std::cout << "Intern creates Robotomy Request Form."<<std::endl;
                break;
        case 1:
                p = new PresidentialPardonForm(_name,_target);
                std::cout << "Intern creates Presidential Pardon Form."<<std::endl;
                break;
        case 2:
                p = new ShrubberyCreationForm(_name,_target);
                std::cout << "Intern creates Shrubbery Form."<<std::endl;
                break;
        default:
                std::cout << "error : form not exist !!"<<std::endl;
                break;
    }
    return p;
}