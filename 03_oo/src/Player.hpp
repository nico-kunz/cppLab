#pragma once

#include <string>
#include <set>

#include "Board.hpp"

class Player {
  public:
    Player(ITargetBoard& target_board) {}

    virtual ~Player() {}

    virtual bool performNextMove() = 0;

    void print_result_map();
};
