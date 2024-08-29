#include "Bureaucrat.hpp"

int main()
{
    // test 1 : 
    try
    {
        Bureaucrat c;
        c.decrementGrade();
    }
    catch(std::exception &e)
    {
        std::cout << "Exception : ";
        std::cout << e.what() <<  std::endl;
    }

    // test 2 :
    try
    {
        Bureaucrat b;
        std::cout << b << std::endl;
        b.decrementGrade();
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what();
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what();
    }
}