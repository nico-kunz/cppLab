#include "strings.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Read int from segment in ip string
 * @param ip String containing ip
 * @param offset Character offset to use when reading segment
 * @param out Integer that was read from segment
 * @return -1 on error, otherwise amount of characters that were read
 */
int readSegment(const char* ip, int offset, int* out) {
    char byte[4];
    byte[3] = '\0';

    // read until dot or termination
    int i = 0 + offset;
    bool firstDigit = false;
    size_t length = strlen(ip);
    while (ip[i] != '.' && i < length) {
        if((i - offset) >= 3) {
            printf("ABORT; TOO LONG\n");
            return -1;
        }

        if(firstDigit && ip[i] == ' ') {
            printf("ABORT, WHITESPACE AFTER DIGIT\n");
            return -1;
        }

        if(ip[i] != ' ' && !isdigit(ip[i])) {
            printf("ABORT; INVALID CHAR\n");
            return -1;
        }

        if(isdigit(ip[i])) {
            firstDigit = true;
        }

        byte[i - offset] = ip[i];
        ++i;
    }

    if(i - offset == 0) {
        printf("ABORT; SEGMENT TOO SHORT\n");
        return -1;
    }

    byte[i - offset] = '\0';
    *out = atoi(byte);
    return ++i;
}

int IPStringtoInt(const char* ip, uint32_t* const ip_int) {
    uint32_t result = 0;
    int exitCode = 0;
    for(int i = 0; i < 4; ++i) {
        int segment;
        exitCode = readSegment(ip, exitCode, &segment);
        if(exitCode == -1) {
            return -1;
        }

        if(segment > 255) {
            printf("ABORT; IP SEGMENT TOO LARGE");
            return -1;
        }

        printf("bitshifted seg: %#010x\n", segment << (24 - i*8));
        result += segment << (24 - i*8);
    }

    printf("%#010x\n", result);
    *ip_int = result;
    return 0;
}

void IPInttoString(uint32_t ip, char* const ip_string) {
    int counter = 0;
    for(int i = 0; i < 4; ++i) {
        // Get int string from leftmost byte, shift by 24 since we go from left to right
        counter += sprintf(ip_string + counter, "%d", (ip >> (24 - 8*i)) & 0xFF);
        ip_string[counter] = '.';
        ++counter;
    }

    // remove last dot
    ip_string[counter-1] = '\0';
    printf("%s", ip_string);
}
