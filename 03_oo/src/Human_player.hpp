#pragma once

#include "Board.hpp"
#include "Player.hpp"

class HumanPlayer : public Player {
  public:
    HumanPlayer(ITargetBoard& target_board);
    virtual bool performNextMove() override;
};
