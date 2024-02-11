#ifndef STRATEGY
#define STRATEGY

#include "types.hpp"
#include "random_generator.hpp"
#include <vector>
#include <string>
#include <bitset>

namespace qlm
{
    // base strategy all other Strategies should inherent from it and write its constructor and Action function
    class Strategy
    {
        protected:
        std::vector<Choice> my_history;
        std::vector<Choice> opponent_history;

        std::string name;
        std::string info;
        Properties properties;
        bool probabilistic_action;

        RandomGenerator random_gen;

        PayOff pay_off;
        int num_coop; 
        int num_def;

        public:
        virtual Choice Action(const Choice opponent_play) = 0;
        virtual Choice FirstAction() = 0;

        public:
        Strategy (const PayOff& pay_off);
        void ClearHistory();
        void UpdateHistory(const Choice my_play, const Choice opponent_play);
        std::string Name() const;
        void PrintInfo() const;

        std::vector<Choice> GetMyHistory() const;
        void SetSeed(int seed);
        bool ProbabilisticAction() const;
        void Reset();

        protected:
        std::size_t Round() const;
    };
}

#endif