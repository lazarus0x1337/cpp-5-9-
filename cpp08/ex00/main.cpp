#include "easyfind.hpp"
int main()
{
    try {
        std::vector<int> vec;
        vec.push_back(100);
        vec.push_back(202);
        vec.push_back(1);
        easyfind(vec, 1);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;  
    }
}