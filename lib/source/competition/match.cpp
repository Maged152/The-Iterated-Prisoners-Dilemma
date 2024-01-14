#include "competition.hpp"

namespace qlm
{
    // score function
    std::pair<int, int> GetScore(const Choice player_0_choice, const Choice player_1_choice, const PayOff& pay_off )
    {
        int player_0_score, player_1_score;

        if (player_0_choice == Choice::COOPERATE && player_1_choice == Choice::COOPERATE)
        {
            player_0_score = player_1_score = pay_off.cooperate_cooperate;
        }
        else if (player_0_choice == Choice::COOPERATE && player_1_choice == Choice::DEFECT)
        {
            player_0_score = pay_off.cooperate_defect;
            player_1_score = pay_off.defect_cooperate;
        }
        else if (player_0_choice == Choice::DEFECT && player_1_choice == Choice::COOPERATE)
        {
            player_0_score = pay_off.defect_cooperate;
            player_1_score = pay_off.cooperate_defect;
        }
        else
        {
            player_0_score = player_1_score = pay_off.defect_defect;
        } 

        return std::make_pair(player_0_score, player_1_score);
    }

    // getters
    PayOff MatchResult::GetPayOff() const
    {
        return pay_off;
    }

    std::string MatchResult::GetPlayer0() const
    {
        return player_0;
    }

    std::vector<Choice> MatchResult::GetPlayer0History() const
    {
        return player_0_history; 
    }

    int MatchResult::GetPlayer0Score() const
    {
        return player_0_score;
    }

    std::string MatchResult::GetPlayer1() const
    {
        return player_1;
    }

    std::vector<Choice> MatchResult::GetPlayer1History() const
    {
        return player_1_history;
    }

    int MatchResult::GetPlayer1Score() const
    {
        return player_1_score;
    }

    // winner function
    std::pair<std::string, int> MatchResult::Winner() const
    {
        if (player_0_score == player_1_score)
        {
            // drew
            return std::make_pair("DRAW", player_0_score);
        }
        else if (player_0_score > player_1_score)
        {
            // player 0 won
            return std::make_pair(player_0, player_0_score);
        }
        else
        {
            // player 1 won
            return std::make_pair(player_1, player_1_score);
        }
    }

    // match function
    MatchResult Match(Strategy& player_0, Strategy& player_1, unsigned int num_rounds = 200,  const PayOff& pay_off)
    {
        MatchResult match_result {player_0.Name(), player_1.Name(), pay_off, num_rounds};


        return match_result;
    }
}