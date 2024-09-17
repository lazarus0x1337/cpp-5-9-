#pragma once 
#include <iostream>
#include <stdint.h>

class Data
{
    std::string member;
    public:
            Data();
            Data(Data &b);
            ~Data();
            Data& operator=(const Data &n);
};

class Serializer
{
        Serializer();
        Serializer(Serializer &b);
    public:
            ~Serializer();
            Serializer& operator=(const Serializer &n);
            static uintptr_t serialize(Data* ptr) ;
            static Data* deserialize(uintptr_t raw) ;
};


