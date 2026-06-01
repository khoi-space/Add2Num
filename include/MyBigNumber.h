#ifndef MY_BIG_NUMBER_H
#define MY_BIG_NUMBER_H

#include <string>

class MyBigNumber {
public:
    /**
     * @brief : Add 2 numbers (in std::string type)
     * @param stn1 : The first number
     * @param stn2 : The second number
     * @return std::string : The result of add 2 numbers above
     */
    std::string sum(std::string stn1, std::string stn2);
};

#endif // MY_BIG_NUMBER_H