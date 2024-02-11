#include "strategies.hpp"

namespace qlm
{
    // constructor
    FirstByGrofman::FirstByGrofman(const PayOff& pay_off) : Strategy(pay_off)
    {
        name = "FirstByGrofman";
        info = "If the players did different things on the previous move, this rule > cooperates with probability 2/7. Otherwise this rule always cooperates.";
        probabilistic_action = true;
        properties.niceness = 1;
        flags.reset();
    }

    // First action function
    Choice FirstByGrofman::FirstAction()
    {
        my_history.push_back(Choice::COOPERATE);
        return Choice::COOPERATE;
    }

    // Action function
    Choice FirstByGrofman::Action(const Choice opponent_play)
    {
        constexpr double probability = 2.0 / 7.0;
        Choice action = Choice::COOPERATE;

        // check players previous moves 
        if (opponent_play != my_history.back())
        {
            // cooperates with probability 2/7
            action = random_gen.random_choice(probability);
        }

        // update history
        UpdateHistory(action, opponent_play);  
              
        return action;
    }

    // rest function
    void FirstByGrofman::Reset()
    {
        Strategy::BaseReset();
        flags.reset();
        random_gen.Reset();
    }

}