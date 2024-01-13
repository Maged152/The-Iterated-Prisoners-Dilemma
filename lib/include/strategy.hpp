#ifndef STRATEGY
#define STRATEGY

#include "types.hpp"
#include <vector>
#include <string>

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

        public:
        virtual Choice Action(const Choice opponent_play) = 0;
        virtual Choice FirstAction() = 0;

        public:
        void ClearHistory();
        void UpdateHistory(const Choice my_play, const Choice opponent_play);

        void PrintInfo() const;

        std::vector<Choice> GetMyHistory() const;

        protected:
        std::size_t GetRoundNumber() const;
    };
}

#endif