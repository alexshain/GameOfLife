#ifndef GAMECONFIGREADER
#define GAMECONFIGREADER

#include <filesystem>
#include <string>
#include "model/gameState.h"
#include "view/gameView.h"

using st_prcsr::EvolutionConditions;
using game_state::Cell;
using game_state::AliveCells;
using game_state::FieldSize;

class GameConfigReader {
private:
    EvolutionConditions condition;
    AliveCells a_cells;
    FieldSize f_size{};
    std::string universe_name;

public:
    bool readFile(const std::filesystem::path& file_path);
    [[nodiscard]] const EvolutionConditions& getEvolutionConditions() const;
    [[nodiscard]] const AliveCells& getAliveCells() const;
    [[nodiscard]] const FieldSize& getFieldSize() const;
    [[nodiscard]] const std::string& getUniverseName() const;

private:
    static std::vector<std::string> split(const std::string& str, char delimiter);
    void lineProcessor(const std::vector<std::string>& words);
    static bool isInteger(const std::string& str);
    void setConditions(const std::string& condition_str);
    void setSize(const std::string& size_str);
};

#endif //GAMECONFIGREADER