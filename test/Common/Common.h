#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <iomanip>
#include <windows.h>
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
	std::string check = (a == b) ? "" : "\t\t\t WRONG!";
	return "Result = \n" + a + "\n\n" + b + "\n" + check;
}
//
//template<>
//inline string checkAnswer(const string a, const string b)
//{
//	string check = (a == b) ? "" : "\t\t\t WRONG!";
//	return "Result = \n" + a + "\n\n" + b + "\n" + check;
//}
//
//template<>
//inline string checkAnswer(TreeNode* a, TreeNode* b)
//{
//	string stra = TreeNodeToString(a);
//	string strb = TreeNodeToString(b);
//	return checkAnswer(stra, strb);
//}
//
//template<>
//inline string checkAnswer(vector<TreeNode*> a, vector<TreeNode*> b)
//{
//	string stra = "";
//	for (const auto t : a)
//	{
//		stra += "\n";
//		stra += TreeNodeToString(t);
//	}
//	stra += "\n";
//	string strb = "";
//	for (const auto t : b)
//	{
//		strb += "\n";
//		strb += TreeNodeToString(t);
//	}
//	strb += "\n";
//	return checkAnswer(stra, strb);
//}
//
//template<>
//inline string checkAnswer(ListNode* a, ListNode* b)
//{
//	string stra = ListNodeToString(a);
//	string strb = ListNodeToString(b);
//	return checkAnswer(stra, strb);
//}
//
//template<>
//inline string checkAnswer(bool a, bool b)
//{
//	string res;
//	res += "Result = ";
//	res += a ? "true" : "false";
//	res += "\t <== ";
//	res += b ? "true" : "false";
//	res += (a == b) ? "" : "\t\t\t WRONG!";
//	return res;
//}
//
//template<>
//inline string checkAnswer(const vector<int> a, const vector<int> b)
//{
//	string check = (a == b) ? "" : "\t\t\t WRONG!";
//	return "Result = \n" + vectorTToString(a) + "\n" + vectorTToString(b) + "\n" + check;
//}
//
//template<>
//inline string checkAnswer(const vector<vector<int>> a, const vector<vector<int>> b)
//{
//	string check = (a == b) ? "" : "\t\t\t WRONG!";
//	return "Result = \n" + vectorTToString(a) + "\n" + vectorTToString(b) + "\n" + check;
//}
//
//template<>
//inline string checkAnswer(const vector<char> a, const vector<char> b)
//{
//	string check = (a == b) ? "" : "\t\t\t WRONG!";
//	return "Result = \n" + vectorTToString(a) + "\n" + vectorTToString(b) + "\n" + check;
//}
//
//template<>
//inline string checkAnswer(const vector<vector<char>> a, const vector<vector<char>> b)
//{
//	string check = (a == b) ? "" : "\t\t\t WRONG!";
//	return "Result = \n" + vectorTToString(a) + "\n" + vectorTToString(b) + "\n" + check;
//}
//
//template<>
//inline string checkAnswer(const vector<string> a, const vector<string> b)
//{
//	string check = (a == b) ? "" : "\t\t\t WRONG!";
//	string res = "Result = \n";
//	res += vectorTToString(a);
//	res += "\n";
//	res += vectorTToString(b);
//	res += "\n";
//	res += "\t\t\t" + check;
//	return res;
//}
//
//template<>
//inline string checkAnswer(const vector<vector<string>> a, const vector<vector<string>> b)
//{
//	string check = (a == b) ? "" : "\t\t\t WRONG!";
//	string res = "Result = \n";
//	res += vectorTToString(a);
//	res += "\n";
//	res += vectorTToString(b);
//	res += "\n";
//	res += "\t\t\t" + check;
//	return res;
//}

#endif //COMMON_H


