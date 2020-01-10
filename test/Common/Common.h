#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

#include "StringConvert.h"

using namespace std;


//////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////
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
	return "Result = \n" + a + "\n\n" + b + "\n" + check;
}

template<>
inline string checkAnswer(TreeNode* a, TreeNode* b)
{
	string stra = TreeNodeToString(a);
	string strb = TreeNodeToString(b);
	return checkAnswer(stra, strb);
}

template<>
inline string checkAnswer(vector<TreeNode*> a, vector<TreeNode*> b)
{
	string stra = "";
	for (const auto t : a)
	{
		stra += "\n";
		stra += TreeNodeToString(t);
	}
	stra += "\n";
	string strb = "";
	for (const auto t : b)
	{
		strb += "\n";
		strb += TreeNodeToString(t);
	}
	strb += "\n";
	return checkAnswer(stra, strb);
}

template<>
inline string checkAnswer(ListNode* a, ListNode* b)
{
	string stra = ListNodeToString(a);
	string strb = ListNodeToString(b);
	return checkAnswer(stra, strb);
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
inline string checkAnswer(const vector<char> a, const vector<char> b)
{
	string check = (a == b) ? "" : "\t\t\t WRONG!";
	return "Result = \n" + VectorCharToString(a) + "\n" + VectorCharToString(b) + "\n" + check;
}

template<>
inline string checkAnswer(const vector<vector<char>> a, const vector<vector<char>> b)
{
	string check = (a == b) ? "" : "\t\t\t WRONG!";
	return "Result = \n" + VectorVectorCharToString(a) + "\n" + VectorVectorCharToString(b) + "\n" + check;
}

template<>
inline string checkAnswer(const vector<string> a, const vector<string> b)
{
	string check = (a == b) ? "" : "\t\t\t WRONG!";
	string res = "Result = \n";
	res += VectorStringToString(a);
	res += "\n";
	res += VectorStringToString(b);
	res += "\n";
	res += "\t\t\t" + check;
	return res;
}

template<>
inline string checkAnswer(const vector<vector<string>> a, const vector<vector<string>> b)
{
	string check = (a == b) ? "" : "\t\t\t WRONG!";
	string res = "Result = \n";
	res += VectorVectorStringToString(a);
	res += "\n";
	res += VectorVectorStringToString(b);
	res += "\n";
	res += "\t\t\t" + check;
	return res;
}

#endif //COMMON_H


