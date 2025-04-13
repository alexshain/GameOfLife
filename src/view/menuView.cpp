#include "view/menuView.h"
#include <iostream>

MenuView::MenuView(MenuModel* m_model): m_model(m_model) {
    this->m_model->addObserver(this);
}

void MenuView::update(std::string arg) {
    std::cout << arg;
}