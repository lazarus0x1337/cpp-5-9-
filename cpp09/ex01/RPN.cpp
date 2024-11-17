#include "RPN.hpp"

RPN::RPN():result(0),status(SUCCESS)
{
}

RPN::~RPN()
{
    while (!Operands.empty())
        Operands.pop();
}


RPN::RPN(const RPN& a)
{
    Operands = a.Operands;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        Operands = other.Operands;
    return *this;
}

void RPN::printResult()
{
    if (status == ERROR)
        std::cout << "Error\n";
    else
        std::cout << result;
}

void RPN::calculate(char op)
{
    result = 0;
    if (Operands.size() < 2)
    {
        status  = ERROR;
        return;
    }
    int operand2 = Operands.top();
    Operands.pop();
    int operand1 = Operands.top();
    Operands.pop();
    if (op == '+')
        result += operand1 + operand2;
    else if (op == '-')
        result += operand1 - operand2;
    else if (op == '/')
    {
        if(operand2 == 0)
        {
            status = ERROR;
            return;
        }
        result += operand1 / operand2;
    }
    else if (op == '*')
        result += operand1 * operand2;
    else
        status = ERROR;
    Operands.push(result);

}

void RPN::readExpression(char *b)
{
    for(size_t i = 0; i < strlen(b) && status != ERROR; i++)
    {
        if(std::isspace(b[i]))
            continue;
        if (std::isdigit(b[i]))
        {
            if( i > 0 && !std::isspace(b[i - 1]))
                status = ERROR;
            Operands.push(b[i] - '0');
        }
        else if (strchr("+-*/", b[i]))
            calculate(b[i]);
        else
            status = ERROR;
    }

    if (Operands.size() == 1 && status != ERROR)
        result = Operands.top();
    else
        status = ERROR;
}