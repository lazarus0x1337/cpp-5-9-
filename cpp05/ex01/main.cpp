#include "Form.hpp"

int main()
{
  Bureaucrat b("joe",4);
  Form f("form1",3,1);
  try{
        std::cout << "- " << b << std::endl;
        std::cout << "- "<< f << std::endl;
        f.beSigned(b);
        b.signForm(f);
    }
    catch(std::exception &e)
    {
            std::cout << e.what() << std::endl;
            b.signForm(f);
    }

}