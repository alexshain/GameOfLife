#include "../../include/model/gameState.h"

namespace game_state {
    GameState::GameState(const AliveCells& alive_cells, const std::string& universe_name, FieldSize f_sz) 
        : alive_cells_(alive_cells)
        , universe_name_(universe_name)
        , f_sz_(f_sz) {}

    void GameState::setAliveCells(const AliveCells& new_alive_cells) {
        alive_cells_ = new_alive_cells;
    }

    AliveCells GameState::getAliveCells() const {
        return alive_cells_;
    }

    std::string GameState::getUniverseName() const {
        return universe_name_;
    }

    FieldSize GameState::getFieldSize() const {
        return f_sz_;
    }
}