// Common.cpp 
//

//#include "pch.h"

#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

#include "Common.h"
using namespace std;


std::vector<std::string> split(std::string str, std::string pattern)
{
	std::string::size_type Postion;
	std::vector<std::string> result;
	str += pattern;	// 扩展字符串以方便操作
	size_t size = str.size();
	for (size_t i = 0; i < size; i++)
	{
		Postion = str.find(pattern, i);
		if (Postion < size)
		{
			std::string s = str.substr(i, Postion - i);
			result.push_back(s);
			i = Postion + pattern.size() - 1;
		}
	}
	return result;
}

vector<char> StringToVectorChar(string str)
{
	vector<char> chars;
	if (str.size() < 3) return chars;
	str = str.substr(1, str.size() - 2);
	vector<string> vStr = split(str, ",");
	for (auto s : vStr)
	{
		int i = 0;
		while (s[i] == ' ') i++;
		chars.push_back(s[i]);
	}
	return chars;
}

vector<string> StringToVectorString(string str)
{
	vector<string> strs;
	if (str.size() < 3) return strs;
	str = str.substr(1, str.size() - 2);
	vector<string> vStr = split(str, ",");
	for (auto s : vStr)
	{
		int i1 = s.find_first_of('"');
		int i2 = s.find_last_of('"');
		strs.push_back(s.substr(i1 + 1, i2 - i1 - 1));
	}
	return strs;
}

vector<int> StringToVectorInt(string str)
{
	vector<int> nums;
	if (str.size() < 3) return nums;
	str = str.substr(1, str.size() - 2);
	vector<string> vStr = split(str, ",");
	for (auto s : vStr)
	{
		nums.push_back(stoi(s));
	}
	return nums;
}

string VectorIntToString(vector<int>& nums)
{
	string str = "[";
	for (auto i : nums)
	{
		str += to_string(i);
		str += ",";
	}
	str[str.size() - 1] = ']';
	return str;
}

vector<vector<int>> StringToVectorVectorInt(string str)
{
	vector<vector<int>> matrix;
	if (str.size() < 3) return matrix;
	str = str.substr(1, str.size() - 2);

	string strSub;
	char last = ' ';
	for (auto c : str)
	{
		if (last == ']')
		{
			last = ' ';
			continue;
		}
		strSub += c;
		last = c;
		if (c == ']')
		{
			matrix.push_back(StringToVectorInt(strSub));
			strSub.clear();
		}
	}
	return matrix;
}

string VectorVectorIntToString(vector<vector<int>>& matrix)
{
	string str = "[";
	for (auto n : matrix)
	{
		str += VectorIntToString(n);
		str += ",";
	}
	str[str.size() - 1] = ']';
	return str;
}

void printVectorVectorInt(vector<vector<int>>& matrix)
{
	for (auto n : matrix)
	{
		for (auto i : n)
		{
			cout << i << ", ";
		}
		cout << endl;
	}
	cout << endl;
}

void printVectorInt(vector<int>& nums)
{
	for (auto i : nums)
	{
		cout << i << ", ";
	}
	cout << endl;
}
