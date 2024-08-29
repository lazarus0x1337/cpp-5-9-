#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("alice"),grade(150)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &b):name(b.name),grade(b.grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &b)
{
   if (this != &b)
        grade = b.grade;
   return (*this);
}
//need form canonique

std::string Bureaucrat::getName()
{
    return name;
}

int Bureaucrat::getGrade()
{
    return grade;
}

void Bureaucrat::validateGrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();

}

void Bureaucrat::incrementGrade()       
{
    --grade;
    validateGrade(grade);
}
void Bureaucrat::decrementGrade()
{
    ++grade;
    validateGrade(grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "Error Grade is too Hight";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Error Grade is too Low";
}


std::ostream& operator<<(std::ostream& os, Bureaucrat b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os; 
}