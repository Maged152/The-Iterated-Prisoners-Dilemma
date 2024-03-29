#include "strategy.hpp"
#include <iostream>

namespace qlm
{
    Strategy::Strategy (const PayOff& pay_off) : pay_off(pay_off), num_coop(0), num_def(0)
    {}
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void Strategy::ClearHistory()
    {
        my_history.clear();
        opponent_history.clear();
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void Strategy::UpdateHistory(const Choice my_play, const Choice opponent_play)
    {
        my_history.push_back(my_play);
        opponent_history.push_back(opponent_play);

        if (my_play == Choice::COOPERATE)
        {
            num_coop++;
        }
        else
        {
            num_def++;
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void Strategy::PrintInfo() const
    {
        std::cout << "Strategy name : " << name << "\n"
                  << "Strategy info : " << info << "\n"
                  << "properties :\n"
                  << "\t niceness : " << properties.niceness << "\n"
                  << "\t clarity : " << properties.clarity << "\n"
                  << "\t forgiveness : " << properties.forgiveness << "\n"
                  << "\t provocability : " << properties.provocability << "\n";
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::vector<Choice> Strategy::GetMyHistory() const
    {
        return my_history;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::size_t Strategy::Round() const
    {
        // the round is just the size of my history + 1 (first round is number 1)
        return my_history.size() + 1;

    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::string Strategy::Name() const
    {
        return name;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void Strategy::SetSeed(int seed)
    {
        this->random_gen.SetSeed(seed);
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool Strategy::ProbabilisticAction() const 
    {
        return this->probabilistic_action;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void Strategy::BaseReset()
    {
        num_coop = 0;
        num_def = 0;
        my_history.clear();
        opponent_history.clear();
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}