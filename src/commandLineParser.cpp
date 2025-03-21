#include "commandLineParser.h"
#include "game_strategy/offlineStrategy.h"
#include "game_strategy/onlineStrategy.h"
#include <algorithm>
#include <memory>
#include <iostream>

CommandLineParser::CommandLineParser(int argc, char* argv[]) : argv_(argv, argv + argc) {}

void CommandLineParser::initializeContext(GameContext* context) const {
    //отрефакторить потом условные операторы
    std::string input_file = argv_.size() > 1 ? argv_[1] : "";
    if(contains(argv_, "-i") || contains(argv_, "-o")) {
        //сделать какую нибудь проверку записи в файл
        auto iters_it = std::find(argv_.begin(), argv_.end(), "-i");
        auto out_file_it = std::find(argv_.begin(), argv_.end(), "-o");

        int iters_index = iters_it != argv_.end() ? std::distance(argv_.begin(), iters_it) + 1 : 0;
        int out_file_index = out_file_it != argv_.end() ? std::distance(argv_.begin(), out_file_it) + 1 : 0;

        // значение по умолчанию
        std::string output_file = "out_Life.life";
        if(out_file_index > 0 && argv_.size() > out_file_index) {
            output_file = argv_[out_file_index];
        }

        size_t iterations;
        if(iters_index > 0 && argv_.size() > iters_index) {
            try {
                iterations = std::stoi(argv_[iters_index]);
            } catch (const std::invalid_argument&) {
                std::cerr << "Warning: Invalid value for iterations. The default value was set: iterations = 1" << std::endl;
                // значение по умолчанию
                iterations = 1;
            } catch (const std::out_of_range&) {
                std::cerr << "Warning: Number is out of range. The default value was set: iterations = 1" << std::endl;
                // значение по умолчанию
                iterations = 1;
            }
        }
        std::unique_ptr<OfflineStrategy> offlineStrategy = std::make_unique<OfflineStrategy>(input_file, output_file, iterations);
        context->setStrategy(std::move(offlineStrategy));
    } else {
        std::unique_ptr<OnlineStrategy> onlineStrategy = std::make_unique<OnlineStrategy>(input_file); 
        context->setStrategy(std::move(onlineStrategy));
    }
}

bool CommandLineParser::contains(const std::vector<std::string>& argv, std::string str) const {
    return std::find(argv.begin(), argv.end(), str) != argv.end();
}