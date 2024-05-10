
#include <catch2/catch_test_macros.hpp>
#include "GameOfLife.hpp"

TEST_CASE("Iterate") {
    Universe f{ { { new Colony(false), new Colony(true), new Colony(false) },
        { new Colony(false), new Colony(true), new Colony(false) },
        { new Colony(false), new Colony(true), new Colony(false) } } };

    GameOfLife g = GameOfLife(f);

    // f must be emptied
    REQUIRE(f.empty());

    g.iterate();
    REQUIRE_FALSE(g.getColonies().at(0).at(0)->getState());
    REQUIRE_FALSE(g.getColonies().at(0).at(1)->getState());
    REQUIRE_FALSE(g.getColonies().at(0).at(2)->getState());
    REQUIRE(g.getColonies().at(1).at(0)->getState());
    REQUIRE(g.getColonies().at(1).at(1)->getState());
    REQUIRE(g.getColonies().at(1).at(2)->getState());
    REQUIRE_FALSE(g.getColonies().at(2).at(0)->getState());
    REQUIRE_FALSE(g.getColonies().at(2).at(1)->getState());
    REQUIRE_FALSE(g.getColonies().at(2).at(2)->getState());
}

TEST_CASE("Copy-Constructor") {
    Universe f{ { { new Colony(false), new Colony(true), new Colony(false) },
        { new Colony(false), new Colony(true), new Colony(false) },
        { new Colony(false), new Colony(true), new Colony(false) } } };

    GameOfLife g = GameOfLife(f);
    GameOfLife g2 {g};

    g2.iterate();

    // g must be unaltered
    REQUIRE_FALSE(g.getColonies().at(0).at(0)->getState());
    REQUIRE(g.getColonies().at(0).at(1)->getState());
    REQUIRE_FALSE(g.getColonies().at(0).at(2)->getState());
    REQUIRE_FALSE(g.getColonies().at(1).at(0)->getState());
    REQUIRE(g.getColonies().at(1).at(1)->getState());
    REQUIRE_FALSE(g.getColonies().at(1).at(2)->getState());
    REQUIRE_FALSE(g.getColonies().at(2).at(0)->getState());
    REQUIRE(g.getColonies().at(2).at(1)->getState());
    REQUIRE_FALSE(g.getColonies().at(2).at(2)->getState());

    // g2 must be iterated
    REQUIRE_FALSE(g2.getColonies().at(0).at(0)->getState());
    REQUIRE_FALSE(g2.getColonies().at(0).at(1)->getState());
    REQUIRE_FALSE(g2.getColonies().at(0).at(2)->getState());
    REQUIRE(g2.getColonies().at(1).at(0)->getState());
    REQUIRE(g2.getColonies().at(1).at(1)->getState());
    REQUIRE(g2.getColonies().at(1).at(2)->getState());
    REQUIRE_FALSE(g2.getColonies().at(2).at(0)->getState());
    REQUIRE_FALSE(g2.getColonies().at(2).at(1)->getState());
    REQUIRE_FALSE(g2.getColonies().at(2).at(2)->getState());
}

TEST_CASE("Read Write") {
    GameOfLife g = GameOfLife::readFromFile("../test.txt");
    REQUIRE(g.getX_SIZE() == 3);
    REQUIRE(g.getY_SIZE() == 3);
    REQUIRE(g.getColonies()[0][0]->getState() == false);
    REQUIRE(g.getColonies()[0][1]->getState() == true);
    REQUIRE(g.getColonies()[0][2]->getState() == false);
    REQUIRE(g.getColonies()[1][0]->getState() == true);
    REQUIRE(g.getColonies()[1][1]->getState() == true);
    REQUIRE(g.getColonies()[1][2]->getState() == false);
    REQUIRE(g.getColonies()[2][0]->getState() == false);
    REQUIRE(g.getColonies()[2][1]->getState() == true);
    REQUIRE(g.getColonies()[2][2]->getState() == true);

    g.writeToFile("../test_write.txt");

    GameOfLife g2 = GameOfLife::readFromFile("../test_write.txt");
    REQUIRE(g2.getX_SIZE() == 3);
    REQUIRE(g2.getY_SIZE() == 3);
    REQUIRE(g2.getColonies()[0][0]->getState() == false);
    REQUIRE(g2.getColonies()[0][1]->getState() == true);
    REQUIRE(g2.getColonies()[0][2]->getState() == false);
    REQUIRE(g2.getColonies()[1][0]->getState() == true);
    REQUIRE(g2.getColonies()[1][1]->getState() == true);
    REQUIRE(g2.getColonies()[1][2]->getState() == false);
    REQUIRE(g2.getColonies()[2][0]->getState() == false);
    REQUIRE(g2.getColonies()[2][1]->getState() == true);
    REQUIRE(g2.getColonies()[2][2]->getState() == true);
}
