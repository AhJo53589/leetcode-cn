#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

#include "StringConvert.h"
#include "TestCases.h"


//////////////////////////////////////////////////////////////////////////
template<typename T>
void printVectorT(T &nums, int width = 1, char pattern = ',')
{
    for (auto i : nums) std::cout << std::setw(width) << i << pattern;
    std::cout << std::endl;
}

template<typename T>
void printVectorVectorT(T& matrix, int width = 1, char pattern = ',')
{
    for (auto n : matrix) printVectorT(n, width, pattern);
    std::cout << std::endl;
}

//////////////////////////////////////////////////////////////////////////
template<typename T>
inline std::string checkAnswer(T ta, T tb)
{
    std::string a = convert<std::string>(ta);
    std::string b = convert<std::string>(tb); 
    std::string check = (a == b) ? "" : "\t\t\t\t\t\t\t\t\t\t## WRONG ANSWER ##";
    return "-- OUTPUT --\n" + a + "\n-- ANSWER --\n" + b + "\n" + check;
}


template<typename T>
inline void _checkAnswer_custom_sort(T& ans, TestCases& tc)
{
    T answer = tc.get<T>();
    std::sort(ans.begin(), ans.end());
    std::sort(answer.begin(), answer.end());
    std::cout << checkAnswer<decltype(ans)>(ans, answer) << std::endl;
}

#endif //COMMON_H
