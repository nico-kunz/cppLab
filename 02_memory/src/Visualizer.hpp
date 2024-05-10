//
// Created by flo on 2/14/24.
//

#ifndef GOL_SFML_VISUALIZER_H
#define GOL_SFML_VISUALIZER_H

#include <SFML/Graphics.hpp>

#include "GameOfLife.hpp"

class Visualizer : GameOfLife {
private:
    sf::RenderWindow window;
    const int SCALE;

public:
    Visualizer(int x, int y, int prop, int scale);
    Visualizer(const GameOfLife& g, int scale);
    void run() override;
    bool render(const Universe& colonies);
};

#endif // GOL_SFML_VISUALIZER_H
