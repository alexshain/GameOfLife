#ifndef GAMECONTEXT
#define GAMECONTEXT

#include "gameStrategy.h"

class GameContext {
private:
    std::unique_ptr<GameStrategy> strategy;

public:
    void setStrategy(std::unique_ptr<GameStrategy> strategy);
    void executeStrategy() const;
};

#endif //GAMECONTEXT