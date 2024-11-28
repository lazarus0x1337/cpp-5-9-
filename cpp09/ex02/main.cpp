#include "PmergeMe.hpp"

int main(int ac, char**av)
{
    if(ac < 2)
        return (1);
    try{
        int i = 0;
        PmergeMe merge;
        while (++i < ac)
            merge.Parse_Save(av[i]);
        merge.printArrays("Before: ");
        merge.sort();
    }catch(std::exception &e)
    {
        std::cout<< e.what()<<std::endl;
    }
}