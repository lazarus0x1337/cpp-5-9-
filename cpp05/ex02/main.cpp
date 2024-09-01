#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat b("alisa",100);
        ShrubberyCreationForm a;
        a.execute(b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}