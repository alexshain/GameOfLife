#ifndef STATEPROCESSOR
#define STATEPROCESSOR

#include "gameState.h"
#include "observable.h"
#include <set>

using game_state::GameState;
using game_state::Cell;


namespace st_prcsr {
    struct EvolutionConditions {
        std::set<int> birth_condition;
        std::set<int> survival_condition;
    };

    class StateProcessor: public Observable {
    private:
        GameState state;
        EvolutionConditions conditions;
        size_t curr_iter;

    public:
        StateProcessor();
        void setState(GameState state);
        void setEvolutionConditions(EvolutionConditions conditions);
        [[nodiscard]] const GameState& getState() const;
        [[nodiscard]] const EvolutionConditions& getConditions() const;
        size_t process();

    private:
        void setDefaultState();
        int getNeighborCount(Cell cell);
    };
}

#endif //STATEPROCESSOR
