#include "Base.hpp"

Base::~Base() {
}

Base * generate(void)
{
    std::srand(std::time(0));
    int random = std::rand() % 3;
    if (random == 0)
        return (new A());
    else if (random == 1)
        return (new C());
    else
        return (new B());
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << " the actual type of the object : A "<<std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << " the actual type of the object : B "<<std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << " the actual type of the object : C "<<std::endl;
    else
        std::cout << "type ?"<<std::endl;
}

void identify(Base& p)
{
    try{
        A& a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << " the actual type of the object : A "<<std::endl;
    }
    catch(std::exception& e)
    {
        (void)e;
        try{
                B& b = dynamic_cast<B &>(p);
                (void)b;
                std::cout << " the actual type of the object : B "<<std::endl;
            }
            catch(std::exception& e)
            {
                (void)e;
                try{
                        C& c = dynamic_cast<C &>(p);
                        (void)c;
                        std::cout << " the actual type of the object : C "<<std::endl;
                    }
                catch(std::exception& e)
                {
                    (void)e;
                    std::cout << "type ?"<<std::endl;
                }
            }
    }
}