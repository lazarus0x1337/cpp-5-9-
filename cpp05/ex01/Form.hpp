#pragma once

class Form
{
private:
        const std::string name;
public:
    Form();
    ~Form();
    Form::Form(const Form &b);
    Form& operator=(const Form& b);
};

