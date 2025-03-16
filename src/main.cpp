//посмотреть, можно ли избежать этого двоеточия
#include "../include/controller/gameController.h"
#include "../include/model/stateProcessor.h"
#include "../include/view/gameView.h"

using view::GameView;

int main() {
    StateProcessor processor;
    GameView view(&processor);
    GameController controller(&processor);
    controller.start();
    return 0;
}