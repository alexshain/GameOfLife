#include "game_strategy/offlineStrategy.h"
#include "gameConfigReader.h"
#include "model/stateProcessor.h"
#include <iostream>
#include <fstream>

using game_state::FieldSize;

OfflineStrategy::OfflineStrategy(const std::string& input_file, const std::string& output_file, size_t iterations)
    : GameStrategy(input_file)
    , output_file(output_file)
    , iterations(iterations) {}

void OfflineStrategy::execute() const {
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

void OfflineStrategy::writeFile(const StateProcessor& processor) const {
    std::ofstream file(output_file);

    if (!file) {
        std::cerr << "Warning: Error opening file!" << std::endl;
        file.open("out_Life.life");
    }

    file << "#Life 1.06\n"; 
    file << "#N " << processor.getState().getUniverseName() << std::endl;

    std::string birth_str;
    for(const auto &it: processor.getConditions().birth_condition) {
        birth_str += std::to_string(it);
    }

    std::string srv_str;
    for(auto it: processor.getConditions().survival_condition) {
        srv_str += std::to_string(it);
    }
    file << "#R B" << birth_str << "/S" << srv_str << std::endl;

    FieldSize f_size = processor.getState().getFieldSize();
    file << "#S X" << f_size.nx << "/Y" << f_size.ny << std::endl;

    for(auto it: processor.getState().getAliveCells()) {
        file << it.x << " " << it.y << std::endl;
    }

    file << iterations << std::endl;

    file.close();
}