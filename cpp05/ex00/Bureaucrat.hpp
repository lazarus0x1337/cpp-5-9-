#pragma once
#include <iostream>

class Bureaucrat
{
    private:
            const std::string name;
            int grade;
    public:
            Bureaucrat();
            ~Bureaucrat();
            Bureaucrat(const Bureaucrat &b);
            Bureaucrat& operator=(const Bureaucrat &b);
            
            std::string getName();
            int getGrade();
            void incrementGrade();
            void decrementGrade();
            void validateGrade(int grade);

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