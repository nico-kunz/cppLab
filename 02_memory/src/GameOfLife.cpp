#include <ctime>
#include <cstdlib>

#include "GameOfLife.hpp"


// TODO 2.2 & 2.3

GameOfLife::GameOfLife(int x_size, int y_size, int prob) : X_SIZE(x_size), Y_SIZE(y_size) {
    std::srand(std::time(nullptr));

    // resize to given size
    colonies.resize(y_size, std::vector<Colony *>(x_size, nullptr));

    for (int y = 0; y < y_size; ++y) {
        for (int x = 0; x < x_size; ++x) {
            const int random = std::rand() % 100;
            colonies.at(y).at(x) = new Colony(random < prob);
        }
    }
}

GameOfLife::GameOfLife(Universe &colonies) : X_SIZE(colonies.size()), Y_SIZE(colonies.at(0).size()) {
    this->colonies.resize(Y_SIZE, std::vector<Colony *>(X_SIZE, nullptr));

    for (int y = 0; y < colonies.size(); ++y) {
        for (int x = 0; x < colonies[0].size(); ++x) {
            this->colonies.at(y).at(x) = colonies.at(y).at(x);
        }
    }
    colonies.clear();
}

GameOfLife::~GameOfLife() {
    // free all the heap allocated colonies
    for (int y = 0; y < Y_SIZE; ++y) {
        for (int x = 0; x < X_SIZE; ++x) {
            delete colonies[y][x];
            colonies[y][x] = nullptr;
        }
    }

    //colonies.clear();
}

GameOfLife::GameOfLife(const GameOfLife &other) : X_SIZE(other.X_SIZE), Y_SIZE(other.Y_SIZE) {
    colonies.resize(Y_SIZE, std::vector<Colony *>(X_SIZE, nullptr));

    for (int y = 0; y < Y_SIZE; ++y) {
        for (int x = 0; x < X_SIZE; ++x) {
            colonies.at(y).at(x) = new Colony(other.colonies.at(y).at(x)->getState());
        }
    }
}

void GameOfLife::iterate() {
    for (int y = 0; y < Y_SIZE; ++y) {
        for (int x = 0; x < X_SIZE; ++x) {
            colonies.at(y).at(x)->calculateNextState(getAliveNeighbors(x, y));
        }
    }

    for (int y = 0; y < Y_SIZE; ++y) {
        for (int x = 0; x < X_SIZE; ++x) {
            colonies.at(y).at(x)->evolve();
        }
    }
}

int GameOfLife::getAliveNeighbors(int x, int y) const {
    // return zero if colony is at edge
    /*if (isAtEdge(x, y))
        return 0;*/

    int aliveNeighbors = 0;

    for (int current_y = y - 1; current_y <= y + 1; ++current_y) {
        for (int current_x = x - 1; current_x <= x + 1; ++current_x) {
            // skip center colony whose neighbors we calculate
            if (current_x == x && current_y == y) {
                continue;
            }

            if(current_x < 0 || current_y < 0 || current_x >= X_SIZE || current_y >= Y_SIZE)
                continue;

            if (colonies.at(current_y).at(current_x)->getState()) {
                ++aliveNeighbors;
            }
        }
    }

    return aliveNeighbors;
}

inline bool GameOfLife::isAtEdge(int x, int y) const {
    if (x == 0 || y == 0 || x == X_SIZE || y == Y_SIZE)
        return true;

    return false;
}

int GameOfLife::getX_SIZE() const {
    return X_SIZE;
}

int GameOfLife::getY_SIZE() const {
    return Y_SIZE;
}

const Universe &GameOfLife::getColonies() const {
    return colonies;
}
void GameOfLife::run() {

}
void GameOfLife::writeToFile(std::string filename) {

}
GameOfLife GameOfLife::readFromFile(std::string filename) {
    return GameOfLife(0, 0, 0);
}


