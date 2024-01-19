#ifndef STRATEGIES
#define STRATEGIES

#include "strategy.hpp"

// Macro to declare a new strategy
#define DECLARE_STRATEGY(Strategy_name)                        \
    class Strategy_name : public Strategy {                    \
    public:                                                    \
        Strategy_name();                                       \
        Choice FirstAction() override;                         \
        Choice Action(const Choice opponent_play) override;    \
    }

namespace qlm
{
    DECLARE_STRATEGY(TitForTat);
    DECLARE_STRATEGY(Cooperate);
}

#endif