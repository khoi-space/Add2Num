#include "../include/MyBigNumber.h"
#include "../include/Config.h"
#include <iostream>
#include <algorithm>

std::string MyBigNumber::sum(std::string stn1, std::string stn2) {
    #ifdef LOGGING
    std::clog << "--- NEW LOGGING ---\n";
    std::clog << "Input: stn1 = " << stn1 << "; stn2 = " << stn2 << "\n";
    #endif

    std::string result = "";

    int idxStn1 = stn1.length() - 1; //begin at the end of string number
    int idxStn2 = stn2.length() - 1;

    int carry = 0;
    int step = 1;

    while (idxStn1 >= 0 || idxStn2 >= 0 || carry > 0) {
        #ifdef LOGGING
        std::clog << "-> STEP " << step << ": ";
        #endif

        int digit1 = (idxStn1 >= 0) ? stn1[idxStn1] - '0' : 0; // Convert character at idxStn1 into digit
        int digit2 = (idxStn2 >= 0) ? stn2[idxStn2] - '0' : 0;

        int localSum = digit1 + digit2 + carry;

        #ifdef LOGGING
        std::clog << "Do " << digit1 << " + " << digit2 << " + " << carry << " (carry)" << " = " << localSum << ". ";
        #endif

        carry = localSum / 10;
        int curResDigit = localSum % 10;
        result += std::to_string(curResDigit);

        #ifdef LOGGING
        std::clog << "Write " << curResDigit << ". ";
        std::clog << "New carry: " << carry << '\n';
        #endif

        --idxStn1;
        --idxStn2;
        ++step;
    }

    // Reserve order of character in result
    std::reverse(result.begin(), result.end());

    #ifdef LOGGING
    std::clog << "Add done." << '\n';
    std::clog << "Final result: " << result << '\n';
    std::clog << "--------------------\n";
    #endif

    return result;
}
