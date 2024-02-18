#include "strategies.hpp"
#include <cmath>

namespace qlm
{
    // constructor
    FirstByDowning::FirstByDowning(const PayOff& pay_off) : Strategy(pay_off), opp_coop_response_to_c(0), opp_coop_response_to_d(0)
    {
        name = "First by Downing";
        info = "This rule selects its choice to maximize its own long term expected payoff on \
                the assumption that the other rule cooperates with a fixed probability which \
                depends only on whether the other player cooperated or defected on the previous \
                move. These two probabilities estimates are continuously updated as the game \
                progresses. Initially, they are both assumed to be .5, which amounts to the \
                pessimistic assumption that the other player is not responsive. This rule is \
                based on an outcome maximization interpretation of human performances proposed  by Downing (1975).";
        probabilistic_action = false;
        properties.niceness = 1; 
    }

    // First action function
    Choice FirstByDowning::FirstAction()
    {
        my_history.push_back(Choice::DEFECT);
        num_def++;
        return Choice::DEFECT;
    }

    // Action function
    Choice FirstByDowning::Action(const Choice opponent_play)
    {
        const int round = Round();
        Choice action;

        if (round == 2)
        {
            action = Choice::DEFECT;

            if (opponent_play == Choice::COOPERATE)
            {
                opp_coop_response_to_c++;
            }
        }
        else
        {
            if (opponent_play == Choice::COOPERATE && my_history[my_history.size() - 2] == Choice::COOPERATE)
            {
                opp_coop_response_to_c++;
            }
            else if (opponent_play == Choice::COOPERATE && my_history[my_history.size() - 2] == Choice::DEFECT)
            {
                opp_coop_response_to_d++;
            }

            double alpha = opp_coop_response_to_c / static_cast<double>(num_coop + 1);
            double beta = opp_coop_response_to_d / static_cast<double>(std::max(num_def, 2));

            double expected_value_of_cooperating = alpha * pay_off.cooperate_cooperate + (1 - alpha) * pay_off.cooperate_defect;
            double expected_value_of_defecting = beta * pay_off.defect_cooperate + (1 - beta) * pay_off.defect_defect;

            if (expected_value_of_cooperating > expected_value_of_defecting)
            {
                action = Choice::COOPERATE;
            }
            else if (expected_value_of_cooperating < expected_value_of_defecting)
            {
                action = Choice::DEFECT;
            }
            else
            {
                action = my_history.back() == Choice::COOPERATE ? Choice::DEFECT : Choice::COOPERATE;
            }
        }

        // update history
        UpdateHistory(action, opponent_play);  
        
        return action;
    }

    // rest function
    void FirstByDowning::Reset()
    {
        opp_coop_response_to_c = 0;
        opp_coop_response_to_d = 0;
        Strategy::BaseReset();
        flags.reset();
    }

}