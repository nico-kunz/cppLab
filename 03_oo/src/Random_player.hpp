#pragma once

#include "Player.hpp"

#include <vector>

class RandomPlayer : public Player {
  public:
    RandomPlayer(ITargetBoard& target_board);
    bool performNextMove() override;
};
