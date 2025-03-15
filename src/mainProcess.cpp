#include "../include/mainProcess.h"
#include "../include/gameConfigReader.h"
#include "../include/gameState.h"
#include "../include/stateProcessor.h"
#include "../include/gameView.h"
#include <iostream>
#include <thread>
#include <chrono>

using game_state::GameState;
using game_view::GameView;
using st_prcsr::StateProcessor;


void process(StateProcessor& processor, const GameView& g_view, GameState& g_state) {
    while (true) {
        g_view.clearScreen();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        g_view.show(g_state);
        g_state = processor.nextState();
    }
}

/*void inputListener() {
    std::string input;
    while (running) {
        std::cin >> input;
        if (input == "exit") {
            running = false;
        }
    }
}*/

void start() {
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

    std::shared_ptr<GameState> g_state = std::make_shared<GameState>(config->getAliveCells(), config->getUniverseName(), config->getFieldSize());
    GameView g_view;
    StateProcessor processor(g_state, config->getEvolutionConditions());

    process(processor, g_view, *g_state);
}