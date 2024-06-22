#include "GameController.hpp"

#include <iostream>
#include <random>

#include "Board.hpp"

void play(Player& player1, Board& board1, Player& player2, Board& board2, const std::vector<Ship>& fleet) {

    bool isPlayer1Turn = true;

    while(isPlayer1Turn) {
        player1.print_result_map();
        player1.performNextMove();
    }

}
