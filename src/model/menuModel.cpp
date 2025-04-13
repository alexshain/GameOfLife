#include "model/menuModel.h"
#include <iostream>

void MenuModel::call() {
    notifyUpdate("dump: ");
}

void MenuModel::setIterations(size_t iterations) {
    notifyUpdate("starting...");
    std::cout << std::endl;
    this->iterations = iterations;
}

void MenuModel::setOutputFile(const std::string& output_file) {
    this->output_file = output_file;
    notifyUpdate("tick: ");
}

size_t MenuModel::getIterations() const {
    return iterations;
}

std::string MenuModel::getOutputFile() const {
    return output_file;
}