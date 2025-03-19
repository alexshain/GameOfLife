//посмотреть, можно ли избежать этого двоеточия
#include "../include/controller/gameController.h"
#include "../include/model/stateProcessor.h"
#include "../include/view/gameView.h"
#include <iostream>

using view::GameView;

int main(int argc, char* argv[]) {
    StateProcessor processor;
    GameView view(&processor);
    GameController controller(&processor, argc, argv);
    controller.start();
    return 0;
}