#pragma once

#include <string>
#include <set>

#include "Board.hpp"

enum class AttackField {
    HIT,
    MISS,
    NONE
};

class Player {
  public:
    Player(ITargetBoard &target_board) : m_target_board(target_board),
                                         m_attack_board(target_board.dim(),
                                                        std::vector<AttackField>(target_board.dim(),
                                                                                 AttackField::NONE)) {

    }

    virtual ~Player() {
    }

    virtual bool performNextMove() = 0;

    void print_result_map();
  protected:
    ITargetBoard &m_target_board;
    std::vector<std::vector<AttackField>> m_attack_board;
};
