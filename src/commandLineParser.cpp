#include "commandLineParser.h"
#include "game_strategy/offlineStrategy.h"
#include "game_strategy/onlineStrategy.h"
#include <iostream>

CommandLineParser::CommandLineParser(int argc, char* argv[]) : argv(argv, argv + argc) {}

void CommandLineParser::initializeContext(GameContext* context) const {
    //отрефакторить потом условные операторы
    std::string input_file = argv.size() > 1 ? argv[1] : "";
    if(contains(argv, "-i") || contains(argv, "-o")) {
        //сделать какую нибудь проверку записи в файл
        auto iters_it = std::find(argv.begin(), argv.end(), "-i");
        auto out_file_it = std::find(argv.begin(), argv.end(), "-o");

        int iters_index = iters_it != argv.end() ? std::distance(argv.begin(), iters_it) + 1 : 0;
        int out_file_index = out_file_it != argv.end() ? std::distance(argv.begin(), out_file_it) + 1 : 0;

        // значение по умолчанию
        std::string output_file = "out_Life.life";
        if(out_file_index > 0 && argv.size() > out_file_index) {
            output_file = argv[out_file_index];
        }

        size_t iterations;
        if(iters_index > 0 && argv.size() > iters_index) {
            try {
                iterations = std::stoi(argv[iters_index]);
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
        //переписать конструктор или как то переделать эту инициализацию
        std::unique_ptr<OnlineStrategy> onlineStrategy = std::make_unique<OnlineStrategy>(input_file, "out.txt", 1);
        context->setStrategy(std::move(onlineStrategy));
    }
}

bool CommandLineParser::contains(const std::vector<std::string>& argv, const std::string& str) {
    return std::find(argv.begin(), argv.end(), str) != argv.end();
}