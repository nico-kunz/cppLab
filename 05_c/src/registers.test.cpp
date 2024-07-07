#include <catch2/catch_test_macros.hpp>

extern "C" {
#include "registers.h"
}

TEST_CASE("registers (bitwise)") {
    const Register_t original = 0xa14c99f7;
    const Register_t expected = 0x9ec0d9f7;

    Register_t copy = original;
    setupADC(&copy);
    REQUIRE(copy == expected);
}

TEST_CASE("registers (struct)") {
    const Register_t original = 0xa14c99f7;
    const Register_t expected = 0x9ec0d9f7;

    Register_t copy = original;
    setupADC_Struct(&copy);
    REQUIRE(copy == expected);
}

TEST_CASE("registers (preprocessor)") {
    const Register_t original = 0xa14c99f7;

#ifdef FAST_ADC
    const Register_t expected = 0x8fc0d9f7;
#else
    const Register_t expected = 0x9ec0d9f7;
#endif

    Register_t copy = original;
    setupADC_CompileOption(&copy);
    REQUIRE(copy == expected);
}
