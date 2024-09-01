#include "AForm.hpp"

AForm::AForm():name("test"),signe(false),gradeSign(1),gradeExc(1)
{
}

AForm::AForm(std::string n, int gradeSign, int GradeExec):name(n),signe(false),gradeSign(gradeSign),gradeExc(GradeExec)
{
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &b):name(b.name),signe(b.signe),gradeSign(b.gradeSign),gradeExc(b.gradeExc)
{
}

AForm& AForm::operator=(const AForm& b)
{
    if (this != &b)
        signe = b.signe;
    return (*this);   
}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getSigne() const
{
    return signe;
}

int AForm::getGradeSign() const
{
    return gradeSign;
}

int AForm::getGradeExc() const
{
    return gradeExc;
}

void AForm::beSigned(Bureaucrat b)
{
    if (b.getGrade() <= gradeSign)
        signe = true;
    else   
        throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Error Grade is too Hight for signed";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Error Grade is too Low for signed";
}


// std::ostream& operator<<(std::ostream& os, AForm b)
// {
//     os<<"FOrm -> name: " << b.getName();
//     if (b.getSigne())
//         os<<" , is signed";
//     else    
//         os<<" , is not signed";
//     os<<" , grade required to sign it: "<<b.getGradeSign();
//     os<<" , grade required to execute it: "<<b.getGradeExc()<<std::endl;
//     return os;
// }
