//
// Created by flo on 2/14/24.
//

#include "Visualizer.hpp"

#include <utility>

Visualizer::Visualizer(int x, int y, int prop, int scale)
    : GameOfLife(x, y, prop), SCALE(scale),
      window(sf::RenderWindow(sf::VideoMode(x * scale, y * scale), "GameOfLife")) {}

Visualizer::Visualizer(const GameOfLife& g, int scale)
    : GameOfLife(g), SCALE(scale),
      window(sf::RenderWindow(sf::VideoMode(X_SIZE * scale, Y_SIZE * scale), "GameOfLife")) {}

void Visualizer::run() {
    while (render(colonies)) {
        iterate();
    }
}

bool Visualizer::render(const Universe& colonies) {
    if (window.isOpen()) {
        window.setFramerateLimit(60);
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return false;
            }
        }
        window.clear(sf::Color(1, 1, 31));
        for (int i = 0; i < Y_SIZE; i++) {
            for (int j = 0; j < X_SIZE; j++) {
                if (colonies.at(i).at(j)->getState()) {
                    sf::RectangleShape rect(sf::Vector2f(SCALE - 1, SCALE - 1));
                    rect.setPosition(j * SCALE, i * SCALE);
                    rect.setOutlineColor(sf::Color(125, 125, 125));
                    rect.setFillColor(sf::Color::Green);
                    window.draw(rect);
                }
            }
        }
        window.display();
        return true;
    }
    return false;
}
