#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("Shrubbery",145,137),target("home")
{
    std::cout << "contractor default Shrubbery called"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &b):target(b.target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target):AForm(name,145,137),target(target)
{
}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &b)
{
    if (this != &b)
        target = b.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
   if (executor.getGrade() > this->getGradeSign() || !this->getSigne())
        throw AForm::GradeTooLowException();
   else
   {
    std::string filename = target + std::string("_shrubbery");
    std::ofstream outFile(filename.c_str());
    if (!outFile.is_open())
    {
        std::cout << "error open file"<<std::endl;
        return ;
    }
    outFile << ASCII_TREE;
    std::cout << "file "<<filename << " has been created successfully."<<std::endl;
    outFile.close();
   }
}
