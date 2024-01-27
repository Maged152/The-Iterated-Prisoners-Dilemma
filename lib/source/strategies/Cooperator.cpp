#include "strategies.hpp"

namespace qlm
{
    // constructor
    Cooperator::Cooperator()
    {
        name = "Cooperator";
        info = "A player always cooperates.";
        probabilistic_action = false;
        properties.niceness = 1; // the others are not obvious or not important as this
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
        flags.reset();
        my_history.clear();
        opponent_history.clear();
    }

}