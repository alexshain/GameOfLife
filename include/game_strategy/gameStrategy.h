#ifndef GAMESTRATEGY
#define GAMESTRATEGY

#include "model/stateProcessor.h"

using st_prcsr::StateProcessor;

class GameStrategy {
protected:
    //StateProcessor* state_processor_;
    std::string input_file_;

public:
    GameStrategy(std::string input_file);
    virtual void execute() const = 0;
    virtual ~GameStrategy() = default;
};

#endif //GAMESTRATEGY