#include "strategies.hpp"
#include <cmath>

namespace qlm
{
    // constructor
    Random::Random(const PayOff& pay_off) : Strategy(pay_off)
    {
        name = "Random: 0.5";
        info = "This rule cooperates and defects with equal probability";
        probabilistic_action = true;
        properties.niceness = 0;
    }

    // First action function
    Choice Random::FirstAction()
    {
        const auto action = random_gen.random_choice(coop_prop);
        my_history.push_back(action);
        return action;
    }

    // Action function
    Choice Random::Action(const Choice opponent_play)
    {
        const auto action = random_gen.random_choice(coop_prop);

        // update history
        UpdateHistory(action, opponent_play);  
              
        return action;
    }

    // rest function
    void Random::Reset()
    {
        Strategy::BaseReset();
        flags.reset();
    }
}