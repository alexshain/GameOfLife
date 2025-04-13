#include "game_strategy/gameContext.h"
#include <iostream>

void GameContext::setStrategy(std::unique_ptr<GameStrategy> strategy) {
    this->strategy = std::move(strategy);
}

void GameContext::executeStrategy() const {
    if (strategy) {
        strategy->execute();
    }
}