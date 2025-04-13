#include "game_strategy/offlineStrategy.h"
#include "gameConfigReader.h"
#include "model/stateProcessor.h"
#include <iostream>
#include <fstream>

using game_state::FieldSize;

OfflineStrategy::OfflineStrategy(const std::string& input_file, const std::string& output_file, size_t iterations)
    : GameStrategy(input_file, output_file, iterations) {}

void OfflineStrategy::execute() {
    GameConfigReader config;
    StateProcessor processor;

    if(config.readFile(input_file)) {
        GameState g_state(config.getAliveCells(), config.getUniverseName(), config.getFieldSize());
        processor.setState(g_state);
        processor.setEvolutionConditions(config.getEvolutionConditions());
    }

    for(size_t i = 0; i < iterations; ++i) {
        processor.process();
    }

    writeFile(processor);
}