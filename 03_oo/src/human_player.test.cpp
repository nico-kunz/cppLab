#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <sstream>

#include "util.test.hpp"
#include "Human_player.hpp"

TEST_CASE("human player") {
    SECTION("valid input") {
        constexpr size_t DIM = 10;

        Board target_board(DIM);
        target_board.set_ship_manually('F', 4);
        target_board.set_ship_manually('F', 5);

        HumanPlayer player(target_board);

        std::streambuf* orig = std::cin.rdbuf();
        std::istringstream input("F4\nE4\nF5");
        std::cin.rdbuf(input.rdbuf());

        REQUIRE(player.performNextMove() == true);
        REQUIRE(player.performNextMove() == false);
        REQUIRE(player.performNextMove() == true);

        REQUIRE(target_board.fleet_destroyed() == true);

        std::cin.rdbuf(orig);
    }
}

TEST_CASE("human player output board") {
    constexpr size_t DIM = 4;

    Board target_board(DIM);
    target_board.set_ship_manually('B', 0);
    target_board.set_ship_manually('B', 1);
    target_board.set_ship_manually('C', 3);
    target_board.set_ship_manually('D', 3);

    HumanPlayer player(target_board);

    std::streambuf* orig_in = std::cin.rdbuf();

    std::istringstream input("B3\nB1\nC1\nC3");
    std::cin.rdbuf(input.rdbuf());

    player.performNextMove();
    player.performNextMove();
    player.performNextMove();
    player.performNextMove();

    std::cin.rdbuf(orig_in);

    std::streambuf* orig_out = std::cout.rdbuf();
    std::ostringstream output{};
    std::cout.rdbuf(output.rdbuf());

    player.print_result_map();

    std::cout.rdbuf(orig_out);

    const std::vector<std::string> out_lines = split_string(output.str());

    const std::string line0{ "-----------------" };
    const std::string line1{ "|   |   |   |   | 0" };
    const std::string line2{ "-----------------" };
    const std::string line3{ "|   | X | ~ |   | 1" };
    const std::string line4{ "-----------------" };
    const std::string line5{ "|   |   |   |   | 2" };
    const std::string line6{ "-----------------" };
    const std::string line7{ "|   | ~ | X |   | 3" };
    const std::string line8{ "-----------------" };
    const std::string line9{ "  A   B   C   D" };

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
