#ifndef GAMECONTEXT
#define GAMECONTEXT

#include "gameStrategy.h"
#include <memory>

class GameContext {
private:
    std::unique_ptr<GameStrategy> strategy_;

public:
    void setStrategy(std::unique_ptr<GameStrategy> strategy);
    void executeStrategy() const;
};

#endif //GAMECONTEXT