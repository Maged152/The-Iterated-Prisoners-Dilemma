#ifndef STRATEGIES
#define STRATEGIES

#include "types.hpp"
#include <vector>
#include <string>

namespace qlm
{
    class Strategy
    {
        private:
        std::vector<Choice> my_history;
        std::vector<Choice> opponent_history;

        std::string name;
        std::string info;
        Properties properties;

        public:
        virtual Choice Play(const Choice opponent_play) = 0;

        public:
        Strategy(const std::string& name, const std::string& info, const Properties& properties) : name(name), info(info), properties(properties)
        {}

        void ClearHistory();
        void UpdateHistory(const Choice my_play, const Choice opponent_play);

        void PrintInfo() const;

        std::vector<Choice> GetMyHistory() const;
    };
    
}

#endif