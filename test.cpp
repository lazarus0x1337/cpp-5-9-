#include <iostream>
#include <stdexcept> // For std::runtime_error

void func() {
    // Throw an exception
    throw std::runtime_error("An error occurred in func!");
}

int main() {
    // Call a function that throws an exception without handling it
    func();
    return 0;
}
