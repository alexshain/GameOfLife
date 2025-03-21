#include "controller/gameController.h"
#include "gameConfigReader.h"
#include "model/gameState.h"
#include "model/stateProcessor.h"
#include "view/gameView.h"
#include <thread>
#include <chrono>

using game_state::GameState;
using view::GameView;
using st_prcsr::StateProcessor;

GameController::GameController(StateProcessor* state_processor, const std::string& file_path)
    : state_processor(state_processor)
    , file_path(file_path) {}

void GameController::runProcessing() const {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        state_processor->process();
    }
}

void GameController::start() const {
    GameConfigReader config;

    if(config.readFile(file_path)) {
        GameState g_state(config.getAliveCells(), config.getUniverseName(), config.getFieldSize());
        state_processor->setState(g_state);
        state_processor->setEvolutionConditions(config.getEvolutionConditions());
    }

    runProcessing();
}