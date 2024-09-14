#include <iostream>
#include <sstream>  // For std::istringstream
#include <string>

int stringToInt(const std::string& input) {
    std::istringstream iss(input);  // Create an input string stream
    int number;
    iss >> number;  // Extract the integer from the stream
    if (iss.fail()) {
        throw std::invalid_argument("Invalid input: not a valid integer");
    }
    return number;
}

int main(int ac, char **av) {
    std::string input = av[1];  // Example input
    try {
        // need to check for caracter alpha :  just we need string.back()=='f'
        int number = stringToInt(input);
        // same thing for float and double !!
        std::cout << "Converted number: " << number << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
