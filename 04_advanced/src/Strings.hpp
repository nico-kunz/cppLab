#pragma once

#include <map>
#include <sstream>
#include <string>
#include <vector>

size_t countDigits(const std::string &input);

std::map<int, std::string> buildIdStringMap(const std::vector<std::string> &input);

bool isPalindrome(const std::string &input);
size_t countPalindromes(const std::string &input);

class StringSplitter {
  public:
    StringSplitter(char sep, std::vector<std::string> &target);

    ~StringSplitter();

    void operator()(char c);

    void flush();

  private:
    char m_sep;
    std::string m_str;
    std::vector<std::string> &m_output;
    void pushBackNonEmpty();
};
