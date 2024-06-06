#pragma once

#include <algorithm>
#include <ostream>
#include <stdexcept>
#include <vector>

struct Ship {
    size_t length;
    std::string type;

    Ship(size_t length, std::string type) : length(length), type(type) {}
};

enum class Field {
    SHIP,
    WATER,
    HIT
};

class ITargetBoard {
  public:
    virtual bool fire(char col, unsigned char row) = 0;
    virtual bool fleet_destroyed() const = 0;
    virtual size_t dim() const = 0;
};

class Board : public ITargetBoard {
  public:
    Board(size_t dim) {
        if (dim < 2 || dim > 10) {
            throw std::invalid_argument("Dimension must be in [2, 10]");
        }
        m_dim = dim;
        m_board = std::vector(dim, std::vector(dim, Field::WATER));
        srand(time(nullptr));
    }

    void place_fleet_randomly(const std::vector<Ship>& fleet);
    void place_fleet_manually(const std::vector<Ship>& fleet);

    size_t dim() const override { return 0; }

    virtual bool fire(char col, unsigned char row) override {
        return false;
    }

    virtual bool fleet_destroyed() const override {
        return true;
    }

    Field at(char col, unsigned char row) const {
        int x = std::toupper(col) - 65;
        int y = row - '0';
        return m_board[x][y];
    }

    void set_ship_manually(char col, unsigned char row) {}

  private:
    size_t m_dim;
    std::vector<std::vector<Field>> m_board;
};

std::ostream& operator<<(std::ostream& os, const Board& board);
