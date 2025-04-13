#include "model/gameState.h"

namespace game_state {
    GameState::GameState(const AliveCells& alive_cells, const std::string& universe_name, FieldSize f_sz) 
        : alive_cells(alive_cells)
        , universe_name(universe_name)
        , f_sz(f_sz) {}

    void GameState::setAliveCells(const AliveCells& new_alive_cells) {
        alive_cells = new_alive_cells;
    }

    const AliveCells& GameState::getAliveCells() const {
        return alive_cells;
    }

    const std::string& GameState::getUniverseName() const {
        return universe_name;
    }

    const FieldSize& GameState::getFieldSize() const {
        return f_sz;
    }
}