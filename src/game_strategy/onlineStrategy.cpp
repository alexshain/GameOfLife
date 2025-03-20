#include "../../include/game_strategy/onlineStrategy.h"
#include "../../include/controller/gameController.h"
#include "../../include/model/stateProcessor.h"
#include "../../include/view/gameView.h"
#include <iostream>

using view::GameView;

OnlineStrategy::OnlineStrategy(std::string input_file) : GameStrategy(input_file) {}

void OnlineStrategy::execute() const {
    StateProcessor processor;
    GameView view(&processor);
    GameController controller(&processor, input_file_);
    controller.start();
}