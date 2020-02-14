#pragma once

#include <iostream>
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
// helper
//////////////////////////////////////////////////////////////////////////
void trimLeftTrailingSpaces(std::string &input);
void trimRightTrailingSpaces(std::string &input);
std::vector<std::size_t> stringGetSplitPos(const std::string& input, char begin = '[', char end = ']', char pattern = ',');
std::vector<std::string> split(std::string str, std::string pattern);


//////////////////////////////////////////////////////////////////////////
template<typename T>
std::vector<T> stringToVectorT(std::string input, char begin = '[', char end = ']', char pattern = ',');
template<typename T>
std::string vectorTToString(std::vector<T> input, char begin = '[', char end = ']', char pattern = ',');


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
// convert	std::string ==> xxx
//////////////////////////////////////////////////////////////////////////

// std::string to char
template<>
inline char convert(const std::string& input)
{
	if (input.empty()) return {};
	std::string output = input;
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

// std::string to std::string
template<>
inline std::string convert(const std::string& input)
{
	if (input.empty()) return input;
	std::string output = input;
	// Sample:
	// "ABC" ==> ABC
	if (output.size() != 1 && output[0] == '\"' && output.back() == '\"')
	{
		output = output.substr(1, output.size() - 2);
	}
	return output;
}

// std::string to bool
template<>
inline bool convert(const std::string& input)
{
	return (input == "true" || input == "True" || input == "TRUE");
}

// std::string to TreeNode*
template<>
inline TreeNode* convert(const std::string& input)
{
	return StringToTreeNode(input);
}

// std::string to ListNode*
template<>
inline ListNode* convert(const std::string & input)
{
	return StringToListNode(input);
}

//////////////////////////////////////////////////////////////////////////
// convert	std::string ==> vector
//////////////////////////////////////////////////////////////////////////

// std::string to char
template<>
inline std::vector<char> convert(const std::string& input)
{
	return stringToVectorT<char>(input);
}

template<>
inline std::vector<std::vector<char>> convert(const std::string& input)
{
	return stringToVectorT<std::vector<char>>(input);
}

// std::string to std::string
template<>
inline std::vector<std::string> convert(const std::string& input)
{
	return stringToVectorT<std::string>(input);
}

template<>
inline std::vector<std::vector<std::string>> convert(const std::string& input)
{
	return stringToVectorT<std::vector<std::string>>(input);
}

// std::string to int
template<>
inline std::vector<int> convert(const std::string& input)
{
	return stringToVectorT<int>(input);
}

template<>
inline std::vector<std::vector<int>> convert(const std::string& input)
{
	return stringToVectorT<std::vector<int>>(input);
}

// std::string to TreeNode*
template<>
inline std::vector<TreeNode*> convert(const std::string& input)
{
	return stringToVectorT<TreeNode*>(input);
}

// std::string to ListNode*
template<>
inline std::vector<ListNode*> convert(const std::string& input)
{
	return stringToVectorT<ListNode*>(input);
}

//////////////////////////////////////////////////////////////////////////
// convert    xxx ==> std::string 
//////////////////////////////////////////////////////////////////////////

// bool to std::string 
template<>
inline std::string convert(const bool& input)
{
	return input ? "true" : "false";
}

//////////////////////////////////////////////////////////////////////////
// convert	vector ==> std::string 
//////////////////////////////////////////////////////////////////////////

// char to std::string
template<>
inline std::string convert(const std::vector<char>& input)
{
	return vectorTToString(input);
}

// std::string to std::string
template<>
inline std::string convert(const std::vector<std::string>& input)
{
	return vectorTToString(input);
}

template<>
inline std::string convert(const std::vector< std::vector<std::string>>& input)
{
	return vectorTToString(input);
}

// int To std::string
template<>
inline std::string convert(const std::vector<int>& input)
{
	return vectorTToString(input);
}

template<>
inline std::string convert(const std::vector<std::vector<int>>& input)
{
	return vectorTToString(input);
}



//////////////////////////////////////////////////////////////////////////
// stringToVectorT
//////////////////////////////////////////////////////////////////////////
template<typename T>
std::vector<T> stringToVectorT(std::string input, char begin/* = '['*/, char end/* = ']'*/, char pattern/* = ','*/)
{
	std::vector<T> output;

	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	std::vector<std::size_t> pos = stringGetSplitPos(input, begin, end, pattern);
	if (!pos.empty()) return {};

	input = input.substr(1, input.size() - 2);
	if (input.empty()) return {};
	input += pattern;
	pos = stringGetSplitPos(input, begin, end, pattern);
	if (pos.empty()) return {};

	std::size_t cur = 0;
	for (auto& i : pos)
	{
		output.push_back(convert<T>(input.substr(cur, i - cur)));
		cur = i + 1;
	}

	return output;
}

template<typename T>
std::string vectorTToString(std::vector<T> input, char begin/* = '['*/, char end/* = ']'*/, char pattern/* = ','*/)
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

