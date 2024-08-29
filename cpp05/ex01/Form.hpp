#pragma once
#include <iostream>


class Form
{
    private:
        const std::string name;
        bool signe;
        const int gradeSign;
        const int gradeExc;

    public:
        Form();
        ~Form();
        Form::Form(const Form &b);
        Form& operator=(const Form& b);

    // getters :
    std::string getName();
    bool getSigne();
    int getGradeSign();
    int getGradeExc();

    //exception : 
    class GradeTooHighException : public std::exception
    {
        public :
            const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public :
            const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, Form b);


std::ostream& operator<<(std::ostream& os, Form b)
{
    os << "FOrm -> name: " << b.getName();
    if (b.getSigne())
        os << " , is signed";
    else    
        os << " , is not signed";
    os << " , grade required to sign it: "<<b.getGradeSign();
    os << " , grade required to execute it: "<<b.getGradeExc()<<std::endl;
}