#include "RPN.hpp"

RPN::RPN():result(0)
{
}

RPN::~RPN()
{
}


RPN::RPN(const RPN& a)
{
}

RPN& RPN::operator=(const RPN& a)
{

}


void RPN::calculate(char op)
{
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
}

int RPN::readExpression(char *b)
{
    status = START;
    int number;
    for(int i = 0; i < strlen(b) && status != ERROR; i++)
    {
        if (status == OPERAND && !std::isspace(b[i]))
        {
            status = ERROR;
            break;
        }
        if(std::isspace(b[i]))
            continue;
        if (status == OPERATOR)
            calculate(b[i]);
        if (std::isdigit(b[i]))
        {
            Operands.push(b[i] - '0');
            if (Operands.size() > 2)
                status = ERROR;
            else if (Operands.size() == 2)
                status = OPERATOR;
            else
                status = OPERAND;
        }
        else
            status = ERROR;
    }
}