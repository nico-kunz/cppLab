#pragma once

#include "Board.hpp"
#include "Player.hpp"

class CheatingPlayer : public Player {
  public:
    CheatingPlayer(ITargetBoard& target_board);
    virtual bool performNextMove() override;
};
