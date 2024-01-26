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
std::vector<std::unique_ptr<qlm::Strategy>> strategy_list0;
std::vector<std::unique_ptr<qlm::Strategy>> strategy_list1;

// Macro to declare a new strategy
#define ADD_STRATEGY(Strategy_name) strategy_list0.push_back(std::make_unique<Strategy_name>()); \
                                    strategy_list1.push_back(std::make_unique<Strategy_name>());


#endif