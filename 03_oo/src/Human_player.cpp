#include "Human_player.hpp"

#include <iostream>
#include <string>

HumanPlayer::HumanPlayer(ITargetBoard &target_board) : Player(target_board) {}

bool HumanPlayer::performNextMove() {
    bool validInput = false;
    const int DIM = static_cast<int>(m_target_board.dim());
    int col, row;
    std::cout
        << "Where do you want to attack? Make sure the value is Between A and \" << char(m_dim + 64) << \", and 1 and "
        << DIM - 1 << " (e.g. A1)" << std::endl;
    std::string input;
    while (!validInput) {
        std::cin >> input;
        std::tie(col, row) = Board::getColRow(input);

        if (col < 0 || col >= DIM || row < 0 || row >= DIM) {
            std::cout << "Invalid input! Make sure the value is Between A and " << char(DIM + 64) << ", and 1 and "
                      << DIM - 1 << " (e.g. A1)" << std::endl;
            continue;
        }

        validInput = true;
    }

    bool isHit = m_target_board.fire('A' + col, row);
    if (isHit) {
        m_attack_board[col][row] = AttackField::HIT;
    } else {
        m_attack_board[col][row] = AttackField::MISS;
    }
    std::cout << (isHit ? "You hit an enemy ship!!" : "Splash! You hit the water...") << std::endl;
    return isHit;
}
