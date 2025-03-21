#ifndef GAMESTRATEGY
#define GAMESTRATEGY

#include "model/stateProcessor.h"

using st_prcsr::StateProcessor;

class GameStrategy {
protected:
    std::string input_file;

public:
    explicit GameStrategy(const std::string& input_file);
    virtual void execute() const = 0;
    virtual ~GameStrategy() = default;
};

#endif //GAMESTRATEGY