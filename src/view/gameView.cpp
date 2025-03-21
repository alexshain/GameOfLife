#include "view/gameView.h"
#include <iostream>
#include <algorithm>

using game_state::AliveCells;
using game_state::Cell;

const std::string clear_screen_str = "\033[2J\033[H";

namespace view {
    GameView::GameView(StateProcessor* state_processor) : state_processor_(state_processor) {
        state_processor_->addObserver(this);
    }

    void GameView::update() {
        clearScreen();
        GameState state = state_processor_->getState();
        int Nx = state.getFieldSize().Nx;
        int Ny = state.getFieldSize().Ny;

        std::cout << "--------- " << state.getUniverseName() << " ---------" << std::endl;

        AliveCells a_cells = state.getAliveCells();
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

    void GameView::clearScreen() {
        std::cout << clear_screen_str;
    }
}