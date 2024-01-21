#ifndef STRATEGIES
#define STRATEGIES

#include "strategy.hpp"

// Macro to declare a new strategy
#define DECLARE_STRATEGY(Strategy_name, n)                     \
    class Strategy_name : public Strategy {                    \
    private:                                                   \
        std::bitset<n> flags;                                  \
    public:                                                    \
        Strategy_name();                                       \
        Choice FirstAction() override;                         \
        Choice Action(const Choice opponent_play) override;    \
        void Reset() override;                                 \
    }

namespace qlm
{
    DECLARE_STRATEGY(TitForTat, 0);
    DECLARE_STRATEGY(Cooperator, 0);
    DECLARE_STRATEGY(Grudger, 1);
    DECLARE_STRATEGY(Defector, 0);
    DECLARE_STRATEGY(FirstByDavis, 1);
}

#endif