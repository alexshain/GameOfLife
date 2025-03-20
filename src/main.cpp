//посмотреть, можно ли избежать этого двоеточия
#include "../include/controller/gameController.h"
#include "../include/model/stateProcessor.h"
#include "../include/view/gameView.h"
#include "../include/commandLineParser.h"
#include "../include/game_strategy/gameContext.h"
#include <iostream>

using view::GameView;

int main(int argc, char* argv[]) {
    GameContext context;
    CommandLineParser parser(argc, argv);
    parser.initializeContext(&context);
    context.executeStrategy();
    return 0;
}