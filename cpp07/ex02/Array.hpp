#pragma once 
#include <iostream>

template <class T> class Array{

            T* array;
            unsigned int len;
    public :
            Array():array(new array[0]),len(0){}
            ~Array()
            {
                delete[] array;
            }
            array(unsigned int n):array(new array[n]),len(n){}
            array(const array& tab)
            {
                len = tab.len;
                array = new array[len];
                for (unsigned int i = 0 ; i < len ;i++)
                    array[i] = tab.array[i]; 
            }
            array& operator=(const array& tab)
            {
                if (this != *tab)
                {
                    len = tab.len;
                    delete[] array;
                    array = new array[len];
                    for (unsigned int i = 0 ; i < len ;i++)
                        array[i] = tab.array[i]; 
                }
                return (*this);
            }


            unsigned int size() const
            {
                return len;
            }


};