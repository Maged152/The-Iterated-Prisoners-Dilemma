#include "strategies.hpp"

namespace qlm
{
    // constructor
    Cooperator::Cooperator()
    {
        name = "Cooperator";
        info = "A player always cooperates.";
        properties.niceness = 1; // the others are not obvious or important as this
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

}