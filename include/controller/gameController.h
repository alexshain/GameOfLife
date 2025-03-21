#ifndef GAMECONTROLLER
#define GAMECONTROLLER

#include "model/stateProcessor.h"

using st_prcsr::StateProcessor;

class GameController {
private:
    StateProcessor* state_processor;
    std::string file_path;

public:
    GameController(StateProcessor* state_processor, const std::string& file_path);
    void start() const;

private:
    void runProcessing() const;
};

#endif //GAMECONTROLLER