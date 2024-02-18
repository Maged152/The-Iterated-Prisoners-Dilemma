#include "strategies.hpp"

namespace qlm
{
    // constructor
    FirstByShubik::FirstByShubik(const PayOff& pay_off) : Strategy(pay_off)
    {
        name = "First by Shubik";
        info = "This rule cooperates until the other defects, and then defects once. If the other defects again after the \
                rule’s cooperation is resumed, the rule defects twice. In general, the length of \
                retaliation is increased by one for each departure from mutual cooperation. \
                This rule is described with its strategic implications in Shubik (1970).  Further \
                treatment of its is given in Taylor (1976).";
        probabilistic_action = false;
        properties.niceness = 1;
        flags.reset();
        retaliation_counter = 0;
        retaliation_remaining = 0;
    }

    // First action function
    Choice FirstByShubik::FirstAction()
    {
        my_history.push_back(Choice::COOPERATE);
        return Choice::COOPERATE;
    }

    // Action function
    Choice FirstByShubik::Action(const Choice opponent_play)
    {
        auto DecreaseRetaliation = [&]()
        {
            retaliation_remaining--;
            if (retaliation_remaining == 0)
            {
                flags.reset();
            }  
        };

        Choice action = Choice::COOPERATE;

        // Are we still retaliating?
        if (flags[0])
        {
            action = Choice::DEFECT;
            DecreaseRetaliation();

            // update history
            UpdateHistory(action, opponent_play);  

            return action;
        }

        if (opponent_play == Choice::DEFECT && my_history.back() == Choice::COOPERATE)
        {
            flags.set();
            retaliation_counter++;
            retaliation_remaining = retaliation_counter;
            DecreaseRetaliation();
            action = Choice::DEFECT;
        }

        // update history
        UpdateHistory(action, opponent_play);  
              
        return action;
    }

    // rest function
    void FirstByShubik::Reset()
    {
        Strategy::BaseReset();
        flags.reset();
        retaliation_counter = 0;
        retaliation_remaining = 0;
    }

}