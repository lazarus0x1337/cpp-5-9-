#include "easyfind.hpp"
int main()
{
    try {
        std::vector<int> vec;
        vec.push_back(100);
        vec.push_back(202);
        vec.push_back(1);
        std::vector<int>::iterator a = easyfind(vec, 1);
        *a = 10000;
        for (const int& value : vec) {
            std::cout << value << std::endl; // Display all elements in the vector
        }
        std::vector<int>::iterator b = easyfind(vec, 1);
        (void)b;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;  
    }
}