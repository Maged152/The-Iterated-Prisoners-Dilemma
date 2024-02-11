#include "strategies.hpp"

namespace qlm
{
    // constructor
    FirstByDavis::FirstByDavis(const PayOff& pay_off) : Strategy(pay_off)
    {
        name = "First by Davis: 10";
        info = "A player starts by cooperating for 10 rounds then plays Grudger, defecting if at any point the opponent has defected";
        properties.niceness = 1;

        flags.reset();
    }

    // First action function
    Choice FirstByDavis::FirstAction()
    {
        my_history.push_back(Choice::COOPERATE);
        probabilistic_action = false;
        return Choice::COOPERATE;
    }

    // Action function
    Choice FirstByDavis::Action(const Choice opponent_play)
    {
        constexpr int rounds_to_cooperate = 10;
        const int round_num = my_history.size() + 1;

        if (opponent_play == Choice::DEFECT)
        {
            flags.set();
        }

        Choice action = Choice::COOPERATE;

        if (round_num > rounds_to_cooperate && flags[0])
        {
            action = Choice::DEFECT;
        }

        // update history
        UpdateHistory(action, opponent_play);  
              
        return action;
    }

    // rest function
    void FirstByDavis::Reset()
    {
        Strategy::BaseReset();
        flags.reset();
    }

}