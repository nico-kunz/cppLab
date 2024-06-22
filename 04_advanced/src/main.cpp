#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

#include "Strings.hpp"
#include "Numerik.hpp"

int main(int argc, char** argv) {
    const std::string tosplit = "A|B|C";
    const char sep = '|';
    std::vector<std::string> output;
    StringSplitter splitter(sep, output);
    std::for_each(tosplit.cbegin(), tosplit.cend(), [&](char c) { splitter(c); });
    splitter.flush();

    std::for_each(output.begin(), output.end(), [](auto str){std::cout << str << std::endl;});
    return 0;
}
