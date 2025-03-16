#include "../../include/controller/gameController.h"
#include "../../include/gameConfigReader.h"
#include "../../include/model/gameState.h"
#include "../../include/model/stateProcessor.h"
#include "../../include/view/gameView.h"
#include <iostream>
#include <thread>
#include <chrono>

using game_state::GameState;
using view::GameView;
using st_prcsr::StateProcessor;

GameController::GameController(StateProcessor* state_processor): state_processor_(state_processor) {}

void proc(StateProcessor* processor, GameState& g_state) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        processor->process();
    }
}

void GameController::start() {
    std::unique_ptr<GameConfigReader> config = std::make_unique<GameConfigReader>();
    std::string file_path = "../examples/Life1.life";
    //std::cin >> file_path;

    while(true) {
        try {
            config->readFile(file_path);
            break;
        } catch(const std::exception& e) { 
            std::cerr << "An error occurred: " << e.what() << " try another path" << std::endl;
        }
    }

    GameState g_state(config->getAliveCells(), config->getUniverseName(), config->getFieldSize());
    state_processor_->setState(&g_state);
    state_processor_->setEvolutionConditions(config->getEvolutionConditions());
    proc(state_processor_, g_state);
}