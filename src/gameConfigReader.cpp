#include "gameConfigReader.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

bool GameConfigReader::readFile(std::filesystem::path file_path) {
    std::ifstream file(file_path);

    if(!file.is_open()) {
        return false;
    }

    std::string line;
    // Skip first line
    std::getline(file, line);
    // обработать случай пустого файла или файла с какой то фигней или без имени вселенной и тд 
    while (std::getline(file, line)) {
        std::vector<std::string> words = split(line, ' ');
        lineProcessor(words);
    }
    return true;
}

std::vector<std::string> GameConfigReader::split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void GameConfigReader::lineProcessor(const std::vector<std::string>& words) {
    if(words[0] == "#N") {
        universe_name_ = words[1];
    } else if(words[0] == "#R") {
        setConditions(words[1]);
    } else if(words[0] == "#S") {
        setSize(words[1]);
    } else if(isInteger(words[0]) && isInteger(words[1])) {
        Cell alive_cell;
        alive_cell.x = std::stoi(words[0]);
        alive_cell.y = std::stoi(words[1]);
        a_cells_.push_back(alive_cell);
    }
}

bool GameConfigReader::isInteger(const std::string& str) {
    if (str.empty()) return false;

    // Check first char
    size_t start = (str[0] == '-' || str[0] == '+') ? 1 : 0;
    return start < str.size() && std::all_of(str.begin() + start, str.end(), ::isdigit);
}

void GameConfigReader::setConditions(const std::string& condition_str) {
    // example: B3/S23

    //обработать случай передачи буквы среди цифр, не передачи ничего после B и S, не передачи B3/S23
    size_t start_birth_cndtn = condition_str.find('B'); 
    size_t end_birth_cndtn = condition_str.find('/'); 
    size_t start_survive_cndtn = condition_str.find('S');

    std::string birth_cndtn;
    std::string survive_cndtn;

    // переделать блоки else
    if (start_birth_cndtn != std::string::npos && end_birth_cndtn != std::string::npos && start_birth_cndtn + 1 < end_birth_cndtn) {
        birth_cndtn = condition_str.substr(start_birth_cndtn + 1, end_birth_cndtn - start_birth_cndtn - 1); 
    } else {
        std::cout << "smth." << std::endl;
    }

    if (start_survive_cndtn != std::string::npos) {
        survive_cndtn = condition_str.substr(start_survive_cndtn + 1); 
    } else {
        std::cout << "smth." << std::endl;
    }

    for(size_t i = 0; i < birth_cndtn.size(); ++i) {
        condition_.birth_condition.insert(std::stoi(birth_cndtn.substr(i, 1)));
    }

    for(size_t i = 0; i < survive_cndtn.size(); ++i) {
        condition_.survival_condition.insert(std::stoi(survive_cndtn.substr(i, 1)));
    }
}

void GameConfigReader::setSize(const std::string& size_str) {
    // example: X10/Y10

    size_t start_x = size_str.find('X'); 
    size_t end_x = size_str.find('/'); 
    size_t start_y = size_str.find('Y');

    //убрать дублирование?
    if (start_x != std::string::npos && end_x != std::string::npos && start_x + 1 < end_x) {
        f_size_.Nx = std::stoi(size_str.substr(start_x + 1, end_x - start_x - 1)); 
    } else {
        std::cout << "smth." << std::endl;
    }

    if (start_y != std::string::npos) {
        f_size_.Ny = std::stoi(size_str.substr(start_y + 1)); 
    } else {
        std::cout << "smth." << std::endl;
    }
}

EvolutionConditions GameConfigReader::getEvolutionConditions() const {
    return condition_;
}

AliveCells GameConfigReader::getAliveCells() const {
    return a_cells_;
}

FieldSize GameConfigReader::getFieldSize() const {
    return f_size_;
}

std::string GameConfigReader::getUniverseName() const {
    return universe_name_;
}