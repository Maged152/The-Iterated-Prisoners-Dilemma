#include "strategies.hpp"

namespace qlm
{
    // constructor
    FirstByTullock::FirstByTullock(const PayOff& pay_off) : Strategy(pay_off)
    {
        name = "First by Tullock";
        info = "This rule cooperates for the first 11 rounds then randomly \
                cooperates 10% less often than the opponent has in the previous 10 rounds.";
        probabilistic_action = true;
        properties.niceness = 0;
    }

    // First action function
    Choice FirstByTullock::FirstAction()
    {
        my_history.push_back(Choice::COOPERATE);
        return Choice::COOPERATE;
    }

    // Action function
    Choice FirstByTullock::Action(const Choice opponent_play)
    {
        constexpr int rounds_to_cooperate = 11;
        constexpr int rounds_to_check = 10;
        constexpr double coop_percentage_dec = 0.1;
        
        const int round = my_history.size() ;
        Choice action;

        if (round < rounds_to_cooperate)
        {
            action = Choice::COOPERATE;
        }
        else
        {
            // count the number of cooperation in the last 10 rounds
            int num_coop {0};
            for (int i = opponent_history.size() - 1; i > opponent_history.size() - rounds_to_check; i--)
            {
                if (opponent_history[i] == Choice::COOPERATE)
                {
                    num_coop++;
                }
            }
            
            if (opponent_play == Choice::COOPERATE)
            {
                num_coop++;
            }

            const double opponent_coop_percentage = num_coop / static_cast<double>(rounds_to_check);
            const double prop = std::max(0.0, opponent_coop_percentage - coop_percentage_dec);
            action = random_gen.random_choice(prop);
        }

        // update history
        UpdateHistory(action, opponent_play);  
              
        return action;
    }

    // rest function
    void FirstByTullock::Reset()
    {
        Strategy::Reset();
        flags.reset();
    }

}