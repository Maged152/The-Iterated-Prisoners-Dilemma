#include "strategies.hpp"

namespace qlm
{
    // constructor
    FirstByGrofman::FirstByGrofman()
    {
        name = "FirstByGrofman";
        info = "If the players did different things on the previous move, this rule > cooperates with probability 2/7. Otherwise this rule always cooperates.";
        properties.niceness = 1; // the others are not obvious or important as this
        flags.reset();
    }

    // First action function
    Choice FirstByGrofman::FirstAction()
    {
        my_history.push_back(Choice::COOPERATE);
        return Choice::COOPERATE;
    }

    // Action function
    Choice FirstByGrofman::Action(const Choice opponent_play)
    {
        constexpr float probability = 2.0f / 7.0f;
        Choice action = Choice::COOPERATE;

        // check players previous moves 
        if (opponent_play != my_history.back())
        {
            // cooperates with probability 2/7
            action = random_gen.random_choice(probability);
        }

        // update history
        UpdateHistory(action, opponent_play);  
              
        return action;
    }

    // rest function
    void FirstByGrofman::Reset()
    {
        flags.reset();
        my_history.clear();
        opponent_history.clear();
        random_gen.Reset();
    }

}