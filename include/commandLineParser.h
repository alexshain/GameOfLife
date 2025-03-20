#ifndef COMMANDLINEPARSER
#define COMMANDLINEPARSER

#include "game_strategy/gameContext.h"
#include <string>

class CommandLineParser {
private:
    std::vector<std::string> argv_;

public:
    CommandLineParser(int argc, char* argv[]);
    void initializeContext(GameContext* context) const;

private:
    bool contains(const std::vector<std::string>& argv, std::string str) const;
};

#endif //COMMANDLINEPARSER