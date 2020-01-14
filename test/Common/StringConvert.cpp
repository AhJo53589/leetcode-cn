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
using namespace std;

void trimLeftTrailingSpaces(string &input) 
{
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) 
{
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
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

vector<char> StringToVectorChar(string str)
{
	vector<char> chars;
	if (str.size() < 3) return chars;
	str = str.substr(1, str.size() - 2);
	for (auto c : str)
	{
		if (c == ' ') continue;
		if (c == ',') continue;
		if (c == '\"') continue;
		if (c == '\'') continue;
		chars.push_back(c);
	}
	return chars;
}

std::string VectorCharToString(const vector<char>& nums)
{
	string str = "[";
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

vector<vector<char>> StringToVectorVectorChar(string str)
{
	vector<vector<char>> matrix;
	if (str.size() < 3) return {};
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
			matrix.push_back(StringToVectorChar(strSub));
			strSub.clear();
		}
	}

	return matrix;
}

std::string VectorVectorCharToString(const vector<vector<char>>& matrix)
{
	string str = "[";
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

vector<int> StringToVectorInt(string input)
{
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

string VectorIntToString(const vector<int>& nums)
{
	string str = "[";
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

string VectorVectorIntToString(const vector<vector<int>>& matrix)
{
	string str = "[";
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

string VectorStringToString(const vector<string>& strs)
{
	string str;
	str += "[";
	for (auto s : strs)
	{
		str += "\"";
		str += s;
		str += "\",";
	}
	if (str.back() == ',') str.pop_back();
	str += "]";
	return str;
}

vector<vector<string>> StringToVectorVectorString(string str)
{
	vector<vector<string>> vvs;
	if (str.size() < 3) return vvs;
	str = str.substr(1, str.size() - 2);
	
	vector<string> vs;
	size_t i = 0;
	for (size_t j = 0; j < str.size(); j++)
	{
		if (str[j] == ']')
		{
			vvs.push_back(StringToVectorString(str.substr(i, j - i + 1)));
			while (j + 1 != str.size() && str[j + 1] != '[') j++;
			i = j + 1;
		}
	}
	return vvs;
}

string VectorVectorStringToString(const vector<vector<string>>& strs)
{
	string str;
	str += "[";
	for (auto vs : strs)
	{
		str += VectorStringToString(vs);
		str += ",";
	}
	if (str.back() == ',') str.pop_back();
	str += "]";
	return str;
}

vector<TreeNode*> StringToVectorTreeNode(string str)
{
	vector<TreeNode*> vt;
	if (str.size() < 3) return vt;
	str = str.substr(1, str.size() - 2);

	size_t i = 0;
	for (size_t j = 0; j < str.size(); j++)
	{
		if (str[j] == ']')
		{
			vt.push_back(StringToTreeNode(str.substr(i, j - i + 1)));
			while (j + 1 != str.size() && str[j + 1] != '[') j++;
			i = j + 1;
		}
	}
	return vt;
}

vector<map<string, string>> StringToVectorMapStringString(string input)
{
	auto trimLR = [](string s, char c)
	{
		trimLeftTrailingSpaces(s);
		trimRightTrailingSpaces(s);
		if (s[s.size() - 1] == c) s.pop_back();
		if (s[0] == c) s.erase(s.begin());
		return s;
	};

	vector<map<string, string>> output;
	stack<map<string, string>> st;

	size_t i = 0;
	while (i < input.size())
	{
		if (input[i] == ' ') continue;
		if (input[i] == '{')
		{
			i++;
			st.push(map<string, string>());
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

		size_t pos = input.find(':', i);
		if (pos == input.npos) break;

		string key = trimLR(input.substr(i, pos - i), '\"');
		string value;
		i = pos + 1;

		if (input[i] == '{')
		{
			size_t pos1 = input.find(':', i) + 1;
			size_t pos2 = input.find(',', i);
			value = input.substr(pos1, pos2 - pos1);

			string tmp = trimLR(input.substr(i, pos1 - i), '\"');
			if (tmp == "$ref")
			{
				pos1 = input.find('}', i);
				i = pos1 + 1;
			}
		}
		else
		{
			size_t pos2 = input.find(',', i);
			size_t pos3 = input.find('}', i);
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

string VectorMapStringStringToString_Core(vector<map<string, string>>& input, map<string, string>& cur, map<string, bool>& visited)
{
	auto addLR = [](string s, char c)
	{
		string r;
		r += c;
		r += s;
		r += c;
		return r;
	};

	string output;
	output += "{";

	string id = cur["$id"];
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

string VectorMapStringStringToString(vector<map<string, string>> input)
{
	map<string, bool> visited;
	for (auto& in : input)
	{
		visited[in["$id"]] = false;
	}

	string output;
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
