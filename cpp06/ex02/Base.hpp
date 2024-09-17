#pragma once 
#include <iostream>
#include <ctime> 
#include <stdlib.h>

class Base{
    public :
             virtual ~Base();
};


class A : public Base {};
class C : public Base {};
class B : public Base {};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);