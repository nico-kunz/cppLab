#include "Cheating_player.hpp"

#include <cassert>
#include <iostream>

CheatingPlayer::CheatingPlayer(ITargetBoard &target_board) : Player(target_board) {}

bool CheatingPlayer::performNextMove() {
    Board board = dynamic_cast<Board &>(m_target_board);
    for (int i = 0; i < m_target_board.dim(); ++i) {
        for (int j = 0; j < m_target_board.dim(); ++j) {
            if (board.m_board[i][j] == Field::SHIP) {
                m_target_board.fire('A' + i, j);
                m_attack_board[j][i] = AttackField::HIT;
                return true;
            }
        }
    }
    std::cout << "Something went wrong here..." << std::endl;
    return false;
}
