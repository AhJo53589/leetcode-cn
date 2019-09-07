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
vector<vector<char>> StringToVectorVectorChar(string str);
vector<string> StringToVectorString(string str);

vector<int> StringToVectorInt(string str);
string VectorIntToString(const vector<int>& nums);
vector<vector<int>> StringToVectorVectorInt(string str);
string VectorVectorIntToString(const vector<vector<int>>& matrix);


template<typename T>
void printVectorT(T &nums)
{
	for (auto i : nums) cout << i << ",";
	cout << endl;
}

template<typename T>
void printVectorVectorT(T &matrix)
{
	for (auto n : matrix) printVectorT(n);
	cout << endl;
}

template<typename T>
inline string checkAnswer(T a, T b)
{
	string check = (a == b) ? "" : "\t\t\t WRONG!";
	return "Result = " + to_string(a) + "\t <== " + to_string(b) + check;
}

template<>
inline string checkAnswer(const string a, const string b)
{
	string check = (a == b) ? "" : "\t\t\t WRONG!";
	return "Result = " + a + "\t <== " + b + check;
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
inline string checkAnswer(const vector<int> a, const vector<int> b)
{
	string check = (a == b) ? "" : "\t\t\t WRONG!";
	return "Result = \n" + VectorIntToString(a) + "\n" + VectorIntToString(b) + "\n" + check;
}

template<>
inline string checkAnswer(const vector<vector<int>> a, const vector<vector<int>> b)
{
	string check = (a == b) ? "" : "\t\t\t WRONG!";
	return "Result = \n" + VectorVectorIntToString(a) + "\n" + VectorVectorIntToString(b) + "\n" + check;
}

template<>
inline string checkAnswer(const vector<string> a, const vector<string> b)
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


