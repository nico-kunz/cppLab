#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <cmath>

#include "Complex.hpp"

// this is required because floating point values can be imprecise,
// especially when used in combination with trigonometric functions
// std::numeric_limits<double>::epsilon() is too small here :-(
constexpr double TOL = 5e-11;

static bool is_close(Complex c1, Complex c2) {
    return ((std::abs(c1.real() - c2.real()) < TOL) && (std::abs(c1.imag() - c2.imag()) < TOL));
}

TEST_CASE("Constructors and simple getters") {
    Complex a = {};
    REQUIRE(a.real() == 0);
    REQUIRE(a.imag() == 0);

    Complex b = {4, 1};
    REQUIRE(b.real() == 4);
    REQUIRE(b.imag() == 1);
}

TEST_CASE("Arithmetic Operators") {
    SECTION("Addition") {
        Complex a = {0, 1};
        Complex b = {1, 1};
        Complex c = a + b;
        REQUIRE(std::abs(c.real() - 1) < TOL);
        REQUIRE(std::abs(c.imag() - 2) < TOL);
    }
    SECTION("Subtraction") {
        Complex a = {0, 1};
        Complex b = {1, 1};
        Complex c = a - b;
        REQUIRE(std::abs(c.real() - -1.0) < TOL);
        REQUIRE(std::abs(c.imag() - 0.0) < TOL);
    }
    SECTION("Multiplication") {
        Complex a = {0, 1};
        Complex b = {1, 1};
        Complex c = a * b;
        REQUIRE(std::abs(c.real() - -1.0) < TOL);
        REQUIRE(std::abs(c.imag() - 1.0) < TOL);
    }
    SECTION("Division") {
        Complex a = {0, 1};
        Complex b = {1, 1};
        Complex c = a / b;
        REQUIRE(std::abs(c.real() - 0.5) < TOL);
        REQUIRE(std::abs(c.imag() - 0.5) < TOL);
    }
    SECTION("Complex conjugate") {
        Complex a = {3, 4};
        Complex b = ~a;
        REQUIRE(is_close(b, {3, -4}));
    }
}

TEST_CASE("ostream output") {
    Complex m = {4, 3};
    std::ostringstream oss{};
    oss << m;
    REQUIRE(oss.str() == "4+3i");
}

TEST_CASE("Euler representation") {
    SECTION("into Euler representation"){
        Complex m = {4, 3};
        REQUIRE(std::abs(m.abs() - 5) < TOL);
        REQUIRE(std::abs(m.angle() - 0.643501108793284) < TOL);
    }
    SECTION("from Euler representation (Quadrant I)"){
        Complex m = {4, 3};
        Complex m2 = Complex::from_euler(m.abs(), m.angle());
        REQUIRE(is_close(m2, {4, 3}));
    }

    SECTION("from Euler representation (Quadrant IV)") {
        Complex m = {4, -3};
        Complex m2 = Complex::from_euler(m.abs(), m.angle());
        REQUIRE(is_close(m2, {4, -3}));
    }

    SECTION("from Euler representation (no imaginary part)") {
        Complex m = {4, 0};
        Complex m2 = Complex::from_euler(m.abs(), m.angle());
        REQUIRE(is_close(m2, {4, 0}));
    }
}
