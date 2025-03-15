#include "../include/stateProcessor.h"
#include <iostream>

using game_state::AliveCells;

namespace st_prcsr {
    StateProcessor::StateProcessor(const std::shared_ptr<GameState>& state, EvolutionConditions conditions)
        : state_(state)
        , conditions_(conditions) {}

        GameState StateProcessor::nextState() {
        int Nx = state_->getFieldSize().Nx;
        int Ny = state_->getFieldSize().Ny;

        AliveCells a_cells = state_->getCellsState();
        AliveCells new_alive_cells;
        Cell c;
        for(int i = - Ny / 2; i < Ny / 2; ++i) {
            for(int j = - Nx / 2; j < Nx / 2; ++j) {
                c.x = j;
                c.y = i;
                if(std::find(a_cells.begin(), a_cells.end(), c) != a_cells.end()) {
                    // сделать так, чтоб использовалось условие из файла
                    if(getNeighborCount(c) == 2 || getNeighborCount(c) == 3) {
                        new_alive_cells.push_back(c);
                    }
                } else {
                    if(getNeighborCount(c) == 3) {
                        new_alive_cells.push_back(c);
                    }
                }
            }
        }

        std::cout << new_alive_cells.size() << std::endl;

        state_->setNextState(new_alive_cells);
        return *state_;
    }

    int StateProcessor::getNeighborCount(Cell current_cell) {
        int Nx = state_->getFieldSize().Nx;
        int Ny = state_->getFieldSize().Ny;
        int count = 0;
        AliveCells a_cells = state_->getCellsState();
        Cell c;
        for(int i = current_cell.y - 1; i <= current_cell.y + 1; ++i) {
            for(int j = current_cell.x - 1; j <= current_cell.x + 1; ++j) {
                c.x = j;
                c.y = i;
                if(c.x >= Nx / 2) {
                    c.x = c.x - Nx;
                }
                if(c.x < -Nx / 2) {
                    c.x = c.x + Nx;
                }
                if(c.y >= Ny / 2) {
                    c.y = c.y - Ny;
                }
                if(c.y < -Ny / 2) {
                    c.y = c.y + Ny;
                }
                if(c == current_cell) {
                    continue;
                } else if(std::find(a_cells.begin(), a_cells.end(), c) != a_cells.end()) {
                    count++;
                }
            }
        }
        return count;
    }
}