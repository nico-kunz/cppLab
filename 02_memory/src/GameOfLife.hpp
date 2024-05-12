//
// Created by flo on 2/14/24.
//

#ifndef GOL_SFML_GAMEOFLIFE_H
#define GOL_SFML_GAMEOFLIFE_H

#include <string>
#include <vector>

#include "Colony.hpp"

typedef std::vector<std::vector<Colony*>> Universe;

class GameOfLife {
private:
    int getAliveNeighbors(int x, int y) const;
    bool isAtEdge(int x, int y) const;

protected:
    Universe colonies;
    const int Y_SIZE;
    const int X_SIZE;

public:
    GameOfLife(int x_size, int y_size, int prob);
    GameOfLife(Universe& colonies);

    GameOfLife(const GameOfLife&);
    GameOfLife& operator=(const GameOfLife&) = delete;

    ~GameOfLife();

    void iterate();
    virtual void run();

    int getX_SIZE() const;
    int getY_SIZE() const;
    const Universe& getColonies() const;

    void writeToFile(std::string filename);
    static GameOfLife readFromFile(std::string filename);
};

#endif // GOL_SFML_GAMEOFLIFE_H
