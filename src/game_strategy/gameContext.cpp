#include "game_strategy/gameContext.h"
#include <iostream>

void GameContext::setStrategy(std::unique_ptr<GameStrategy> strategy) {
    strategy_ = std::move(strategy);
}

void GameContext::executeStrategy() const {
    if (strategy_) {
        strategy_->execute();
    }
}