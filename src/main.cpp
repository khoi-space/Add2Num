#include "../include/MyBigNumber.h"
#include <iostream>

int main() {
    MyBigNumber mbn;

    std::string stn1 = "1234";
    std::string stn2 = "329";

    std::string result = mbn.sum(stn1, stn2);

    return 0;
}