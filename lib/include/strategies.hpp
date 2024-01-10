#ifndef STRATEGIES
#define STRATEGIES

#include "types"
#include <vector>

namespace qlm
{
    class Strategy
    {
        private:
        std::vector<Choice> my_history;
        std::vector<Choice> opponent_history;

        public:
        Choice Play(const Choice opponent_play) = 0;

        void ClearHistory()
        {
            my_history.clear();
            opponent_history.clear();
        }
    };
}

#endif