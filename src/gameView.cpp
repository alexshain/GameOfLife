#include "../include/gameView.h"
#include <iostream>
#include <algorithm>

using game_state::AliveCells;
using game_state::Cell;

namespace game_view {
    void GameView::show(const GameState& state) const {
        int Nx = state.getFieldSize().Nx;
        int Ny = state.getFieldSize().Ny;

        std::cout << "--------- " << state.getUniverseName() << " ---------" << std::endl;

        AliveCells a_cells = state.getCellsState();
        for(int i = - Ny / 2; i < Ny / 2; ++i) {
            for(int j = - Nx / 2; j < Nx / 2; ++j) {
                Cell c;
                c.x = j;
                c.y = i;
                if(std::find(a_cells.begin(), a_cells.end(), c) != a_cells.end()) {
                    std::cout << " * ";
                } else {
                    std::cout << " 0 ";
                }
            }
            std::cout << "\n\n";
        }
    }

    void GameView::clearScreen() const {
        std::cout << "\033[2J\033[H";
    }
}