#include "../include/fun.hpp"
#include <iostream>

void fun()
{
    #if __cplusplus == 202002L
        std::cout << "C++20\n";
    #elif __cplusplus == 201703L
        std::cout << "C++17\n";
    #elif __cplusplus == 201402L
        std::cout << "C++14\n";
    #elif __cplusplus == 201103L
        std::cout << "C++11\n";
    #else
        std::cout << "C++  standard pre-C++11 or unknown\n";
    #endif
    std::cout << "from fun\n";
}
