#include "../../include/model/stateProcessor.h"
#include <iostream>
#include <string>
#include <algorithm>

using game_state::AliveCells;
using game_state::FieldSize;

namespace st_prcsr {
    StateProcessor::StateProcessor() {
        setDefaultState();
        conditions_.birth_condition = {3};
        conditions_.survival_condition = {2, 3};
    }

    void StateProcessor::process() {
        int Nx = state_.getFieldSize().Nx;
        int Ny = state_.getFieldSize().Ny;

        AliveCells a_cells = state_.getAliveCells();
        AliveCells new_alive_cells;
        Cell c;
        for(int i = - Ny / 2; i < Ny / 2; ++i) {
            for(int j = - Nx / 2; j < Nx / 2; ++j) {
                c.x = j;
                c.y = i;
                if(std::find(a_cells.begin(), a_cells.end(), c) != a_cells.end()) { //условие того, что ячейка жива
                    std::set<int> s_cndtn = conditions_.survival_condition;
                    if(std::find(s_cndtn.begin(), s_cndtn.end(), getNeighborCount(c)) != s_cndtn.end()) {
                        new_alive_cells.push_back(c);
                    }
                } else { // мертвая ячейка
                    std::set<int> b_cndtn = conditions_.birth_condition;
                    if(std::find(b_cndtn.begin(), b_cndtn.end(), getNeighborCount(c)) != b_cndtn.end()) {
                        new_alive_cells.push_back(c);
                    }
                }
            }
        }
        state_.setAliveCells(new_alive_cells);
        notifyUpdate();
    }

    int StateProcessor::getNeighborCount(Cell current_cell) {
        int Nx = state_.getFieldSize().Nx;
        int Ny = state_.getFieldSize().Ny;
        int count = 0;
        AliveCells a_cells = state_.getAliveCells();
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

    void StateProcessor::setDefaultState() {
        FieldSize f_sz;
        f_sz.Nx = 10;
        f_sz.Ny = 10;

        AliveCells a_cells{{0, -1}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
        std::string universe_name = "Glider (default)";
        state_ = GameState(a_cells, universe_name, f_sz);
    }

    void StateProcessor::setState(GameState state) {
        state_ = state;
    }

    void StateProcessor::setEvolutionConditions(EvolutionConditions conditions) {
        conditions_ = conditions;
    }

    EvolutionConditions StateProcessor::getConditions() const {
        return conditions_;
    }

    GameState StateProcessor::getState() const {
        return state_;
    }
}