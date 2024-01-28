#include "strategies.hpp"
#include <cmath>

namespace qlm
{
    // constructor
    FirstByFeld::FirstByFeld()
    {
        name = "FirstByFeld";
        info = "This rule starts with tit for tat and gradually lowers its probability of \
                cooperation following the other's cooperation to .5 by the two hundredth \
                 move. It always defects after a defection by the other.";
        probabilistic_action = true;
        properties.niceness = 1; // the others are not obvious or not important as this
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
        flags.reset();
        my_history.clear();
        opponent_history.clear();
    }

}