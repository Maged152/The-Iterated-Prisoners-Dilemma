#ifndef STRATEGIES
#define STRATEGIES

#include "strategy.hpp"

// Macro to declare a new strategy
#define DECLARE_STRATEGY(Strategy_name, n, ...)                       \
    class Strategy_name : public Strategy {                           \
    private:                                                          \
        std::bitset<n> flags;                                         \
        __VA_ARGS__;                                                  \
    public:                                                           \
        Strategy_name(const PayOff& pay_off = {});                    \
        Choice FirstAction() override;                                \
        Choice Action(const Choice opponent_play) override;           \
        void Reset();                                                 \
    }


namespace qlm
{
    DECLARE_STRATEGY(TitForTat, 0);
    DECLARE_STRATEGY(Cooperator, 0);
    DECLARE_STRATEGY(Grudger, 1);
    DECLARE_STRATEGY(Defector, 0);
    DECLARE_STRATEGY(FirstByDavis, 1);
    DECLARE_STRATEGY(FirstByGrofman, 0);
    DECLARE_STRATEGY(FirstByJoss, 0);
    DECLARE_STRATEGY(FirstByFeld, 0);
    DECLARE_STRATEGY(FirstByTullock, 0);
    DECLARE_STRATEGY(FirstByShubik, 1, int retaliation_counter; int retaliation_remaining);
    DECLARE_STRATEGY(FirstByNydegger, 0, int arr[19]);
    DECLARE_STRATEGY(FirstByDowning, 0, int opp_coop_response_to_c; int opp_coop_response_to_d);
}

#endif