#include "strategies.hpp"

namespace qlm
{
    // constructor
    Cooperate::Cooperate()
    {
        name = "Cooperate";
        info = "A player always cooperates.";
        properties.niceness = 1; // the others are not obvious or important as this
    }

    // First action function
    Choice Cooperate::FirstAction()
    {
        my_history.push_back(Choice::COOPERATE);
        return Choice::COOPERATE;
    }

    // Action function
    Choice Cooperate::Action(const Choice opponent_play)
    {
        // update history
        UpdateHistory(Choice::COOPERATE, opponent_play);       
        return Choice::COOPERATE;
    }

}