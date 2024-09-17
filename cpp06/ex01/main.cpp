#include "Serializer.hpp"

int main()
{
    Data *olddata = new Data();
    std::cout << "old data : "<<olddata<<std::endl;
    
    uintptr_t ptr = Serializer::serialize(olddata);
    Data *newdata = Serializer::deserialize(ptr);
    std::cout << "new data : "<<newdata<<std::endl;
}