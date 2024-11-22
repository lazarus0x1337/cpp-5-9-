#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange btc;
    std::string line;
    if(ac != 2)
    return (std::cout << "error in  argument.\n",1);
    std::ifstream file(av[1]);
    if (!file.is_open())
        return (std::cout << "Error opening file for writing.\n",1);
    btc.readData(file);
    file.close();
}