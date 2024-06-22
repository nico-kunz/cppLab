#include <catch2/catch_test_macros.hpp>

#include <cmath>

#include "Numerik.hpp"

TEST_CASE("non-template version") {
    const auto fx = [](double x) { return x * x * x + 4 * x * x - 7 * x + 12; };

    SECTION("example from task") {
        REQUIRE(std::abs(trapz(fx, 0.0, 10.0, 20000) - 3603.33) / 3603.33 < 1e-4);
    }

    SECTION("use one single interval") {
        REQUIRE(std::abs(trapz(fx, 0.0, 10.0, 1) - (0.5 * (fx(0.0) + fx(10.0)) * 10.0)) < 1e-12);
    }
}

TEST_CASE("template version") {
    SECTION("check funktion") {
        REQUIRE(fxT<int>(0) == 12);
        REQUIRE(fxT<int>(1) == 10);
        REQUIRE(fxT<int>(2) == 22);
    }

    SECTION("double values") {
        REQUIRE(std::abs(trapz(fxT<double>, 0.0, 10.0, 20000) - 3603.33) / 3603.33 < 1e-4);
        REQUIRE(std::abs(trapzT<double>(fxT<double>, 0.0, 10.0, 20000) - 3603.33) / 3603.33 < 1e-4);
    }

    SECTION("float values") {
        REQUIRE(std::abs(trapzT<float>(fxT<float>, 0.0, 10.0, 20000) - 3603.33) / 3603.33 < 1e-2);
    }

    SECTION("int values") {
        REQUIRE(std::abs((double)trapzT<int>(fxT<int>, 0, 10, 10) - 3603.33) / 3603.33 < 5e-2);
    }
}
