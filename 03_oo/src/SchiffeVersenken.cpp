#include <iostream>
#include <string>
#include <vector>

#include "Board.hpp"
#include "GameController.hpp"
#include "Human_player.hpp"
#include "Random_player.hpp"

constexpr size_t DIM = 5;

static const std::vector<Ship> FLEET = {
    Ship(3, "destroyer"),
    Ship(2, "submarine"),
    Ship(2, "submarine"),
};

int main(void) {

    Board b1(DIM);
    Board b2(DIM);

    HumanPlayer player1(b2);
    RandomPlayer player2(b1);
    play(player1, b1, player2, b2, FLEET);

    return 0;
}
