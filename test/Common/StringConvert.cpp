// Common.cpp 
//

#include <iostream>
#include <sstream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

#include "StringConvert.h"

void trimLeftTrailingSpaces(std::string& input)
{
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
		}));
}

void trimRightTrailingSpaces(std::string& input)
{
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
		}).base(), input.end());
}

std::vector<std::size_t> stringGetSplitPos(const std::string& input, char begin, char end, char delim)
{
	std::vector<std::size_t> output;
	int st = 0;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == delim && st == 0)
		{
			output.push_back(i);
			continue;
		}
		st += (input[i] == begin);
		st -= (input[i] == end);
	}
	return output;
}

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

std::vector<char> StringToVectorChar(std::string input)
{
	//std::vector<char> output;
	//if (input.size() < 3) return output;
	//input = input.substr(1, input.size() - 2);
	//for (auto c : input)
	//{
	//	if (c == ' ') continue;
	//	if (c == ',') continue;
	//	if (c == '\"') continue;
	//	if (c == '\'') continue;
	//	output.push_back(c);
	//}
	//return output;

	input.erase(std::remove(input.begin(), input.end(), '\''), input.end());
	input.erase(std::remove(input.begin(), input.end(), '\"'), input.end());
	return stringToVectorT<char>(input);
}

std::string VectorCharToString(const std::vector<char>& nums)
{
	std::string str = "[";
	for (auto i : nums)
	{
		str += i;
		str += ",";
	}
	if (str.back() == ',')
	{
		str.pop_back();
	}
	str.push_back(']');
	return str;
}

std::vector<std::vector<char>> StringToVectorVectorChar(std::string input)
{
	//vector<vector<char>> output;
	//if (input.size() < 3) return {};
	//input = input.substr(1, input.size() - 2);

	//string strSub;
	//char last = ' ';
	//for (auto c : input)
	//{
	//	if (last == ']')
	//	{
	//		last = ' ';
	//		continue;
	//	}
	//	strSub += c;
	//	last = c;
	//	if (c == ']')
	//	{
	//		output.push_back(StringToVectorChar(strSub));
	//		strSub.clear();
	//	}
	//}

	//return output;

	return stringToVectorT<std::vector<char>>(input);
}

std::string VectorVectorCharToString(const std::vector<std::vector<char>>& matrix)
{
	std::string str = "[";
	for (auto n : matrix)
	{
		str += VectorCharToString(n);
		str += ",";
	}
	if (str.back() == ',')
	{
		str.pop_back();
	}
	str.push_back(']');
	return str;
}

std::vector<int> StringToVectorInt(std::string input)
{
	//std::vector<int> output;
	//trimLeftTrailingSpaces(input);
	//trimRightTrailingSpaces(input);
	//input = input.substr(1, input.length() - 2);
	//stringstream ss;
	//ss.str(input);
	//string item;
	//char delim = ',';
	//while (getline(ss, item, delim)) {
	//	output.push_back(stoi(item));
	//}
	//return output;
	return stringToVectorT<int>(input);
}

std::string VectorIntToString(const std::vector<int>& nums)
{
	std::string str = "[";
	for (auto i : nums)
	{
		str += to_string(i);
		str += ",";
	}
	if (str.back() == ',')
	{
		str.pop_back();
	}
	str.push_back(']');
	return str;
}

std::vector<std::vector<int>> StringToVectorVectorInt(std::string input)
{
	//vector<vector<int>> output;
	//if (input.size() < 3) return output;
	//input = input.substr(1, input.size() - 2);

	//string strSub;
	//char last = ' ';
	//for (auto c : input)
	//{
	//	if (last == ']')
	//	{
	//		last = ' ';
	//		continue;
	//	}
	//	strSub += c;
	//	last = c;
	//	if (c == ']')
	//	{
	//		output.push_back(StringToVectorInt(strSub));
	//		strSub.clear();
	//	}
	//}
	//return output;

	return stringToVectorT<std::vector<int>>(input);
}

std::string VectorVectorIntToString(const std::vector<std::vector<int>>& matrix)
{
	std::string str = "[";
	for (auto n : matrix)
	{
		str += VectorIntToString(n);
		str += ",";
	}
	if (str.back() == ',')
	{
		str.pop_back();
	}
	str.push_back(']');
	return str;
}

std::vector<std::string> StringToVectorString(std::string input)
{
	//vector<string> output;
	//if (input.size() < 3) return output;
	//input = input.substr(1, input.size() - 2);
	//vector<string> vStr = split(input, ",");
	//for (auto s : vStr)
	//{
	//	int i1 = s.find_first_of('"');
	//	int i2 = s.find_last_of('"');
	//	output.push_back(s.substr(i1 + 1, i2 - i1 - 1));
	//}
	//return output;

	//input.erase(std::remove(input.begin(), input.end(), '\''), input.end());
	//input.erase(std::remove(input.begin(), input.end(), '\"'), input.end());
	return stringToVectorT<std::string>(input);
}

std::string VectorStringToString(const std::vector<std::string>& strs, bool quotation)
{
	std::string str;
	str += "[";
	for (auto s : strs)
	{
		str += quotation ? "\"" : "";
		str += s;
		str += quotation ? "\"" : "";
		str += ",";
	}
	if (str.back() == ',') str.pop_back();
	str += "]";
	return str;
}

std::vector<std::vector<std::string>> StringToVectorVectorString(std::string input)
{
	//vector<vector<string>> output;
	//if (input.size() < 3) return output;
	//input = input.substr(1, input.size() - 2);
	//
	//vector<string> vs;
	//size_t i = 0;
	//for (size_t j = 0; j < input.size(); j++)
	//{
	//	if (input[j] == ']')
	//	{
	//		output.push_back(StringToVectorString(input.substr(i, j - i + 1)));
	//		while (j + 1 != input.size() && input[j + 1] != '[') j++;
	//		i = j + 1;
	//	}
	//}
	//return output;

	return stringToVectorT<std::vector<std::string>>(input);
}

std::string VectorVectorStringToString(const std::vector<std::vector<std::string>>& strs, bool quotation)
{
	std::string str;
	str += "[";
	for (auto vs : strs)
	{
		str += VectorStringToString(vs, quotation);
		str += ",";
	}
	if (str.back() == ',') str.pop_back();
	str += "]";
	return str;
}

std::vector<TreeNode*> StringToVectorTreeNode(std::string input)
{
	//vector<TreeNode*> output;
	//if (input.size() < 3) return output;
	//input = input.substr(1, input.size() - 2);

	//size_t i = 0;
	//for (size_t j = 0; j < input.size(); j++)
	//{
	//	if (input[j] == ']')
	//	{
	//		output.push_back(StringToTreeNode(input.substr(i, j - i + 1)));
	//		while (j + 1 != input.size() && input[j + 1] != '[') j++;
	//		i = j + 1;
	//	}
	//}
	//return output;

	return stringToVectorT<TreeNode*>(input);
}

std::vector<ListNode*> StringToVectorListNode(std::string input)
{
	return stringToVectorT<ListNode*>(input);
}

std::vector<std::map<std::string, std::string>> StringToVectorMapStringString(std::string input)
{
	auto trimLR = [](std::string s, char c)
	{
		trimLeftTrailingSpaces(s);
		trimRightTrailingSpaces(s);
		if (s[s.size() - 1] == c) s.pop_back();
		if (s[0] == c) s.erase(s.begin());
		return s;
	};

	std::vector<std::map<std::string, std::string>> output;
	std::stack<std::map<std::string, std::string>> st;

	std::size_t i = 0;
	while (i < input.size())
	{
		if (input[i] == ' ') continue;
		if (input[i] == '{')
		{
			i++;
			st.push(std::map<std::string, std::string>());
		}
		if (input[i] == '}')
		{
			i++;
			output.push_back(st.top());
			st.pop();
		}
		if (input[i] == ',')
		{
			i++;
		}

		std::size_t pos = input.find(':', i);
		if (pos == input.npos) break;

		std::string key = trimLR(input.substr(i, pos - i), '\"');
		std::string value;
		i = pos + 1;

		if (input[i] == '{')
		{
			std::size_t pos1 = input.find(':', i) + 1;
			std::size_t pos2 = input.find(',', i);
			value = input.substr(pos1, pos2 - pos1);

			std::string tmp = trimLR(input.substr(i, pos1 - i), '\"');
			if (tmp == "$ref")
			{
				pos1 = input.find('}', i);
				i = pos1 + 1;
			}
		}
		else
		{
			std::size_t pos2 = input.find(',', i);
			std::size_t pos3 = input.find('}', i);
			if (pos2 < pos3)
			{
				value = input.substr(i, pos2 - i);
				i = pos2 + 1;
			}
			else
			{
				value = input.substr(i, pos3 - i);
				i = pos3;
			}
		}

		auto& cur = st.top();
		cur.insert({key, value});
	}

	return output;
}

std::string VectorMapStringStringToString_Core(std::vector<std::map<std::string, std::string>>& input, std::map<std::string, std::string>& cur, std::map<std::string, bool>& visited)
{
	auto addLR = [](std::string s, char c)
	{
		std::string r;
		r += c;
		r += s;
		r += c;
		return r;
	};

	std::string output;
	output += "{";

	std::string id = cur["$id"];
	if (visited[id])
	{
		output += addLR("$ref", '\"') + ":" + id + "},";
		return output;
	}
	visited[id] = true;

	for (auto kv : cur)
	{
		if (kv.first != "$id" && visited.count(kv.second) != 0)
		{
			for (auto& um : input)
			{
				if (um["$id"] == kv.second)
				{
					output += addLR(kv.first, '\"') + ":";
					output += VectorMapStringStringToString_Core(input, um, visited);
					break;
				}
			}
		}
		else
		{
			output += addLR(kv.first, '\"') + ":" + kv.second + ",";
		}
	}
	if (!output.empty() && output.back() == ',') output.pop_back();

	output += "},";
	return output;
}

std::string VectorMapStringStringToString(std::vector<std::map<std::string, std::string>> input)
{
	std::map<std::string, bool> visited;
	for (auto& in : input)
	{
		visited[in["$id"]] = false;
	}

	std::string output;
	for (auto& um : input)
	{
		if (um["$id"] == "\"1\"")
		{
			output += VectorMapStringStringToString_Core(input, um, visited);
			break;
		}
	}

	if (!output.empty() && output.back() == ',') output.pop_back();
	return output;
}
