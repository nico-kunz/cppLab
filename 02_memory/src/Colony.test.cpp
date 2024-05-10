#include <catch2/catch_test_macros.hpp>
#include "Colony.hpp"

TEST_CASE("Colony") {
    Colony x(true);
    for (int i = 0; i < 9; i++) {
        x = Colony(true);
        x.calculateNextState(i);
        x.evolve();
        if (i == 2 || i == 3) {
            REQUIRE(x.getState());
        } else {
            REQUIRE_FALSE(x.getState());
        }
    }
}