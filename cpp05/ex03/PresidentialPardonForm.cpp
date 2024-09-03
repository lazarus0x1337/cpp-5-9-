#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("Zaphod Beeblebrox",25,5),target("Arthur Dent")
{
    std::cout << "contractor default PresidentialPardon called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &b):target(b.target)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target):AForm(name,25,5),target(target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &b)
{
    if (this != &b)
        target = b.target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getGradeSign() || !this->getSigne())
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << target << "has been pardoned by Zaphod Beeblebrox."<<std::endl;
    }
}


