#include <catch2/catch_test_macros.hpp>

#include "Cheating_player.hpp"

TEST_CASE("cheating player") {
    constexpr size_t DIM = 10;

    Board target_board(DIM);
    target_board.set_ship_manually('F', 4);
    target_board.set_ship_manually('F', 5);
    target_board.set_ship_manually('F', 6);

    target_board.set_ship_manually('J', 8);
    target_board.set_ship_manually('J', 9);

    CheatingPlayer player(target_board);

    REQUIRE(player.performNextMove() == true);
    REQUIRE(player.performNextMove() == true);
    REQUIRE(player.performNextMove() == true);
    REQUIRE(player.performNextMove() == true);
    REQUIRE(player.performNextMove() == true);

    REQUIRE(target_board.fleet_destroyed() == true);
}
