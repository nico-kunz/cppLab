#include "Strings.hpp"
#include <algorithm>
#include <iostream>

size_t countDigits(const std::string &input) {
    return std::count_if(input.begin(), input.end(), [](char c) { return std::isdigit(c); });
}

std::map<int, std::string> buildIdStringMap(const std::vector<std::string> &input) {
    std::map<int, std::string> result;

    for (const auto &str : input) {
        size_t pos;

        // throw if string starts with whitespace
        if (!str.empty() && str.at(0) == ' ') {
            throw std::runtime_error("String cannot start with whitespace");
        }

        try {
            const int id{std::stoi(str, &pos)};

            // throw if key already exists
            if (result.find(id) != result.end()) {
                throw std::runtime_error("Key already exists in map");
            }

            result[id] = str.substr(pos);
        } catch (std::exception &e) {
            // pass through exceptions as runtime exception
            throw std::runtime_error(e.what());
        }
    }

    return result;
}

bool isPalindrome(const std::string &input) {
    if(input.length() < 2) {
        return false;
    }

    int left = 0;
    int right = input.length() - 1;

    while (left < right) {
        if(tolower(input[left]) != tolower(input[right])) {
            return false;
        }

        ++left;
        --right;
    }

    return true;
}

size_t countPalindromes(const std::string &input) {
    int count = 0;

    for(int len = 2; len <= input.length(); ++len) {
        for(int i = 0; i <= input.length() - len; ++i) {
            auto substr = input.substr(i, len);
            if(isPalindrome(substr)) {
                ++count;
            }
        }
    }

    return count;
}

StringSplitter::StringSplitter(char sep, std::vector<std::string> &target) : m_sep(sep), m_output(target) {
    m_str = "";
}

StringSplitter::~StringSplitter() {
    flush();
}

void StringSplitter::operator()(char c) {
    if(c == m_sep) {
        flush();
        return;
    }

    m_str += c;
}

void StringSplitter::flush() {
    if(m_str.empty()) {
        return;
    }

    m_output.push_back(m_str);
    m_str = "";
}

