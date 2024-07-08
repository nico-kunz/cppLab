#include "registers.h"
#include "strings.h"

int main(int argc, char** argv) {
    uint32_t result;
    char str[16];
    IPInttoString(0x7f000001, str);
    return 0;
}
