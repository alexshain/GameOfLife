#ifndef GAMECONFIGREADER
#define GAMECONFIGREADER

#include <filesystem>
#include <sstream>
#include <string>
#include "model/gameState.h"
#include "controller/gameController.h"
#include "view/gameView.h"

using st_prcsr::EvolutionConditions;
using game_state::Cell;
using game_state::AliveCells;
using game_state::FieldSize;

class GameConfigReader {
private:
    EvolutionConditions condition_;
    AliveCells a_cells_;
    FieldSize f_size_;
    std::string universe_name_;

public:
    bool readFile(std::filesystem::path file_path);
    EvolutionConditions getEvolutionConditions() const;
    AliveCells getAliveCells() const;
    FieldSize getFieldSize() const;
    std::string getUniverseName() const;

private:
    std::vector<std::string> split(const std::string& str, char delimiter);
    void lineProcessor(const std::vector<std::string>& words);
    bool isInteger(const std::string& str);
    void setConditions(const std::string& condition_str);
    void setSize(const std::string& size_str);
};

#endif //GAMECONFIGREADER