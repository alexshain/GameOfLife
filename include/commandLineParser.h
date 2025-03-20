#ifndef COMMANDLINEPARSER
#define COMMANDLINEPARSER

#include "game_strategy/gameContext.h"

class CommandLineParser {
private:
    std::vector<char*> argv_;

public:
    CommandLineParser(int argc, char* argv[]);
    void initializeContext(GameContext* context) const;

private:
    bool contains(const std::vector<char*>& argv, std::string str) const;
};

#endif //COMMANDLINEPARSER