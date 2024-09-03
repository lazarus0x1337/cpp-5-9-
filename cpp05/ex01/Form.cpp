#include "Form.hpp"

Form::Form():name("test"),signe(false),gradeSign(1),gradeExc(1)
{
}

Form::Form(std::string n, int gradeSign, int GradeExec):name(n),signe(false),gradeSign(gradeSign),gradeExc(GradeExec)
{
}

Form::~Form()
{
}

Form::Form(const Form &b):name(b.name),signe(b.signe),gradeSign(b.gradeSign),gradeExc(b.gradeExc)
{
}

Form& Form::operator=(const Form& b)
{
    if (this != &b)
        signe = b.signe;
    return (*this);   
}

std::string Form::getName()
{
    return name;
}

bool Form::getSigne()
{
    return signe;
}

int Form::getGradeSign()
{
    return gradeSign;
}

int Form::getGradeExc()
{
    return gradeExc;
}

void Form::beSigned(Bureaucrat b)
{
    if (b.getGrade() <= gradeSign)
        signe = true;
    else   
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Error Grade is too Hight for signed";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Error Grade is too Low for signed";
}


std::ostream& operator<<(std::ostream& os, Form b)
{
    os<<"FOrm -> name: " << b.getName();
    if (b.getSigne())
        os<<" , is signed";
    else    
        os<<" , is not signed";
    os<<" , grade required to sign it: "<<b.getGradeSign();
    os<<" , grade required to execute it: "<<b.getGradeExc()<<std::endl;
    return os;
}
