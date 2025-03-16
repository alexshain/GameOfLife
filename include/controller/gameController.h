#ifndef GAMECONTROLLER
#define GAMECONTROLLER

#include "../model/stateProcessor.h"

using st_prcsr::StateProcessor;

class GameController {
private:
    StateProcessor* state_processor_;

public:
    GameController(StateProcessor* state_processor);
    void start();
};



#endif //GAMECONTROLLER