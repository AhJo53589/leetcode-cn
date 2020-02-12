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

std::vector<std::size_t> stringGetSplitPos(const std::string& input, char begin, char end, char pattern)
{
	std::vector<std::size_t> output;
	int st = 0;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == pattern && st == 0)
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
