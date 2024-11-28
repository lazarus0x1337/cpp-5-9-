#include "PmergeMe.hpp"

int main(int ac, char**av)
{
    if(ac < 2)
        return (1);
    try{
        int i = 0;
        PmergeMe merge;
        std::cout <<"Before: ";
        while (++i < ac)
            merge.Parse_Save(av[i]);
        merge.printArrays();
    }catch(std::exception &e)
    {
        std::cout<< e.what()<<std::endl;
    }
}