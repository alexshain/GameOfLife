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
        int Nx;
        int Ny;
    };

    using AliveCells = std::vector<Cell>;

    class GameState {
    private:
        AliveCells alive_cells_;
        std::string universe_name_;
        FieldSize f_sz_;

    public:
        GameState() = default;
        GameState(const AliveCells& alive_cells, const std::string& universe_name, FieldSize f_sz);
        void setAliveCells(const AliveCells& new_alive_cells);
        AliveCells getAliveCells() const;
        std::string getUniverseName() const;
        FieldSize getFieldSize() const;
    };
}

#endif //GAMESTATE
