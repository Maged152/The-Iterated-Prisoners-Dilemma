#ifndef TEST_IPD
#define TEST_IPD

#include "../lib/include/shakhbat_pd.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <memory> 

// test strategies
std::vector<std::unique_ptr<qlm::Strategy>> strategy_list;

// Macro to declare a new strategy
#define ADD_STRATEGY(Strategy_name) strategy_list.push_back(std::make_unique<Strategy_name>());


#endif