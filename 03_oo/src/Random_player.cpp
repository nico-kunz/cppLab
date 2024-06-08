#include "Random_player.hpp"

#include <cstdlib>
#include <iostream>

RandomPlayer::RandomPlayer(ITargetBoard &target_board) : Player{target_board} {}

bool RandomPlayer::performNextMove() {
    srand(rand() + time(nullptr));

    int col = rand() % 10;
    int row = rand() % 10;

    // keep generating new random coords until field with no previous attack is found
    while (m_attack_board[col][row] != AttackField::NONE) {
        col = rand() % 10;
        row = rand() % 10;
    }

    bool isHit = m_target_board.fire('A' + col, row);

    if (isHit) {
        m_attack_board[col][row] = AttackField::HIT;
    } else {
        m_attack_board[col][row] = AttackField::MISS;
    }

    return isHit;
}
