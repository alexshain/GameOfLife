#ifndef STATEPROCESSOR
#define STATEPROCESSOR

#include "gameState.h"
#include <memory>
#include <cinttypes>
#include <set>

using game_state::GameState;
using game_state::Cell;

namespace st_prcsr {
    struct EvolutionConditions {
        std::set<uint8_t> birth_condition;
        std::set<uint8_t> survival_condition;
    };

    class StateProcessor {
    private:
        std::shared_ptr<GameState> state_;
        EvolutionConditions conditions_;

    public:
        StateProcessor(const std::shared_ptr<GameState>& state, EvolutionConditions conditions);
        GameState nextState();

    private:
        int getNeighborCount(Cell cell);
    };
}

#endif //STATEPROCESSOR
