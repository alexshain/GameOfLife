#include "controller/gameController.h"
#include "gameConfigReader.h"
#include "model/gameState.h"
#include "model/stateProcessor.h"
#include "view/gameView.h"
#include <iostream>
#include <thread>
#include <chrono>

using game_state::GameState;
using view::GameView;
using st_prcsr::StateProcessor;

GameController::GameController(StateProcessor* state_processor, std::string file_path)
    : state_processor_(state_processor)
    , file_path_(file_path) {}

void GameController::runProcessing(StateProcessor* processor) const {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        processor->process();
    }
}

void GameController::start() const {
    GameConfigReader config;

    if(config.readFile(file_path_)) {
        GameState g_state(config.getAliveCells(), config.getUniverseName(), config.getFieldSize());
        state_processor_->setState(g_state);
        state_processor_->setEvolutionConditions(config.getEvolutionConditions());
    }

    runProcessing(state_processor_);
}