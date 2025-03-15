#include "../include/gameState.h"

namespace game_state {
    GameState::GameState(const AliveCells& inition_state, const std::string& universe_name, FieldSize f_sz) 
        : cells_state_(inition_state)
        , universe_name_(universe_name)
        , f_sz_(f_sz) {}

    void GameState::setNextState(const AliveCells& next_state) {
        cells_state_ = next_state;
    }

    AliveCells GameState::getCellsState() const {
        return cells_state_;
    }

    std::string GameState::getUniverseName() const {
        return universe_name_;
    }

    FieldSize GameState::getFieldSize() const {
        return f_sz_;
    }
}