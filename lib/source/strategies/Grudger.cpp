#include "strategies.hpp"

namespace qlm
{
    // constructor
    Grudger::Grudger(const PayOff& pay_off) : Strategy(pay_off)
    {
        name = "Grudger";
        info = "A player starts by cooperating until the other player defects, and then defects until the end of the game.";
        probabilistic_action = false;
        properties.niceness = 1; // the others are not obvious or not important as this
        flags.reset();
    }

    // First action function
    Choice Grudger::FirstAction()
    {
        my_history.push_back(Choice::COOPERATE);
        return Choice::COOPERATE;
    }

    // Action function
    Choice Grudger::Action(const Choice opponent_play)
    {
        Choice action = Choice::COOPERATE;

        if (opponent_play == Choice::DEFECT)
        {
            flags.set();
        }

        if (flags[0])
        {
            action = Choice::DEFECT;
        }

        // update history
        UpdateHistory(action, opponent_play);  
              
        return action;
    }

    // rest function
    void Grudger::Reset()
    {
        Strategy::Reset();
        flags.reset();
    }

}