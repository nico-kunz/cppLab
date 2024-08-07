#include "Board.hpp"

#include <iostream>
#include <random>

void Board::place_fleet_manually(const std::vector<Ship> &fleet) {
    int shipsPlaced = 0;

    while (shipsPlaced < fleet.size()) {
        std::string input;
        std::cout << shipsPlaced + 1 << ". " << "Input where to place the ship " << fleet[shipsPlaced].type
                  << " length " << fleet[shipsPlaced].length << std::endl;
        std::cin >> input;
        auto [col, row] = getColRow(input);

        if (col < 0 || col >= m_dim || row < 0 || row >= m_dim) {
            std::cout << "Invalid input! Make sure the value is Between A and " << char(m_dim + 64) << ", and 1 and "
                      << m_dim - 1 << " (e.g. A1)" << std::endl;
            continue;
        }

        std::cout << "Input where the ship should end" << std::endl;
        std::cin >> input;
        auto [colEnd, rowEnd] = getColRow(input);
        if (colEnd != col && rowEnd != row) {
            std::cout << "Ships can't be placed diagonally!" << std::endl;
            continue;
        }

        if (std::abs((colEnd - col) + (rowEnd - row)) + 1 != fleet[shipsPlaced].length) {
            std::cout << "Coordinate does not match ship length " << fleet[shipsPlaced].length << std::endl;
            continue;
        }

        bool couldBePlaced = placeShip(col, row, colEnd, rowEnd);
        if (couldBePlaced) {
            shipsPlaced++;
        } else {
            std::cout << "Ship cannot be placed here, because it collides with another ship." << std::endl;
        }
    }
}

bool Board::placeShip(int col, int row, int colEnd, int rowEnd) {
    int directionX = col == colEnd ? 0 : col > colEnd ? -1 : 1;
    int directionY = row == rowEnd ? 0 : row > rowEnd ? -1 : 1;

    auto previousBoard = std::vector(m_board);

    while (col != colEnd + directionX) {
        if (m_board[col][row] == Field::SHIP) {
            m_board = previousBoard;
            return false;
        }

        m_board[col][row] = Field::SHIP;
        col += directionX;
    }

    while (row != rowEnd + directionY) {
        if (m_board[col][row] == Field::SHIP) {
            m_board = previousBoard;
            return false;
        }

        m_board[col][row] = Field::SHIP;
        row += directionY;
    }

    return true;
}

std::tuple<int, int> Board::getColRow(std::string &s) {
    return {std::toupper(s[0]) - 65, s[1] - '0'};
}

void Board::place_fleet_randomly(const std::vector<Ship> &fleet) {
    srand(rand() + time(nullptr));

    for (const auto &ship : fleet) {
        bool couldBePlaced = false;
        while (!couldBePlaced) {
            int col = rand() % m_dim;
            int row = rand() % m_dim;
            int direction = rand() % 2;

            int colEnd = col;
            int rowEnd = row;

            if (direction == 1) {
                colEnd += ship.length - 1;
            } else {
                rowEnd += ship.length - 1;
            }

            if (colEnd >= m_dim || rowEnd >= m_dim) {
                continue;
            }

            couldBePlaced = placeShip(col, row, colEnd, rowEnd);
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Board &board) {
    for (int i = 0; i < board.m_dim; ++i) {
        os << std::string(4 * board.m_dim + 1, '-') << std::endl;
        for (int j = 0; j < board.m_dim; ++j) {
            os << "|";
            switch (board.m_board[j][i]) {
                case Field::SHIP:
                    os << " S ";
                    break;
                case Field::WATER:
                    os << "   ";
                    break;
                case Field::HIT:
                    os << " X ";
                    break;
            }
        }
        os << "| " << i << std::endl;
    }
    os << std::string(4 * board.m_dim + 1, '-') << std::endl;

    for (char c = 'A'; c < 'A' + board.m_dim; c++) {
        os << "  " << c << " ";
    }
    return os;
}