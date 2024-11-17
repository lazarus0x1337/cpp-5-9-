#pragma once
#include <iostream>
#include <string.h>
#include <stack>

enum State {
    SUCCESS,
    ERROR
};

class RPN
{
    private:
            std::stack<int> Operands;
            int result ;
            State status;
    public:
            RPN();
            ~RPN();
            RPN(const RPN& a);
            RPN& operator=(const RPN& a);
            void readExpression(char *b);
            void calculate(char op);
            void printResult();
};

