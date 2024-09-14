#include <iostream>

class Serializer
{

    public:
            Serializer();
            ~Serializer();
            Serializer(Serializer &b);
            Serializer& operator=(const Serializer &n);

            uintptr_t serialize(Data* ptr);
            Data* deserialize(uintptr_t raw);
};


