#ifndef MATCHES
#define MATCHES

#include "strategies.hpp"

namespace qlm
{
    class MatchResult
    {
        // TODO
    };

    class TournamentResult
    {
        // TODO
    };

    MatchResult Match(Strategy& player_0, Strategy& player_1);

    TournamentResult Tournament(std::vector<Strategy>& players);
}

#endif