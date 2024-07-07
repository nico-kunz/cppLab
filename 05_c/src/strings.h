//
// Created by flo on 3/11/24.
//
#ifndef CPPP_05_C_STRINGS_H_
#define CPPP_05_C_STRINGS_H_

#include <stdint.h>

int IPStringtoInt(const char* const ip, uint32_t* const ip_int);

void IPInttoString(uint32_t ip, char* const ip_string);

#endif
