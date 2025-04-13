#include "model/stateProcessor.h"
#include <iostream>
#include <string>

using game_state::AliveCells;
using game_state::FieldSize;

namespace st_prcsr {
    StateProcessor::StateProcessor() {
        setDefaultState();
        conditions.birth_condition = {3};
        conditions.survival_condition = {2, 3};
        curr_iter = 0;
    }

    size_t StateProcessor::process() {
        int nx = state.getFieldSize().nx;
        int ny = state.getFieldSize().ny;

        AliveCells a_cells = state.getAliveCells();
        AliveCells new_alive_cells;
        Cell c{};
        for(int i = - ny / 2; i < ny / 2; ++i) {
            for(int j = - nx / 2; j < nx / 2; ++j) {
                c.x = j;
                c.y = i;
                if(std::find(a_cells.begin(), a_cells.end(), c) != a_cells.end()) { //условие того, что ячейка жива
                    std::set<int> s_cndtn = conditions.survival_condition;
                    if(s_cndtn.find(getNeighborCount(c)) != s_cndtn.end()) {
                        new_alive_cells.push_back(c);
                    }
                } else { // мертвая ячейка
                    std::set<int> b_cndtn = conditions.birth_condition;
                    if(b_cndtn.find(getNeighborCount(c)) != b_cndtn.end()) {
                        new_alive_cells.push_back(c);
                    }
                }
            }
        }
        state.setAliveCells(new_alive_cells);
        notifyUpdate(std::to_string(curr_iter));
        return curr_iter++;
    }

    int StateProcessor::getNeighborCount(Cell current_cell) {
        int nx = state.getFieldSize().nx;
        int ny = state.getFieldSize().ny;
        int count = 0;
        AliveCells a_cells = state.getAliveCells();
        Cell c{};
        for(int i = current_cell.y - 1; i <= current_cell.y + 1; ++i) {
            for(int j = current_cell.x - 1; j <= current_cell.x + 1; ++j) {
                c.x = j;
                c.y = i;
                if(c.x >= nx / 2) {
                    c.x = c.x - nx;
                }
                if(c.x < -nx / 2) {
                    c.x = c.x + nx;
                }
                if(c.y >= ny / 2) {
                    c.y = c.y - ny;
                }
                if(c.y < -ny / 2) {
                    c.y = c.y + ny;
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
        FieldSize f_sz{10, 10};

        AliveCells a_cells{{0, -1}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
        std::string universe_name = "Glider (default)";
        state = GameState(a_cells, universe_name, f_sz);
    }

    void StateProcessor::setState(GameState state) {
        this->state = std::move(state);
    }

    void StateProcessor::setEvolutionConditions(EvolutionConditions conditions) {
        this->conditions = std::move(conditions);
    }

    const EvolutionConditions& StateProcessor::getConditions() const {
        return conditions;
    }

    const GameState& StateProcessor::getState() const {
        return state;
    }
}