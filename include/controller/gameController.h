#ifndef GAMECONTROLLER
#define GAMECONTROLLER

#include "model/stateProcessor.h"
#include "model/menuModel.h"

using st_prcsr::StateProcessor;

class GameController {
private:
    StateProcessor* state_processor;
    MenuModel* m_model;
    std::string file_path;
    size_t iterations;

public:
    GameController(StateProcessor* state_processor, MenuModel* m_model, const std::string& file_path);
    void start() const;

private:
    void runProcessing() const;
};

#endif //GAMECONTROLLER