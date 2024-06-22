#include "Random_player.hpp"

#include <cstdlib>
#include <iostream>

RandomPlayer::RandomPlayer(ITargetBoard &target_board) : Player{target_board} {}

bool RandomPlayer::performNextMove() {
    srand(rand() + time(nullptr));

    int col = rand() % m_target_board.dim();
    int row = rand() % m_target_board.dim();

    // keep generating new random coords until field with no previous attack is found
    while (m_attack_board[col][row] != AttackField::NONE) {
        col = rand() % m_target_board.dim();
        row = rand() % m_target_board.dim();
    }

    bool isHit = m_target_board.fire('A' + col, row);

    if (isHit) {
        m_attack_board[col][row] = AttackField::HIT;
    } else {
        m_attack_board[col][row] = AttackField::MISS;
    }

    return isHit;
}
