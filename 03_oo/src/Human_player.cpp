#include "Human_player.hpp"

#include <iostream>
#include <string>

HumanPlayer::HumanPlayer(ITargetBoard& target_board) : Player(target_board) {}

bool HumanPlayer::performNextMove() {
    return false;
}
