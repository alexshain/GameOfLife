#ifndef GAMESTATE
#define GAMESTATE

#include <vector>

namespace game_state {
    struct Cell {
        int x;
        int y;

        bool operator==(const Cell& other) const {
            return x == other.x && y == other.y;
        }
    };

    struct FieldSize {
        int nx;
        int ny;
    };

    using AliveCells = std::vector<Cell>;

    class GameState {
    private:
        AliveCells alive_cells;
        std::string universe_name;
        FieldSize f_sz{};

    public:
        GameState() = default;
        GameState(const AliveCells& alive_cells, const std::string& universe_name, FieldSize f_sz);
        void setAliveCells(const AliveCells& new_alive_cells);
        [[nodiscard]] const AliveCells& getAliveCells() const;
        [[nodiscard]] const std::string& getUniverseName() const;
        [[nodiscard]] const FieldSize& getFieldSize() const;
    };
}

#endif //GAMESTATE
