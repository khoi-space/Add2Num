#include "../include/MyBigNumber.h"
#include "../include/Config.h"
#include <iostream>
#include <string>
#include <chrono>

// Tip: Recommend to disable logging in Config.h for readable testing

int total_tests = 0;
int passed_tests = 0;

void assert_equal(const std::string& test_name, const std::string& expected, const std::string& actual) {
    ++total_tests;
    if (expected == actual) {
        std::cout << "\033[32m[PASSED]\033[0m " << test_name << "\n";
        ++passed_tests;
    } else {
        std::cout << "\033[31m[FAILED]\033[0m " << test_name << '\n';
        std::cout << " -> Expected: " << expected << '\n';
        std::cout << " -> Actual: " << actual << "\n";
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

/* Test Group 3: So large number */
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

/* Test Group 4: Test coverage paths*/
void test_coverage_paths(MyBigNumber& mbn) {
    assert_equal("Coverage - Same length with continuous carry", "1110", mbn.sum("555", "555"));
    
    assert_equal("Coverage - Empty string 1", "123", mbn.sum("", "123"));
    assert_equal("Coverage - Empty string 2", "123", mbn.sum("123", ""));
    assert_equal("Coverage - Both strings empty", "", mbn.sum("", ""));

    assert_equal("Coverage - Leading zeros", "105", mbn.sum("009", "0096"));
}

/* Test Group 5: Stress Test (Very very large number) */
#ifdef STRESS_TEST
std::string genLargeNumFixed(size_t numSize, char ch) {
    if (numSize == 0) return "";
    return std::string(numSize, ch);
}

std::string genLargeNumPattern(size_t numSize, std::string pattern) {
    std::string num = "";
    num.reserve(numSize);

    while (num.length() < numSize) {
        num += pattern;
    }

    // Cut the overhead numSize part
    return num.substr(0, numSize);
}

void stress_test(MyBigNumber& mbn) {
    std::string num1 = "";
    std::string num2 = "";
    std::string expected = "";

    auto start = std::chrono::high_resolution_clock::now();

    // Test 1: Same number with 10,000 digits
    num1 = genLargeNumPattern(10000, "1234567890");
    num2 = num1;
    expected.reserve(10000);
    for (int i = 0; i < 1000; ++i) expected += "2469135780"; // "1234567890" * 2
    assert_equal("StressTest - Fixed Pattern (10,000 digits)", expected, mbn.sum(num1, num2));

    // Test 2
    num1 = genLargeNumFixed(20000, '1');
    num2 = "9";
    expected = genLargeNumFixed(19998, '1') + "20";
    assert_equal("StressTest - Fixed (1 vs 20,000 digits)", expected, mbn.sum(num1, num2));

    // Test 3
    num1 = genLargeNumFixed(15000, '9');
    num2 = "1";
    expected = "1" + genLargeNumFixed(15000, '0');
    assert_equal("StressTest - Fixed (15,000 digits of '9')", expected, mbn.sum(num1, num2));

    // Test 4
    num1 = genLargeNumFixed(15000, '0') + genLargeNumFixed(15000, '5');
    num2 = "0";
    expected = genLargeNumFixed(15000, '5');
    assert_equal("StressTest - Fixed Massive Leading Zeros (30,000 digits)", expected, mbn.sum(num1, num2));

    // Test 5
    num1 = genLargeNumFixed(10000000, '1');
    num2 = num1;
    expected = genLargeNumFixed(10000000, '2');
    assert_equal("StressTest - 10,000,000 digits", expected, mbn.sum(num1, num2));


    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "\n>>> TOTAL STRESS TEST TIME: " << duration.count() << " ms <<<\n";
}
#endif

int main() {
    MyBigNumber mbn;

    std::cout << "\n=== UNIT TESTING ===\n";

    test_happy_paths(mbn);
    test_edge_cases(mbn);
    test_big_nums(mbn);
    test_coverage_paths(mbn);
    #ifdef STRESS_TEST
    stress_test(mbn);
    #endif
    std::cout << "====================\n";
    

    std::cout << "\n========= UNIT TEST REPORT ===========\n";

    if (passed_tests == total_tests) {
        std::cout << "\033[32m[SUCCESS]\033[0m: Passed all tests.\n";
    } else {
        std::cout << "\033[31m[FAIL]\033[0m: Only passed " << passed_tests << "/" << total_tests << " tests\n";
    }

    std::cout << "======================\n";

    return (passed_tests == total_tests) ? 0 : 1;
}
