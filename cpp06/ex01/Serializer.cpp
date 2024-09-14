#include "Serializer.hpp"

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
}

Serializer::~Serializer()
{
}


uintptr_t Serializer::serialize(Data* ptr)
{
    
}