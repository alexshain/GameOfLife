#ifndef GAMEVIEW
#define GAMEVIEW

#include "gameState.h"

using game_state::AliveCells;
using game_state::GameState;

namespace game_view {
    class GameView {

    public:
        void show(const GameState& state) const;
        void clearScreen() const;
    };
}

#endif //GAMEVIEW