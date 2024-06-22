#include <catch2/catch_test_macros.hpp>
#include <iostream>

#include "Strings.hpp"

TEST_CASE("countDigits") {
    SECTION("count Numbers (examples task)") {
        REQUIRE(countDigits("123") == 3);
        REQUIRE(countDigits("abc") == 0);
        REQUIRE(countDigits("ab34yz_34") == 4);
    }
}

TEST_CASE("buildIdStringMap") {
    SECTION("examples 1") {
        const std::vector<std::string> input = { "1abc", "2abc", "3abc" };
        const std::map<int, std::string> result = { { 1, "abc" }, { 2, "abc" }, { 3, "abc" } };
        REQUIRE(buildIdStringMap(input) == result);
    }
    SECTION("example task 1") {
        const std::vector<std::string> input = {};
        const std::map<int, std::string> result = {};
        REQUIRE(buildIdStringMap(input) == result);
    }
    SECTION("example task 2") {
        const std::vector<std::string> input = { "12abc", "222abc", "3c++", "4programmierung" };
        const std::map<int, std::string> result = { { 12, "abc" }, { 222, "abc" }, { 3, "c++" }, { 4, "programmierung" } };
        REQUIRE(buildIdStringMap(input) == result);
    }
    SECTION("example task 3") {
        const std::vector<std::string> input = { "12abc", "222abc", "3 c++", "4programmierung " };
        const std::map<int, std::string> result = { { 12, "abc" }, { 222, "abc" }, { 3, " c++" }, { 4, "programmierung " } };
        REQUIRE(buildIdStringMap(input) == result);
    }
    SECTION("example task 4") {
        const std::vector<std::string> input = { "12abc", "222" };
        const std::map<int, std::string> result = { { 12, "abc" }, { 222, "" } };
        REQUIRE(buildIdStringMap(input) == result);
    }
    SECTION("example task 5") {
        const std::vector<std::string> input = { "12abc", "222abc", "abc", "4programmierung" };
        REQUIRE_THROWS_AS(buildIdStringMap(input), std::runtime_error);
    }
    SECTION("example task 6") {
        const std::vector<std::string> input = { "12abc", "222abc", "", "4programmierung" };
        REQUIRE_THROWS_AS(buildIdStringMap(input), std::runtime_error);
    }
    SECTION("example task 7") {
        const std::vector<std::string> input = { "12abc", "222abc", " 3c++", "4programmierung" };
        REQUIRE_THROWS_AS(buildIdStringMap(input), std::runtime_error);
    }
    SECTION("example task 8") {
        const std::vector<std::string> input = { "12abc", "12abc" };
        REQUIRE_THROWS_AS(buildIdStringMap(input), std::runtime_error);
    }
}

TEST_CASE("Palindroms") {
    SECTION("isPalindrome") {
        REQUIRE(isPalindrome("123") == false);
        REQUIRE(isPalindrome("aba") == true);
        REQUIRE(isPalindrome(" aba") == false);
        REQUIRE(isPalindrome("Aba") == true);
        REQUIRE(isPalindrome("a") == false);
    }

    SECTION("countPalindromes (examples from task)") {
        REQUIRE(countPalindromes("123") == 0);
        REQUIRE(countPalindromes("Otto") == 2);
        REQUIRE(countPalindromes("tto") == 1);
        REQUIRE(countPalindromes("OTtotto") == 7);
    }

    SECTION("countPalindromes") {
        REQUIRE(countPalindromes("Radar") == 2);
    }

    SECTION("countPalindromes with spaces") {
        REQUIRE(countPalindromes(" Radar") == 2);
        int t = countPalindromes("abcdefghijklmnopqrstuvwxyz1234567890wowowowoqkeoqwkdjiofweiofgjwenuioffnuiesfnsuilfnfueislfneusifneuenfisuenflsieufnfliusnfseiunffoiunewjgfoiewfoijdkwqoekqowowowow0987654321zyxwvutsrqponmlkjihgfedcba");
        std::cout << "PALINDROMES: " << t << std::endl;
    }
}

TEST_CASE("StringSplitter") {

    SECTION("example task 1") {
        const char sep = '|';
        const std::string tosplit = "A|B|C|";
        std::vector<std::string> output;
        StringSplitter splitter(sep, output);

        for (char c : tosplit) {
            splitter(c);
        }

        std::vector<std::string> expected_output = { "A", "B", "C" };
        REQUIRE(output == expected_output);
    }

    SECTION("example task 2") {
        const char sep = '|';
        const std::string tosplit = "A|B|C";
        std::vector<std::string> output;
        StringSplitter splitter(sep, output);

        for (char c : tosplit) {
            splitter(c);
        }
        splitter.flush();

        const std::vector<std::string> expected_output = { "A", "B", "C" };
        REQUIRE(output == expected_output);
    }

    SECTION("example task 3") {
        const char sep = '|';
        const std::string tosplit = "A|B|C";
        std::vector<std::string> output;
        StringSplitter splitter(sep, output);

        for (char c : tosplit) {
            splitter(c);
        }

        const std::vector<std::string> expected_output = { "A", "B" };
        REQUIRE(output == expected_output);
    }

    SECTION("example task 4") {
        const char sep = '|';
        const std::string tosplit = "AB|C|";
        std::vector<std::string> output;
        StringSplitter splitter(sep, output);

        for (char c : tosplit) {
            splitter(c);
        }

        const std::vector<std::string> expected_output = { "AB", "C" };
        REQUIRE(output == expected_output);
    }

    SECTION("example task 5") {
        const char sep = '|';
        const std::string tosplit = "|C|||D|";
        std::vector<std::string> output;
        StringSplitter splitter(sep, output);

        for (char c : tosplit) {
            splitter(c);
        }

        const std::vector<std::string> expected_output = { "C", "D" };
        REQUIRE(output == expected_output);
    }

    SECTION("example task 6") {
        const char sep = '|';
        const std::string tosplit = "AB";
        std::vector<std::string> output;
        StringSplitter splitter(sep, output);

        for (char c : tosplit) {
            splitter(c);
        }
        splitter.flush();

        const std::vector<std::string> expected_output = { "AB" };
        REQUIRE(output == expected_output);
    }

    SECTION("example task 7") {
        const char sep = '|';
        std::vector<std::string> output;
        StringSplitter splitter(sep, output);

        splitter('A');
        splitter('B');
        splitter('|');
        splitter('C');
        splitter.flush();
        splitter('D');
        splitter('|');

        const std::vector<std::string> expected_output = { "AB", "C", "D" };
        REQUIRE(output == expected_output);
    }
}
