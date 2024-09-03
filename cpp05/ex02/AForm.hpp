#pragma once
#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string name;
        bool signe;
        const int gradeSign;
        const int gradeExc;

    public:
        AForm();
        AForm(std::string n, int gradeSign, int GradeExec);
        virtual ~AForm();
        AForm(const AForm &b);
        AForm& operator=(const AForm& b);
        virtual void execute(Bureaucrat const & executor) const = 0 ;

    // getters :
    std::string getName() const;
    bool getSigne() const;
    int getGradeSign() const;
    int getGradeExc() const;

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