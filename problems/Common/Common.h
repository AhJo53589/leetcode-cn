#ifndef COMMON_H
#define COMMON_H

#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

using namespace std;


std::vector<std::string> split(std::string str, std::string pattern);

vector<char> StringToVectorChar(string str);
vector<string> StringToVectorString(string str);

vector<int> StringToVectorInt(string str);
string VectorIntToString(vector<int>& nums);
vector<vector<int>> StringToVectorVectorInt(string str);
string VectorVectorIntToString(vector<vector<int>>& matrix);

void printVectorVectorInt(vector<vector<int>>& matrix);
void printVectorInt(vector<int>& nums);


template<typename T>
inline string checkAnswer(T a, T b)
{
	string check = (a == b) ? "" : "\t\t\t WRONG!";
	return "Result = " + to_string(a) + "\t <== " + to_string(b) + check;
}

template<>
inline string checkAnswer(bool a, bool b)
{
	string res;
	res += "Result = ";
	res += a ? "true" : "false";
	res += "\t <== ";
	res += b ? "true" : "false";
	res += (a == b) ? "" : "\t\t\t WRONG!";
	return res;
}

template<>
inline string checkAnswer(vector<vector<int>> &a, vector<vector<int>> &b)
{
	string check = (a == b) ? "" : "\t\t\t WRONG!";
	return "Result = " + VectorVectorIntToString(a) + "\t <== " + VectorVectorIntToString(b) + check;
}

template<>
inline string checkAnswer(vector<string> a, vector<string> b)
{
	string check = (a == b) ? "" : "\t\t\t WRONG!";
	string res = "Result = ";
	for (auto &s : a) res += s + ", ";
	res += "\n";
	for (auto &s : b) res += s + ", ";
	res += "\n";
	res += "\t\t\t" + check;
	return res;
}

#endif //COMMON_H

