#include "controller/gameController.h"
#include "gameConfigReader.h"
#include "model/gameState.h"
#include "model/stateProcessor.h"
#include "view/gameView.h"
#include <thread>
#include <iostream>
#include <chrono>

using game_state::GameState;
using view::GameView;
using st_prcsr::StateProcessor;

GameController::GameController(StateProcessor* state_processor, MenuModel* m_model, const std::string& file_path)
    : state_processor(state_processor)
    , m_model(m_model)
    , file_path(file_path) {
        iterations = 1;
    }

void GameController::runProcessing() const {
    while (state_processor->process() < m_model->getIterations()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
}

void callInputStream(std::string& line) {
    std::cin >> line;
    if(line == "exit") {
        std::exit(0);
    }
}

void GameController::start() const {
    m_model->call();
    std::string output_file;
    callInputStream(output_file);
    m_model->setOutputFile(output_file);

    //обработать если ввели не число
    std::string n_iters;
    callInputStream(n_iters);
    m_model->setIterations(std::stoi(n_iters));
    std::this_thread::sleep_for(std::chrono::seconds(2));

    GameConfigReader config;

    if(config.readFile(file_path)) {
        GameState g_state(config.getAliveCells(), config.getUniverseName(), config.getFieldSize());
        state_processor->setState(g_state);
        state_processor->setEvolutionConditions(config.getEvolutionConditions());
    }

    runProcessing();
}