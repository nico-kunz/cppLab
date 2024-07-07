#include <catch2/catch_test_macros.hpp>

#include "util.strings.test.hpp"

extern "C" {
#include "strings.h"
}

void test_int2str(const uint32_t ip, const char* const expected) {
    // add four sentinel bytes at the end
    char out[4 * 3 + 3 + 1 + 4];
    memset(out, 42, sizeof(out));

    IPInttoString(ip, out);

    REQUIRE(strcmp(out, expected) == 0);

    // check if functions wrote over the allowed range
    REQUIRE(out[16] == 42);
    REQUIRE(out[17] == 42);
    REQUIRE(out[18] == 42);
    REQUIRE(out[19] == 42);
}

void test_str2int_valid(const char* const ip, const uint32_t expected) {
    char* const ip_backup = (char*)malloc(strlen(ip));
    strcpy(ip_backup, ip);

    uint32_t out = (expected == 0) ? 42 : 0;
    REQUIRE(IPStringtoInt(ip, &out) == 0);
    REQUIRE(out == expected);

    // as ip should be created in the read-only section, it should crash if the function
    // changes the input string, but for good measure:
    REQUIRE(strcmp(ip_backup, ip) == 0);
    free(ip_backup);
}

void test_str2int_invalid(const char* const ip) {
    char* const ip_backup = (char*)malloc(strlen(ip) + 1);
    strcpy(ip_backup, ip);

    const uint32_t sentinel = (*ip > 127) ? 42 : 0;
    uint32_t out = sentinel;
    REQUIRE(IPStringtoInt(ip, &out) == -1);
    // in case of an invalid ip string, out must not be altered
    REQUIRE(out == sentinel);

    // as ip should be created in the read-only section, it should crash if the function
    // changes the input string, but for good measure:
    REQUIRE(strcmp(ip_backup, ip) == 0);
    free(ip_backup);
}
