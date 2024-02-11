#include "strategies.hpp"
#include <cmath>

namespace qlm
{
    // constructor
    FirstByFeld::FirstByFeld(const PayOff& pay_off) : Strategy(pay_off)
    {
        name = "First by Feld: 1.0, 0.5, 200";
        info = "This rule starts with tit for tat and gradually lowers its probability of \
                cooperation following the other's cooperation to .5 by the two hundredth \
                 move. It always defects after a defection by the other.";
        probabilistic_action = true;
        properties.niceness = 1;
    }

    // First action function
    Choice FirstByFeld::FirstAction()
    {
        my_history.push_back(Choice::COOPERATE);
        return Choice::COOPERATE;
    }

    // Action function
    Choice FirstByFeld::Action(const Choice opponent_play)
    {
        constexpr double coop_prob = 1.0;
        constexpr double min_prop = 0.5;
        constexpr int num_rounds = 200;

        constexpr double prop_step = (coop_prob - min_prop) / num_rounds;
        

        Choice action;

        if (opponent_play == Choice::DEFECT)
        {
            action = Choice::DEFECT;
        }
        else
        {
            const int round =  my_history.size();
            const double prop = std::max(min_prop, coop_prob - round * prop_step);
            action = random_gen.random_choice(prop);
        }

        // update history
        UpdateHistory(action, opponent_play);  
              
        return action;
    }

    // rest function
    void FirstByFeld::Reset()
    {
        Strategy::Reset();
        flags.reset();
    }

}