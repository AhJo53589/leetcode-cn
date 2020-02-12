#pragma once

#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>

#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <string>

#include "ListNode.h"
#include "TreeNode.h"



//////////////////////////////////////////////////////////////////////////
void trimLeftTrailingSpaces(std::string &input);
void trimRightTrailingSpaces(std::string &input);

std::vector<std::size_t> stringGetSplitPos(const std::string& input, char begin = '[', char end = ']', char pattern = ',');

std::vector<std::string> split(std::string str, std::string pattern);

std::vector<char> StringToVectorChar(std::string str);
std::string VectorCharToString(const std::vector<char>& nums);
std::vector<std::vector<char>> StringToVectorVectorChar(std::string str);
std::string VectorVectorCharToString(const std::vector<std::vector<char>>& matrix);

std::vector<int> StringToVectorInt(std::string str);
std::string VectorIntToString(const std::vector<int>& nums);
std::vector<std::vector<int>> StringToVectorVectorInt(std::string str);
std::string VectorVectorIntToString(const std::vector<std::vector<int>>& matrix);

std::vector<std::string> StringToVectorString(std::string str);
std::string VectorStringToString(const std::vector<std::string>& strs, bool quotation = true);
std::vector<std::vector<std::string>> StringToVectorVectorString(std::string str);
std::string VectorVectorStringToString(const std::vector<std::vector<std::string>>& strs, bool quotation = true);

std::vector<TreeNode*> StringToVectorTreeNode(std::string str);
std::vector<ListNode*> StringToVectorListNode(std::string str);

// example
// {"$id":"1","left":
// {"$id":"2","left":
// {"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":
// {"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":
// {"$id":"5","left":
// {"$id":"6","left":null,"next":null,"right":null,"val":6},"next":null,"right":
// {"$id":"7","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}
std::vector<std::map<std::string, std::string>> StringToVectorMapStringString(std::string input);
std::string VectorMapStringStringToString(std::vector<std::map<std::string, std::string>> input);


//////////////////////////////////////////////////////////////////////////
// convert
//////////////////////////////////////////////////////////////////////////
template<typename out_type, typename in_type>
out_type convert(const in_type& t)
{
	std::stringstream stream;
	stream << t;
	out_type result;
	stream >> result;
	return result;
}

//////////////////////////////////////////////////////////////////////////

// std::string to bool
template<>
inline bool convert(const std::string& s)
{
	return (s == "true" || s == "True" || s == "TRUE");
}

// std::string to TreeNode*
template<>
inline TreeNode* convert(const std::string& s)
{
	return StringToTreeNode(s);
}

template<> 
inline std::vector<TreeNode*> convert(const std::string& s)
{
	return StringToVectorTreeNode(s);
}

// std::string to ListNode*
template<>
inline ListNode* convert(const std::string &s)
{
	return StringToListNode(s);
}

template<>
inline std::vector<ListNode*> convert(const std::string& s)
{
	return StringToVectorListNode(s);
}

// std::string to int
template<>
inline std::vector<int> convert(const std::string& s)
{
	return StringToVectorInt(s);
}

template<>
inline std::vector<std::vector<int>> convert(const std::string& s)
{
	return StringToVectorVectorInt(s);
}

// std::string to char
template<>
inline char convert(const std::string& s)
{
	if (s.empty()) return {};
	std::string output = s;
	// Sample:
	// "A" ==> A
	if (output.size() != 1 && output[0] == '\"' && output.back() == '\"')
	{
		output = output.substr(1, output.size() - 2);
	}
	// Sample:
	// 'A' ==> A
	if (output.size() != 1 && output[0] == '\'' && output.back() == '\'')
	{
		output = output.substr(1, output.size() - 2);
	}
	if (output.empty()) return {};
	return output[0];
}

template<>
inline std::vector<char> convert(const std::string& s)
{
	return StringToVectorChar(s);
}

template<>
inline std::vector<std::vector<char>> convert(const std::string& s)
{
	return StringToVectorVectorChar(s);
}

// std::string to std::string
template<>
inline std::string convert(const std::string& s)
{
	if (s.empty()) return s;
	std::string output = s;
	// Sample:
	// "ABC" ==> ABC
	if (output.size() != 1 && output[0] == '\"' && output.back() == '\"')
	{
		output = output.substr(1, output.size() - 2);
	}
	return output;
}

template<>
inline std::vector<std::string> convert(const std::string& s)
{
	return StringToVectorString(s);
}

template<>
inline std::vector<std::vector<std::string>> convert(const std::string& s)
{
	return StringToVectorVectorString(s);
}

//////////////////////////////////////////////////////////////////////////

// int To std::string
template<>
inline std::string convert(const std::vector<int>& input)
{
	return VectorIntToString(input);
}

template<>
inline std::string convert(const std::vector<std::vector<int>>& input)
{
	return VectorVectorIntToString(input);
}

// char to std::string
template<>
inline std::string convert(const std::vector<char>& input)
{
	return VectorCharToString(input);
}

// std::string to std::string
template<>
inline std::string convert(const std::vector<std::string>& input)
{
	return VectorStringToString(input);
}

template<>
inline std::string convert(const std::vector< std::vector<std::string>>& input)
{
	return VectorVectorStringToString(input);
}



//////////////////////////////////////////////////////////////////////////
// stringToVectorT
//////////////////////////////////////////////////////////////////////////
template<typename T>
std::vector<T> stringToVectorT(std::string input, char begin = '[', char end = ']', char pattern = ',')
{
	std::vector<T> output;

	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	std::vector<std::size_t> pos = stringGetSplitPos(input, begin, end, pattern);
	if (!pos.empty()) return {};

	input = input.substr(1, input.size() - 2);
	input += pattern;
	pos = stringGetSplitPos(input, begin, end, pattern);

	size_t cur = 0;
	for (auto& i : pos)
	{
		output.push_back(convert<T>(input.substr(cur, i - cur)));
		cur = i + 1;
	}

	return output;
}

template<typename T>
std::string vectorTToString(std::vector<T> input, char begin = '[', char end = ']', char pattern = ',')
{
	std::string output;

	output += begin;
	for (auto i : input)
	{
		output += convert<std::string>(i);
		output += pattern;
	}
	if (output.back() == pattern)
	{
		output.pop_back();
	}
	output += end;

	return output;
}

