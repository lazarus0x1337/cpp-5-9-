#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
            std::string target;    
    public:
    PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm &b);
    PresidentialPardonForm& operator=(const PresidentialPardonForm &b);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const & executor) const;
};


