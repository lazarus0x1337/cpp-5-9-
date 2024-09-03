#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat b("alisa",12);
    //RobotomyRequestForm Robot;
    //ShrubberyCreationForm Shrubbery;
    PresidentialPardonForm President;
    try
    {
        President.beSigned(b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " for signed." <<std::endl;
    }
    
    b.executeForm(President);
}