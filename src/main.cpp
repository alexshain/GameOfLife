#include "controller/gameController.h"
#include "model/stateProcessor.h"
#include "view/gameView.h"
#include "commandLineParser.h"
#include "game_strategy/gameContext.h"
#include <iostream>

using view::GameView;

int main(int argc, char* argv[]) {
    GameContext context;
    CommandLineParser parser(argc, argv);
    parser.initializeContext(&context);
    context.executeStrategy();
    return 0;
}