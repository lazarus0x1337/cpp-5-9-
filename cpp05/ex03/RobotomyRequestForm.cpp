#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("Robotomy",72,45),target("Michael")
{
    std::cout << "contractor default Robotomy called"<<std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target):AForm(name,72,45),target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &b):target(b.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &b)
{
    if (this != &b)
        target = b.target;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
   if (executor.getGrade() > this->getGradeSign() || !this->getSigne())
   {
        std::cout << " the robotomy "<< target<<" failed."<<std::endl; 
        throw AForm::GradeTooLowException();
   }
   else
   {
        std::cout << "zzzzzzzzttttttttzzzzzzzzzzttttttttzzzzzzzzztttttttttzzzzzzzzzzzzz"<<std::endl;
        std::cout << target << " has been robotomized successfully 50\% of the time"<<std::endl;
   } 
}