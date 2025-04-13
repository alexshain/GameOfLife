#include "game_strategy/gameStrategy.h"
#include "gameConfigReader.h"
#include <fstream>
#include <iostream>

GameStrategy::GameStrategy(const std::string& input_file, const std::string& output_file, size_t iterations)
    : input_file(input_file)
    , output_file(output_file)
    , iterations(iterations) {}

void GameStrategy::writeFile(const StateProcessor& processor) const {
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