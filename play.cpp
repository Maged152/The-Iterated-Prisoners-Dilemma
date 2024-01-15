#include "shakhbat_pd.hpp"
#include <iostream>

int main()
{
    qlm::TitForTat strategy0;
    strategy0.PrintInfo();

    qlm::AlwaysCooperate strategy1;
    strategy1.PrintInfo();

    auto m = qlm::Match(strategy0, strategy1, 20);
    
    m.Print();
}