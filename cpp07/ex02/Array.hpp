#pragma once 
#include <iostream>
#include <ctime> 
#include <stdlib.h>
template <class T> class Array{

            T* tab;
            unsigned int len;
    public :
            Array():tab(new T[0]),len(0){}
            ~Array()
            {
                delete[] tab;
            }
            Array(unsigned int n):tab(new T[n]),len(n){}
            Array(const Array& a)
            {
                len = a.len;
                tab = new T[len];
                for (unsigned int i = 0 ; i < len ;i++)
                    tab[i] = a.tab[i]; 
            }
            Array& operator=(const Array& a)
            {
                if (this != *a)
                {
                    len = a.len;
                    delete[] tab;
                    tab = new T[len];
                    for (unsigned int i = 0 ; i < len ;i++)
                        tab[i] = a.tab[i]; 
                }
                return (*this);
            }
            
            class OutOfRang : public std::exception{
                public :
                         const char* what() const throw()
                         {
                            return " index out of range !!";
                         }
            };
            
            T& operator[](unsigned int index)
            {
                if (index < 0 || index >= len)
                    throw  OutOfRang();
                else
                {
                    std::cout << "index exist !";
                    return tab[index];
                }
            }
            
            unsigned int size() const
            {
                return len;
            }
};