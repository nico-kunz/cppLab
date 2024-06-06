#include <catch2/catch_test_macros.hpp>

#include <sstream>
#include <numeric>

#include "util.test.hpp"
#include "Board.hpp"

TEST_CASE("board") {

    Board board(10);
    SECTION("empty board") {
        for (char c = 'A'; c < 'K'; ++c) {
            for (unsigned char r = 0; r < 10; ++r) {
                REQUIRE(board.at(c, r) == Field::WATER);
            };
        }
        REQUIRE(board.fleet_destroyed() == true);
    }
    SECTION("fire on empty board") {
        REQUIRE(board.fire('A', 0) == false);
        REQUIRE(board.fire('J', 9) == false);
        REQUIRE(board.fire('A', 0) == false);
        REQUIRE(board.fire('J', 9) == false);
        REQUIRE(board.fleet_destroyed() == true);
    }

    board.set_ship_manually('B', 3);
    board.set_ship_manually('B', 4);
    REQUIRE(board.fleet_destroyed() == false);

    REQUIRE(board.fire('A', 0) == false);

    REQUIRE(board.fire('B', 3) == true);
    REQUIRE(board.fleet_destroyed() == false);

    REQUIRE(board.fire('B', 3) == false);
    REQUIRE(board.fleet_destroyed() == false);

    REQUIRE(board.fire('B', 4) == true);
    REQUIRE(board.fleet_destroyed() == true);

    REQUIRE(board.fire('B', 4) == false);
    REQUIRE(board.fleet_destroyed() == true);
}

TEST_CASE("board random placement") {

    const std::vector<Ship> fleet = {
        Ship(5, "dreadnought"),
        Ship(4, "cruiser"),
        Ship(4, "cruiser"),
        Ship(3, "destroyer"),
        Ship(3, "destroyer"),
        Ship(3, "destroyer"),
        Ship(2, "submarine"),
        Ship(2, "submarine"),
        Ship(2, "submarine"),
        Ship(2, "submarine"),
        Ship(2, "submarine"),
    };

    constexpr size_t DIM = 10;
    Board board(DIM);

    board.place_fleet_randomly(fleet);
    size_t ship_field_count = 0;

    for (char c = 'A'; c < 'A' + DIM; ++c) {
        for (unsigned char r = 0; r < DIM; ++r) {
            if (board.at(c, r) == Field::SHIP) {
                ++ship_field_count;
            }
        }
    }

    const size_t expected_ship_field_count = std::accumulate(fleet.cbegin(), fleet.cend(), 0, [](auto acc, const auto& ship) { return acc + ship.length; });
    REQUIRE(ship_field_count == expected_ship_field_count);
}

TEST_CASE("board operator<<") {

    Board board(4);

    board.set_ship_manually('A', 0);
    board.set_ship_manually('A', 1);
    board.set_ship_manually('B', 2);
    board.set_ship_manually('C', 2);
    board.set_ship_manually('D', 2);

    board.fire('A', 1);
    board.fire('A', 2);
    board.fire('C', 2);

    std::stringstream s{};
    s << board;

    const std::string line0{ "-----------------" };
    const std::string line1{ "| S |   |   |   | 0" };
    const std::string line2{ "-----------------" };
    const std::string line3{ "| X |   |   |   | 1" };
    const std::string line4{ "-----------------" };
    const std::string line5{ "|   | S | X | S | 2" };
    const std::string line6{ "-----------------" };
    const std::string line7{ "|   |   |   |   | 3" };
    const std::string line8{ "-----------------" };
    const std::string line9{ "  A   B   C   D" };

    const std::vector<std::string> out_lines = split_string(s.str());

    REQUIRE(out_lines.size() == 10);
    REQUIRE(out_lines[0] == line0);
    REQUIRE(out_lines[1] == line1);
    REQUIRE(out_lines[2] == line2);
    REQUIRE(out_lines[3] == line3);
    REQUIRE(out_lines[4] == line4);
    REQUIRE(out_lines[5] == line5);
    REQUIRE(out_lines[6] == line6);
    REQUIRE(out_lines[7] == line7);
    REQUIRE(out_lines[8] == line8);
    REQUIRE(out_lines[9] == line9);
}
