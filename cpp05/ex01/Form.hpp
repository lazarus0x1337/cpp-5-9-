#pragma once
#include "Bureaucrat.hpp"


class Form
{
    private:
        const std::string name;
        bool signe;
        const int gradeSign;
        const int gradeExc;

    public:
        Form();
        Form(std::string n, int gradeSign, int GradeExec);
        ~Form();
        Form(const Form &b);
        Form& operator=(const Form& b);

    // getters :
    std::string getName();
    bool getSigne();
    int getGradeSign();
    int getGradeExc();

    void beSigned(Bureaucrat b);

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