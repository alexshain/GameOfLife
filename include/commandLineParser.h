#ifndef COMMANDLINEPARSER
#define COMMANDLINEPARSER

#include "game_strategy/gameContext.h"
#include <string>

class CommandLineParser {
private:
    std::vector<std::string> argv;

public:
    CommandLineParser(int argc, char* argv[]);
    void initializeContext(GameContext* context) const;

private:
    static bool contains(const std::vector<std::string>& argv, const std::string& str) ;
};

#endif //COMMANDLINEPARSER