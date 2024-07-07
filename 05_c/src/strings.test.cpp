#include <catch2/catch_test_macros.hpp>

#include <cstring>

#include "util.strings.test.hpp"

TEST_CASE("String to Int") {
    test_str2int_valid("8.8.8.8", 0x08080808);
    test_str2int_valid("127.0.255.1", 0x7f00ff01);

    test_str2int_valid("127.0.0.1", 0x7F000001);
    test_str2int_valid("127.000.000.001", 0x7F000001);
    test_str2int_valid("127.0.0.01", 0x7F000001);
    test_str2int_valid("127.  0.  0.  1", 0x7F000001);
}

TEST_CASE("String to Int Faults") {
    test_str2int_invalid("172.0.1");
    test_str2int_invalid("172.0.866.444");

    test_str2int_invalid("127.   1.   1.   1");
    test_str2int_invalid("127.0001.0001.0001");
    test_str2int_invalid("Dies ist eine IP-Adresse");
    test_str2int_invalid("127.0.0.1#IP-Adresse");
}

TEST_CASE("Int to String") {
    test_int2str(0xF12F6606, "241.47.102.6");
}
