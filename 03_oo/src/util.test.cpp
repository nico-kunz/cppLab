#include <catch2/catch_test_macros.hpp>

#include "util.test.hpp"

void set_ships_on_every_field(Board& board) {
    for (char col = 'A'; col < 'A' + board.dim(); ++col) {
        for (unsigned char row = 0; row < board.dim(); ++row) {
            board.set_ship_manually(col, row);
        }
    }
}

static void rtrim(std::string& s) {
    const size_t pos = s.find_last_not_of(" \t\n\r");

    if (pos == std::string::npos) {
        s.clear();
    }
    else if (pos + 1 < s.size()) {
        s.erase(pos + 1);
    }
}

std::vector<std::string> split_string(const std::string& s) {
    std::vector<std::string> v{};

    size_t pos = 0;

    while (pos != std::string::npos) {
        const size_t start_pos = s.find_first_not_of("\n\r", pos);
        if (start_pos == std::string::npos) {
            break;
        }
        const size_t end_pos = s.find_first_of("\n\r", start_pos);

        std::string str = s.substr(start_pos, end_pos - start_pos);
        rtrim(str);

        v.push_back(str);

        pos = end_pos;
    }

    return v;
}