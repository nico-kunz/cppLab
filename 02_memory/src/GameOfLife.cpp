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
            delete colonies[y][x];
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

    colonies.clear();
}

GameOfLife::GameOfLife(const GameOfLife &other) : X_SIZE(other.X_SIZE), Y_SIZE(other.Y_SIZE) {
    colonies.resize(Y_SIZE, std::vector<Colony *>(X_SIZE, nullptr));

    for (int y = 0; y < Y_SIZE; ++y) {
        for (int x = 0; x < X_SIZE; ++x) {
            colonies.at(y).at(x) = new Colony(other.colonies.at(y).at(x));
        }
    }
}




