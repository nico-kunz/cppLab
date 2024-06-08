#include "Player.hpp"

#include <iostream>

void Player::print_result_map() {
    for (int i = 0; i < m_attack_board.size(); ++i) {
        std::cout << std::string(4 * m_attack_board.size() + 1, '-') << std::endl;
        for (int j = 0; j < m_attack_board.size(); ++j) {
            std::cout << "|";
            switch (m_attack_board[j][i]) {
                case AttackField::MISS: std::cout << " ~ ";
                    break;
                case AttackField::HIT: std::cout << " X ";
                    break;
                case AttackField::NONE:
                    std::cout << "   ";
                    break;
            }
        }
        std::cout << "| " << i << std::endl;
    }
    std::cout << std::string(4 * m_attack_board.size() + 1, '-') << std::endl;

    for (char c = 'A'; c < 'A' + m_attack_board.size(); c++) {
        std::cout << "  " << c << " ";
    }
}
