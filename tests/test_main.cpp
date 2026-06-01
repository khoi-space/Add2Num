#include "../include/MyBigNumber.h"
#include <iostream>
#include <string>

// Tip: Recommend to disable logging in Config.h for readable testing

int total_tests = 0;
int passed_tests = 0;

void assert_equal(const std::string& test_name, const std::string& expected, const std::string& actual) {
    ++total_tests;
    if (expected == actual) {
        std::cout << "\033[32m[PASSED]\033[0m " << test_name << "\n\n";
        ++passed_tests;
    } else {
        std::cout << "\033[31m[FAILED]\033[0m " << test_name << '\n';
        std::cout << " -> Expected: " << expected << '\n';
        std::cout << " -> Actual: " << actual << "\n\n";
    }
}

/* Test Group 1: Standard scenarios */
void test_happy_paths(MyBigNumber& mbn) {
    assert_equal("HappyPath - Test 1", "579", mbn.sum("123", "456"));
    assert_equal("HappyPath - Test 2", "2131", mbn.sum("1234", "897"));
}

/* Test Group 2: Edge case */
void test_edge_cases(MyBigNumber& mbn) {
    assert_equal("EdgeCase - Test 1", "1000", mbn.sum("999", "1"));
    assert_equal("EdgeCase - Test 2", "1000", mbn.sum("1", "999"));
    assert_equal("EdgeCase - Test 3", "1234", mbn.sum("1234", "0"));
    assert_equal("EdgeCase - Test 4", "1234", mbn.sum("0", "1234"));
    assert_equal("EdgeCase - Test 5", "0", mbn.sum("0", "0"));
    assert_equal("EdgeCase - Test 6", "100000000001", mbn.sum("100000000000", "1"));
}

void test_big_nums(MyBigNumber& mbn) {
    std::string big_num1(50, '9'); // 50 digits of '9'
    std::string expected1 = "1" + std::string(50, '0'); // '1' followed by 50 zeros
    assert_equal("BigNumbers - Test 1", expected1, mbn.sum(big_num1, "1"));

    std::string big_num2 = "123456789012345678901234567890";
    std::string big_num3 = "876543210987654321098765432109";
    std::string expected2 = "999999999999999999999999999999";
    assert_equal("BigNumbers - Test 2", expected2, mbn.sum(big_num2, big_num3));

    std::string big_num4 = "123456789012345678901234567891"; // big_num2 + 1
    std::string expected3 = "1000000000000000000000000000000";
    assert_equal("BigNumbers - Test 3", expected3, mbn.sum(big_num3, big_num4));
}

int main() {
    MyBigNumber mbn;

    std::cout << "=== UNIT TESTING ===\n";

    test_happy_paths(mbn);
    test_edge_cases(mbn);
    test_big_nums(mbn);

    std::cout << "\n\n====================\n";
    std::cout << "UNIT TEST REPORT:\n";

    if (passed_tests == total_tests) {
        std::cout << "SUCCESS: Passed all tests.\n";
    } else {
        std::cout << "FAIL: Only passed " << passed_tests << "/" << total_tests << "tests\n";
    }

    return (passed_tests == total_tests) ? 0 : 1;
}
