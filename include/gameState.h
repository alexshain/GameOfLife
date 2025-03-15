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
        AliveCells cells_state_;
        std::string universe_name_;
        FieldSize f_sz_;

    public:
        GameState(const AliveCells& inition_state, const std::string& universe_name, FieldSize f_sz);
        void setNextState(const AliveCells& next_state);
        AliveCells getCellsState() const;
        std::string getUniverseName() const;
        FieldSize getFieldSize() const;
    };
}

#endif //GAMESTATE
