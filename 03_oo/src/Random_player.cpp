#include "Random_player.hpp"

#include <cstdlib>

RandomPlayer::RandomPlayer(ITargetBoard& target_board) : Player{ target_board } {}

bool RandomPlayer::performNextMove() {
    return false;
}
