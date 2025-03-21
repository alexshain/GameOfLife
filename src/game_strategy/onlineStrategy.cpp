#include "game_strategy/onlineStrategy.h"
#include "controller/gameController.h"
#include "model/stateProcessor.h"
#include "view/gameView.h"
#include <iostream>

using view::GameView;

OnlineStrategy::OnlineStrategy(const std::string& input_file) : GameStrategy(input_file) {}

void OnlineStrategy::execute() const {
    StateProcessor processor;
    GameView view(&processor);
    GameController controller(&processor, input_file);
    controller.start();
}