#include "game_strategy/onlineStrategy.h"
#include "controller/gameController.h"
#include "model/stateProcessor.h"
#include "view/gameView.h"
#include "model/menuModel.h"
#include "view/menuView.h"
#include <iostream>

using view::GameView;

OnlineStrategy::OnlineStrategy(const std::string& input_file, const std::string& output_file, size_t iterations)
    : GameStrategy(input_file, output_file, iterations) {}

void OnlineStrategy::execute() {
    StateProcessor processor;
    MenuModel m_model;
    GameView g_view(&processor);
    MenuView m_view(&m_model);
    GameController controller(&processor, &m_model, input_file);
    controller.start();
    output_file = m_model.getOutputFile();
    writeFile(processor);
}