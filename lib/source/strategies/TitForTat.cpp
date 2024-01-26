#include "strategies.hpp"

namespace qlm
{
    // constructor
    TitForTat::TitForTat()
    {
        name = "TitForTat";
        info = "A player starts by cooperating and then mimics the previous action of the opponent.";
        probabilistic_action = false;
        properties.niceness = 1; // the others are not obvious or important as this
    }

    // First action function
    Choice TitForTat::FirstAction()
    {
        my_history.push_back(Choice::COOPERATE);
        return Choice::COOPERATE;
    }

    // Action function
    Choice TitForTat::Action(const Choice opponent_play)
    {
        // update history
        UpdateHistory(opponent_play, opponent_play);  
        // mimics the previous action of the opponent      
        return opponent_play;
    }

    // rest function
    void TitForTat::Reset()
    {
        flags.reset();
        my_history.clear();
        opponent_history.clear();
    }

}