#pragma once 
#include <iostream>

template <class T> void printelement(T elem);
template <class T, class F> void iter(T* array,std::size_t len, F func);