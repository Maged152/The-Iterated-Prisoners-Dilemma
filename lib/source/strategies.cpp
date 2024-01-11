#include "strategies.hpp"
#include <iostream>

namespace qlm
{
    void Strategy::ClearHistory()
    {
        my_history.clear();
        opponent_history.clear();
    }
    ///////////////////////////////////////
    void Strategy::UpdateHistory(const Choice my_play, const Choice opponent_play)
    {
        my_history.push_back(my_play);
        opponent_history.push_back(opponent_play);
    }
    ///////////////////////////////////////
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
    ///////////////////////////////////////
    std::vector<Choice> Strategy::GetMyHistory() const
    {
        return my_history;
    }
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    
}