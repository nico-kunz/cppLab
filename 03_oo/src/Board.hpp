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

    void place_fleet_randomly(const std::vector<Ship> &fleet);
    void place_fleet_manually(const std::vector<Ship> &fleet);

    size_t dim() const override { return m_dim; }
    std::vector<std::vector<Field>> m_board;

    /**
     * Fires a shot at the given coords. Sets the field on the board to hit if a ship was hit.
     * @param col
     * @param row
     * @return True if a ship was hit, false if not.
     */
    virtual bool fire(char col, unsigned char row) override {
        int x = std::toupper(col) - 65;

        bool isHit = m_board[x][row] == Field::SHIP;

        if (isHit) {
            m_board[x][row] = Field::HIT;
        }

        return isHit;
    }

    virtual bool fleet_destroyed() const override {
        for (int i = 0; i < m_dim; ++i) {
            for (int j = 0; j < m_dim; ++j) {
                if (m_board[i][j] == Field::SHIP) {
                    return false;
                }
            }
        }

        return true;
    }

    Field at(char col, unsigned char row) const {
        int x = std::toupper(col) - 65;

        if (x < 0 || x >= m_dim || row < 0 || row >= m_dim) {
            throw std::out_of_range("Index is out of range");
        }
        return m_board[x][row];
    }

    void set_ship_manually(char col, unsigned char row) {
        int x = std::toupper(col) - 65;

        m_board[x][row] = Field::SHIP;
    }

    /**
    * Get tuple containing column and row number from the given string
    * @param s String containing a letter followed by a number < 10
    * @return row number and column number (zero-based)
    */
    static std::tuple<int, int> getColRow(std::string &s);
    friend std::ostream &operator<<(std::ostream &os, const Board &board);

  private:
    size_t m_dim;

    /**
     * Tries placing the ship at the given coordinates, returns true if the ship could be placed.
     * Assumes coords are already within bounds. Resets board on collision.
     * @param col Start column of the ship
     * @param row Start row of the ship
     * @param colEnd End column of the ship
     * @param rowEnd End row of the ship
     * @return True if ship could successfully be placed, false if not.
     */
    bool placeShip(int col, int row, int colEnd, int rowEnd);
};

std::ostream &operator<<(std::ostream &os, const Board &board);