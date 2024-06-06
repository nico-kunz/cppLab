//
// Created by nicokunz on 6/6/24.
//

#include "Board.hpp"
#include <iostream>

int main() {
    Board board{10};
    const std::vector<Ship> fleet = {
        Ship(5, "dreadnought"),
        Ship(4, "cruiser"),
        Ship(4, "cruiser"),
        Ship(3, "destroyer"),
        Ship(3, "destroyer"),
        Ship(3, "destroyer"),
        Ship(2, "submarine"),
        Ship(2, "submarine"),
        Ship(2, "submarine"),
        Ship(2, "submarine"),
        Ship(2, "submarine"),
    };
    board.place_fleet_manually(fleet);
    //std::cout << board << std::endl;
}
