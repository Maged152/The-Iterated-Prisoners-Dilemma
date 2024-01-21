#include "competition.hpp"
#include "helper.hpp"
#include <cmath>
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
    MatchResult Match(Strategy& player_0, Strategy& player_1, unsigned int num_rounds,  const PayOff& pay_off)
    {
        MatchResult match_result {player_0.Name(), player_1.Name(), pay_off, num_rounds};

        // clear history
        player_0.ClearHistory();
        player_1.ClearHistory();

        // first move
        auto player_0_action = player_0.FirstAction();
        auto player_1_action = player_1.FirstAction();

        // score
        auto [player_0_score, player_1_score] = GetScore(player_0_action, player_1_action);

        // rest of the rounds
        for (int i = 1; i < num_rounds; i++)
        {
            // take action
            auto player_0_new_action = player_0.Action(player_1_action);
            auto player_1_new_action = player_1.Action(player_0_action);

            // update score
            auto [score_0, score_1] = GetScore(player_0_new_action, player_1_new_action);
            player_0_score += score_0;
            player_1_score += score_1;

            // update action
            player_1_action = player_1_new_action;
            player_0_action = player_0_new_action;
        }

        // copy history
        match_result.player_0_history = player_0.GetMyHistory();
        match_result.player_1_history = player_1.GetMyHistory();

        // store scores
        match_result.player_0_score = player_0_score;
        match_result.player_1_score = player_1_score;

        return match_result;
    }

    // print 
    void MatchResult::Print() const
    {
        // names of the players
        std::cout << player_0 << "  VS  " << player_1 << std::endl;

        // results
        std::cout << "Match result of " << num_rounds << " rounds :" <<std::endl;

        if (player_0_score == player_1_score)
        {
            // drew
            std::cout << "Draw" << " ,Score : " << player_0_score << std::endl;
        }
        else if (player_0_score > player_1_score)
        {
            // player 0 won
            std::cout << player_0 << " ,Wins" << " ,Score : " << player_0_score << std::endl;
            std::cout << player_1 << " ,Losses" << " ,Score : " << player_1_score << std::endl;
        }
        else
        {
            // player 1 won
            std::cout << player_1 << " ,Wins" << " ,Score : " << player_1_score << std::endl;
            std::cout << player_0 << " ,Loses" << " ,Score : " << player_0_score << std::endl;
        }

        // print details
        constexpr int col_0_size = 6; // 1(space) + 5(Round)
        const int col_1_size = std::max(9 ,(int)player_0.size()) + 1; // Cooperate, strategy_name + 1
        const int col_2_size = std::max(9 ,(int)player_1.size()) + 1; // Cooperate, strategy_name + 1

        const std::string header_0_spaces (col_1_size - player_0.size(), ' ');
        const std::string header_1_spaces (col_2_size - player_1.size(), ' ');

        const std::string col_1_co_spaces (col_1_size - 9, ' ');
        const std::string col_1_de_spaces (col_1_size - 6, ' ');

        const std::string col_2_co_spaces (col_2_size - 9, ' ');
        const std::string col_2_de_spaces (col_2_size - 6, ' ');
        
        
        // headers
        std::cout << "| Round | " << player_0 << header_0_spaces << "| " << player_1 << header_1_spaces << "|\n";
        std::cout << "| ----- | " << std::string (col_1_size - 1, '-') << " | " << std::string (col_2_size - 1, '-') << " |\n";
        
        // data
        for (int r = 0; r < num_rounds; r++)
        {
            const std::string round_spaces (col_0_size - std::to_string(r).size(), ' ');
            const std::string col_1_spaces = player_0_history[r] == Choice::COOPERATE ? col_1_co_spaces : col_1_de_spaces;
            const std::string col_2_spaces = player_1_history[r] == Choice::COOPERATE ? col_2_co_spaces : col_2_de_spaces;

            std::cout <<"| " << r << round_spaces 
                      << "| " << player_0_history[r] << col_1_spaces
                      << "| " << player_1_history[r] << col_2_spaces
                      << "|\n";
        }

        std::cout << "| ----- | " << std::string (col_1_size - 1, '-') << " | " << std::string (col_2_size - 1, '-') << " |\n";
    }

    // save as csv
}