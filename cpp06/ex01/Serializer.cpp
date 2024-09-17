#include "Serializer.hpp"

Data::Data():member("empty")
{
}

Data::Data(Data &b):member(b.member)
{
}

Data& Data::operator=(const Data &n)
{
    if (this != &n)
        member = n.member;
    return (*this);
}

Data::~Data()
{
}

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer &b)
{
    (void)b;
}

Serializer& Serializer::operator=(const Serializer &n)
{
    (void)n;
    return (*this);
}

Serializer::~Serializer()
{
}


uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t p = reinterpret_cast<uintptr_t>(ptr);
    return p;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* p = reinterpret_cast<Data* >(raw);
    return p;
}