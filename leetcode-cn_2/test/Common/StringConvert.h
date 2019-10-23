#pragma once

#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

#include "TreeNode.h"
#include "ListNode.h"

using namespace std;




//////////////////////////////////////////////////////////////////////////
//void trimLeftTrailingSpaces(std::string &input);
//void trimRightTrailingSpaces(std::string &input);

std::vector<std::string> split(std::string str, std::string pattern);

vector<char> StringToVectorChar(string str);
string VectorCharToString(const vector<char>& nums);
vector<vector<char>> StringToVectorVectorChar(string str);
string VectorVectorCharToString(const vector<vector<char>>& matrix);

vector<int> StringToVectorInt(string str);
string VectorIntToString(const vector<int>& nums);
vector<vector<int>> StringToVectorVectorInt(string str);
string VectorVectorIntToString(const vector<vector<int>>& matrix);

vector<string> StringToVectorString(string str);

//////////////////////////////////////////////////////////////////////////
//template<typename T>
//std::vector<T> stringToVectorT(std::string input, char begin = '[', char end = ']', char delim = ',')
//{
//	std::vector<T> output;
//	trimLeftTrailingSpaces(input);
//	trimRightTrailingSpaces(input);
//	if (input.front() != begin || input.back() != end) return {};
//
//	std::stringstream ss;
//	ss.str(input.substr(1, input.length() - 2));
//	std::string item;
//	while (getline(ss, item, delim))
//	{
//		output.push_back(convert<T>(item));
//	}
//	return output;
//}
//
//template<typename T>
//std::string vectorTToString(std::vector<T> input, char begin = '[', char end = ']', char delim = ',')
//{
//	std::string output;
//	output += begin;
//
//	for (auto i : input)
//	{
//		output += convert<std::string>(i);
//		output += delim;
//	}
//	if (output.back() == delim)
//	{
//		output.pop_back();
//	}
//	output += end;
//	return output;
//}

//////////////////////////////////////////////////////////////////////////
template<typename out_type, typename in_type>
out_type convert(const in_type & t)
{
	std::stringstream stream;
	stream << t;
	out_type result;
	stream >> result;
	return result;
}

template<>
inline bool convert(const std::string &s)
{
	return (s == "true" || s == "True" || s == "TRUE");
}

template<>
inline TreeNode* convert(const std::string &s)
{
	return StringToTreeNode(s);
}

template<>
inline ListNode* convert(const std::string &s)
{
	return StringToListNode(s);
}