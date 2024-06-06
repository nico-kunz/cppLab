#include <catch2/catch_test_macros.hpp>
#include "util.test.hpp"

#include "Random_player.hpp"

TEST_CASE("random player") {
    SECTION("test single move") {
        constexpr size_t DIM = 10;

        Board target_board(DIM);
        set_ships_on_every_field(target_board);

        RandomPlayer randomPlayer(target_board);

        for (size_t i = 0; i < DIM * DIM; ++i) {
            randomPlayer.performNextMove();
        }

        REQUIRE(target_board.fleet_destroyed() == true);
    }
}
