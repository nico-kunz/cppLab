#pragma once

#include <cstdint>

void test_int2str(const uint32_t ip, const char* const expected);

void test_str2int_valid(const char* const ip, const uint32_t expected);
void test_str2int_invalid(const char* const ip);
