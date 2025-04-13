#include "view/gameView.h"
#include <iostream>

using game_state::AliveCells;
using game_state::Cell;

const std::string clear_screen_str = "\033[2J\033[H";

namespace view {
    GameView::GameView(StateProcessor* state_processor) 
    : state_processor(state_processor)
    {
        this->state_processor->addObserver(this);
    }

    void GameView::update(std::string arg) {
        clearScreen();
        show();
        std::cout << "number of iteration: " << arg << std::endl;
    }

    void GameView::show() {
        GameState state = state_processor->getState();
        int Nx = state.getFieldSize().nx;
        int Ny = state.getFieldSize().ny;

        std::cout << "--------- " << state.getUniverseName() << " ---------" << std::endl;

        AliveCells a_cells = state.getAliveCells();
        for(int i = - Ny / 2; i < Ny / 2; ++i) {
            for(int j = - Nx / 2; j < Nx / 2; ++j) {
                Cell c{j, i};
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