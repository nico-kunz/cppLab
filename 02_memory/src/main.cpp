

#include "GameOfLife.hpp"
#include "Visualizer.hpp"
int main() {
    // TODO 2.4
    GameOfLife gameOfLife = GameOfLife(50, 50, 80);
    Visualizer visualizer = Visualizer(gameOfLife, 20);
    visualizer.run();
}