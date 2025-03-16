#ifndef STATEPROCESSOR
#define STATEPROCESSOR

#include "gameState.h"
#include "../view/observer.h"
#include <memory>
#include <cinttypes>
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
        std::set<uint8_t> birth_condition;
        std::set<uint8_t> survival_condition;
    };

    class StateProcessor: public Observable {
    private:
        GameState* state_;
        EvolutionConditions conditions_;

    public:
        void setState(GameState* state);
        void setEvolutionConditions(EvolutionConditions conditions);
        GameState getState() const;
        void process();

    private:
        int getNeighborCount(Cell cell);
    };
}

#endif //STATEPROCESSOR
