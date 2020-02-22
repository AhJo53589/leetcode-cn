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
	std::string check = (a == b) ? "" : "\t\t\t\t\t\t\t\t WRONG ANSWER";
	return "-- OUTPUT --\n" + a + "\n-- ANSWER --\n" + b + "\n" + check;
}

#endif //COMMON_H


