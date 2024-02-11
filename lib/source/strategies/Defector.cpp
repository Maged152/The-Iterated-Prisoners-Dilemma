#include "strategies.hpp"

namespace qlm
{
    // constructor
    Defector::Defector(const PayOff& pay_off) : Strategy(pay_off)
    {
        name = "Defector";
        info = "A player always defects.";
        probabilistic_action = false;
        properties.niceness = 0;
    }

    // First action function
    Choice Defector::FirstAction()
    {
        my_history.push_back(Choice::DEFECT);
        return Choice::DEFECT;
    }

    // Action function
    Choice Defector::Action(const Choice opponent_play)
    {
        // update history
        UpdateHistory(Choice::DEFECT, opponent_play);       
        return Choice::DEFECT;
    }

    // rest function
    void Defector::Reset()
    {
        Strategy::Reset();
        flags.reset();
    }

}