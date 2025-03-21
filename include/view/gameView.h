#ifndef GAMEVIEW
#define GAMEVIEW

#include "model/gameState.h"
#include "model/stateProcessor.h"
#include "observer.h"

using game_state::AliveCells;
using game_state::GameState;
using st_prcsr::StateProcessor;


namespace view {
    class GameView: public Observer {
    private:
    // переписать на умные указатели
        StateProcessor* state_processor_;

    public:
        explicit GameView(StateProcessor* state_processor);
        void update();
    
    private:
        void clearScreen();
    };
}

#endif //GAMEVIEW