#ifndef GAMECONTROLLER
#define GAMECONTROLLER

#include "../model/stateProcessor.h"

using st_prcsr::StateProcessor;

class GameController {
private:
    StateProcessor* state_processor_;
    std::string file_path_;

public:
    GameController(StateProcessor* state_processor, std::string file_path);
    void start() const;

private:
    void runProcessing(StateProcessor* processor) const;
};



#endif //GAMECONTROLLER