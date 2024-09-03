// Required grades: sign 72, exec 45
#pragma once
#include "AForm.hpp"

class RobotomyRequestForm :public AForm
{
    private:
            std::string target;
    public:
            RobotomyRequestForm();
            RobotomyRequestForm(RobotomyRequestForm &b);
            RobotomyRequestForm(std::string name, std::string target);
            RobotomyRequestForm& operator=(const RobotomyRequestForm &b);
            ~RobotomyRequestForm();
            void execute(Bureaucrat const & executor) const;
};
