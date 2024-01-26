#include "shakhbat_pd.hpp"
#include <iostream>

int main()
{
    // first strategy
    qlm::FirstByJoss strategy_0;

    // second strategy
    qlm::TitForTat strategy_1;

    // match parameters
    const unsigned int num_rounds = 15;
    const qlm::PayOff pay_off {}; // default pay off
    const int seed = 0; // seed for  probabilistic strategies

    qlm::MatchResult match = qlm::Match(strategy_0, strategy_1, num_rounds, pay_off, seed);
    
    // print results
    match.Print();

    // save results as csv file
    match.SaveAsCSV("match_results.csv");
}