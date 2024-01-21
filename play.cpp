#include "shakhbat_pd.hpp"
#include <iostream>

int main()
{
    qlm::FirstByDavis strategy0;
    strategy0.PrintInfo();

    qlm::Defector strategy1;
    strategy1.PrintInfo();

    auto m = qlm::Match(strategy0, strategy0, 15);
    
    m.Print();
}