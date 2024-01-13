#ifndef COMETITION 
#define COMETITION

#include "strategy.hpp"
#include <utility>
namespace qlm
{
    class MatchResult
    {
        private:
        // match info
        PayOff pay_off;
        unsigned int num_rounds;
        // player 0 info
        std::string player_0;
        std::vector<Choice> player_0_history;
        int player_0_score;
        // player 1 info
        std::string player_1;
        std::vector<Choice> player_1_history;
        int player_1_score;

        public:
        MatchResult(const std::string& player_0, const std::string& player_1, const PayOff& pay_off = {},  unsigned int num_rounds = 200)
        : player_0(player_0), player_1(player_1), pay_off(pay_off), num_rounds(num_rounds)
        {}

        public:
        // getters
        PayOff GetPayOff() const;
        unsigned int GetNumRounds() const;

        std::string GetPlayer0() const;
        std::vector<Choice> GetPlayer0History() const;
        int GetPlayer0Score() const;

        std::string GetPlayer1() const;
        std::vector<Choice> GetPlayer1History() const;
        int GetPlayer1Score() const;

        public:
        std::pair<std::string, int> Winner() const;

        std::pair<int, int> Score(const Choice& player_0_choice, const Choice& player_1_choice) const;

        void Print() const;

        friend MatchResult Match(Strategy& player_0, Strategy& player_1, unsigned int num_rounds,  const PayOff& pay_off); 
    };

    class TournamentResult
    {
        // TODO
    };

    MatchResult Match(Strategy& player_0, Strategy& player_1, unsigned int num_rounds = 200,  const PayOff& pay_off = {}); 

    TournamentResult Tournament(std::vector<Strategy>& players, unsigned int num_rounds = 200, const PayOff& pay_off = {});
}

#endif