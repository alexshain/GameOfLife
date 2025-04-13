#ifndef GAMEPROGRESSVIEW
#define GAMEPROGRESSVIEW

#include "observer.h"
#include "model/menuModel.h"

class MenuView: public Observer {
    private:
        MenuModel* m_model;

    public:
        explicit MenuView(MenuModel* m_model);
        void update(std::string arg) override;
};

#endif //GAMEPROGRESSVIEW