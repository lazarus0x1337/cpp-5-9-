#include "RPN.hpp"


int main(int ac, char **av)
{
    RPN     expression;
    if(ac != 2)
        return (std::cout << "error in  argument.\n",1);
    expression.readExpression(av[1]);
    expression.printResult();
}