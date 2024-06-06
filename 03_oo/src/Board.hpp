#pragma once

#include <algorithm>
#include <ostream>
#include <stdexcept>
#include <vector>

struct Ship {
    size_t length;
    std::string type;

    Ship(size_t length, std::string type) : length(length), type(type) {}
};

enum class Field {
    SHIP,
    WATER,
    HIT
};

class ITargetBoard {
  public:
    virtual bool fire(char col, unsigned char row) = 0;
    virtual bool fleet_destroyed() const = 0;
    virtual size_t dim() const = 0;
};

class Board : public ITargetBoard {
  public:
    Board(size_t dim) {}

    void place_fleet_randomly(const std::vector<Ship>& fleet);
    void place_fleet_manually(const std::vector<Ship>& fleet);

    size_t dim() const override { return 0; }

    virtual bool fire(char col, unsigned char row) override {
        return false;
    }

    virtual bool fleet_destroyed() const override {
        return true;
    }

    Field at(char col, unsigned char row) const {
        return Field::WATER;
    }

    void set_ship_manually(char col, unsigned char row) {}

  private:
};

std::ostream& operator<<(std::ostream& os, const Board& board);
