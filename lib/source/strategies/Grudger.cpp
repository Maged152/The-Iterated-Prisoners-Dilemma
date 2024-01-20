#include "strategies.hpp"

namespace qlm
{
    // constructor
    Grudger::Grudger()
    {
        name = "Grudger";
        info = "A player starts by cooperating until the other player defects, and then defects until the end of the game.";
        properties.niceness = 1; // the others are not obvious or important as this
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

        if (opponent_play == Choice::DEFECT || my_history.back() == Choice::DEFECT)
        {
            action = Choice::DEFECT;
        }

        // update history
        UpdateHistory(action, opponent_play);  
              
        return action;
    }

}