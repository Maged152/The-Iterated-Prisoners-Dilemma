#include "strategies.hpp"

namespace qlm
{
    // constructor
    TitForTat::AlwaysCooperate()
    {
        name = "AlwaysCooperate";
        info = "A player always cooperates.";
        properties.niceness = 1; // the others are not obvious or important as this
    }

    // First action function
    Choice AlwaysCooperate::FirstAction()
    {
        my_history.push_back(Choice::COOPERATE);
        return Choice::COOPERATE;
    }

    // Action function
    Choice AlwaysCooperate::Action(const Choice opponent_play)
    {
        // update history
        UpdateHistory(Choice::COOPERAT, opponent_play);       
        return Choice::COOPERAT;
    }

}