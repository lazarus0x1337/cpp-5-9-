#pragma once
#include <iostream>
class AForm;
class Bureaucrat
{
    private:
            const std::string name;
            int grade;
    public:
            Bureaucrat();
            Bureaucrat(std::string n, int grade);
            ~Bureaucrat();
            Bureaucrat(const Bureaucrat &b);
            Bureaucrat& operator=(const Bureaucrat &b);
            
            std::string getName() const;
            int getGrade() const;
            void incrementGrade();
            void decrementGrade();
            void validateGrade(int grade);

            void signForm(AForm f);
            //EXCEPTION :
            class GradeTooHighException : public std::exception{
                public :
                         const char* what() const throw() ;
            };
            class GradeTooLowException : public std::exception{
                public :
                        const char* what() const throw() ;            
            };

            

};
std::ostream& operator<<(std::ostream& os, Bureaucrat b);