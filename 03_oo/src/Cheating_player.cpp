#include "Cheating_player.hpp"

#include <cassert>

CheatingPlayer::CheatingPlayer(ITargetBoard& target_board) : Player(target_board) {}

bool CheatingPlayer::performNextMove() {
    return false;
}
