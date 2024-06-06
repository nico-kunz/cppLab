

#include "GameOfLife.hpp"
#include "Visualizer.hpp"
int main() {
    // TODO 2.4
    GameOfLife gameOfLife = GameOfLife::readFromFile("../gol.txt");
    Visualizer visualizer = Visualizer(gameOfLife, 10);
    visualizer.run();
    gameOfLife.writeToFile("TESTGOL.txt");
}