#include <algorithm>
#include <iostream>
#include <vector>
#include <exception>

class NotFoundException : public std::exception {
public:
    const char* what() const throw() {
        return "Element not found in the container";
    }
};

template <typename T> void easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw NotFoundException();
    }
}

int main() {
    try {
        std::vector<char> vec = {' ', '2', '3', '4', '5'};
        easyfind(vec, 322);  // Searching for an element that doesn't exist
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;  // Output: Element not found in the container
    }
}
