#include "Base.hpp"
#include <unistd.h>

int main()
{
    Base *random1 = generate();
    identify(random1);

    Base &random2 = *random1;
    identify(random2);

    delete random1;
}