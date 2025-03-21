#ifndef STATEPROCESSOR
#define STATEPROCESSOR

#include "gameState.h"
#include "view/observer.h"
#include <set>

using game_state::GameState;
using game_state::Cell;

class Observable {
private:
    std::vector<Observer*> observers_;

public:
    void addObserver(Observer* observer) {
        observers_.push_back(observer);
    }

    void notifyUpdate() {
        for(const auto& observer: observers_) {
            observer->update();
        }
    }
};

namespace st_prcsr {
    struct EvolutionConditions {
        std::set<int> birth_condition;
        std::set<int> survival_condition;
    };

    class StateProcessor: public Observable {
    private:
        GameState state;
        EvolutionConditions conditions;

    public:
        StateProcessor();
        void setState(GameState state);
        void setEvolutionConditions(EvolutionConditions conditions);
        [[nodiscard]] const GameState& getState() const;
        [[nodiscard]] const EvolutionConditions& getConditions() const;
        void process();

    private:
        void setDefaultState();
        int getNeighborCount(Cell cell);
    };
}

#endif //STATEPROCESSOR
