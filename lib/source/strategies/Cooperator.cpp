#include "strategies.hpp"

namespace qlm
{
    // constructor
    Cooperator::Cooperator(const PayOff& pay_off) : Strategy(pay_off)
    {
        name = "Cooperator";
        info = "A player always cooperates.";
        probabilistic_action = false;
        properties.niceness = 1;
    }

    // First action function
    Choice Cooperator::FirstAction()
    {
        my_history.push_back(Choice::COOPERATE);
        return Choice::COOPERATE;
    }

    // Action function
    Choice Cooperator::Action(const Choice opponent_play)
    {
        // update history
        UpdateHistory(Choice::COOPERATE, opponent_play);       
        return Choice::COOPERATE;
    }

    // rest function
    void Cooperator::Reset()
    {
        Strategy::Reset();
        flags.reset();
    }

}