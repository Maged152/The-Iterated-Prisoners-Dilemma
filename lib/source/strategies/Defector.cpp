#include "strategies.hpp"

namespace qlm
{
    // constructor
    Defector::Defector()
    {
        name = "Defector";
        info = "A player always defects.";
        probabilistic_action = false;
        properties.niceness = 0; // the others are not obvious or important as this
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
        flags.reset();
        my_history.clear();
        opponent_history.clear();
    }

}